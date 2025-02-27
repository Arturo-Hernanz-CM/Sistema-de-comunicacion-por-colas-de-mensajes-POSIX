#include "claves.h"
#include "estructuras.h"
#include <stdio.h> 
#include <mqueue.h>
#include <pthread.h>

// Variables globales
Lista * base_datos = NULL;
mqd_t  cola_servidor;

int main(void) {
    // Inicializar la lista de claves
    base_datos = (Lista *) malloc(sizeof(Lista));
    if (base_datos == NULL) {
        return -1;
    }
    base_datos->inicio = NULL;
    base_datos->final = NULL;
    base_datos->size = 0;

    // Inicializar la cola del serviddor. 
    //El servidor solo lee peticiones aquí, las respuestas en cada cola de cada cliente.
    struct mq_attr atributos_cola_s;
    atributos_cola_s.mq_msgsize = sizeof((Peticion));
    if (mq_open("/Servidor", O_CREAT | O_RDONLY, 0777, &atributos_cola_s) == -1) {
        return -1;
    }

    // Escribir en la cola

    // Se "cierra" la cola del servidor
    mq_close(cola_servidor);
    mq_unlink("/Servidor");
    return 0;
}