#include "estructuras.h"
#include <stdio.h> 
#include <mqueue.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    // Variables
    char nombre_cola[256];
    Peticion peticion;
    int respuesta;

    // Colas
    mqd_t cola_cliente;
    mqd_t cola_servidor;
    struct mq_attr atributos_cola_c;
    
    // Cola del cliente
    atributos_cola_c.mq_msgsize = sizeof(Peticion);
    sprintf(nombre_cola,  "/Cliente-%d", getpid());
    cola_cliente = mq_open(nombre_cola, O_CREAT | O_RDONLY, 0777, &atributos_cola_c);
    if (cola_cliente == -1) {
        perror("Error al abrir la cola del cliente\n");
        return -1;
    }

    // Cola del servidor
    atributos_cola_c.mq_msgsize = sizeof(Peticion);
    cola_servidor = mq_open("/Servidor", O_WRONLY);
    if (cola_servidor == -1) {
        perror("Error al abrir la cola del servidor\n");
        return -1;
    }

    // Escribir en la cola del servidor
    // Peticion de test
    int key = 1;
    char *value1 = "hola";  
    int N_value2 = 1;
    double *value2 = NULL;
    value2 = (double *)malloc(N_value2 * sizeof(double));
    value2[0] = 1.0;
    struct Coord value3 = {0, 0};
    int operacion = 1;

    strcpy(peticion.cola_cliente, nombre_cola);
    peticion.key = key;
    strcpy(peticion.value1, value1);
    peticion.value2 = value2;
    peticion.N_value2 = N_value2;
    peticion.value3 = value3;
    peticion.operacion = operacion;

    if (mq_send(cola_servidor, (char *)&peticion, sizeof(peticion), 0) == -1) {
        perror("No se puede enviar la peticion");
        mq_close(cola_servidor);
        mq_unlink("/Servidor");
    }

    // Recibir respuesta en la cola del cliente
    if(mq_receive(cola_cliente, (char *)&respuesta, sizeof(peticion), 0) == -1) {
        perror("No se puede recibir la respuesta");
        mq_close(cola_cliente);
        mq_unlink(nombre_cola);
    }

    printf("Resultado = %d\n", respuesta);

	mq_close(cola_servidor);
	mq_close(cola_cliente);
    mq_unlink(nombre_cola);
    return 0;
}