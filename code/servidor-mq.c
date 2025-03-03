#include "claves.h"
#include "estructuras.h"
#include <stdio.h> 
#include <mqueue.h>
#include <pthread.h>

// Variables globales
Lista * base_datos = NULL;
mqd_t  cola_servidor;
pthread_mutex_t mutex_mensaje;
pthread_cond_t condicion_mensaje;
int mensaje_copiado = 0;


void *leer_cola(void *Peticion) {
    mqd_t cola_cliente;
    struct Peticion peticion_local;
    int respuesta;

    // Copiar la petición a local
    pthread_mutex_lock(&mutex_mensaje);
    peticion_local = *((struct Peticion *) Peticion);
    mensaje_copiado = 1;
    pthread_mutex_unlock(&mutex_mensaje);

    // Ejecutar la petición
    if (peticion_local.opcion == 0) {
        respuesta = destroy();
    }
    else if (peticion_local.opcion == 1) {
        respuesta = insertar(peticion_local.key, peticion_local.value1, peticion_local.N_value2, peticion_local.value2, peticion_local.value3);
    }
    else if (peticion_local.opcion == 2) {
        respuesta = modify_value(peticion_local.key, peticion_local.value1, peticion_local.N_value2, peticion_local.value2, peticion_local.value3);
    }
    else if (peticion_local.opcion == 3) {
        respuesta = delete_key(peticion_local.key);
    }
    else if (peticion_local.opcion == 4) {
        respuesta = exist(peticion_local.key);
    }
    else if (peticion_local.opcion == 5) {
        respuesta = get_value(peticion_local.key, peticion_local.value1, &peticion_local.N_value2, peticion_local.value2, &peticion_local.value3);
    }
    else {
        respuesta = -1;
    }

    // Enviar la respuesta
    cola_cliente = mq_open(peticion_local.cliente, O_WRONLY);
    if (cola_cliente == -1) {
        perror("No se puede abrir la cola del cliente");
		mq_close(q_servidor);
		mq_unlink("/Servidor");
    }
    else {
        if (mq_send(cola_cliente, &respuesta, sizeof(respuesta), 0) == -1) {
            perror("No se puede enviar la respuesta");
            mq_close(q_servidor);
            mq_unlink("/Servidor");
        }
    }
}

int main(void) {
    // Inicializar la lista de claves
    base_datos = (Lista *) malloc(sizeof(Lista));
    if (base_datos == NULL) {
        return -1;
    }
    base_datos->inicio = NULL;
    base_datos->final = NULL;
    base_datos->size = 0;

    // Inicializar estructuras
    struct Peticion peticion;
    struct mq_attr atributos_cola_s;

    // Inicializar hilos
    pthread_t thread;
    pthread_attr_t thread_att;
    pthread_attr_init(&thread_att);

    // Inicializar mutex
    pthread_mutex_init(&mutex_mensaje, NULL);
    pthread_cond_init(&condicion_mensaje, NULL);

    // Inicializar la cola del serviddor. 
    //El servidor solo lee peticiones aquí, las respuestas en cada cola de cada cliente.
    atributos_cola_s.mq_msgsize = sizeof((Peticion));
    if (mq_open("/Servidor", O_CREAT | O_RDONLY, 0777, &atributos_cola_s) == -1) {
        return -1;
    }

    // Escribir en la cola

	pthread_attr_setdetachstate(&thread_att, PTHREAD_CREATE_DETACHED);      // threads independientes
    while(1) {
        if (mq_receive(q_servidor, (char *) &peticion, sizeof(peticion), 0) < 0 ){
			perror("mq_recev");
			return -1;
		}

        if(pthread_create(&thread, &thread_att, (void *) &leer_cola, &peticion) == 0) {
            pthread_mutex_lock(&mutex_mensaje);
            while(mensaje_copiado == 0) {
                pthread_cond_wait(&condicion_mensaje, &mutex_mensaje);
            }
            mensaje_copiado = 0;
            pthread_mutex_unlock(&mutex_mensaje);
        }
    }

    // Se "cierra" la cola del servidor
    mq_close(cola_servidor);
    mq_unlink("/Servidor");
    return 0;
}