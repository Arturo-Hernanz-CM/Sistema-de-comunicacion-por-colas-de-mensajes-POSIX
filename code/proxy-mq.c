#include "estructuras.h"
#include "proxy-mq.h"
#include <stdio.h> 
#include <mqueue.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int tratar_peticion(Peticion* peticion_entrada) {

    // Variables
    int funcion;
    char nombre_cola[256];
    Peticion peticion;
    int respuesta;

    // Comprobar la operación
    funcion = comprobar_peticion(peticion_entrada);
    if (funcion == -1){
        perror("ERROR:\nFile: proxy-mq.c\nFunction: tratar_peticion\nError: Peticion no válida");
        return -1;
    }

    // Copiar la peticion de entrada
    memcpy(&peticion, peticion_entrada, sizeof(Peticion));

    //debug
    printf("Peticion recibida: %d\n", peticion.operacion);

    // Colas
    mqd_t cola_cliente;
    mqd_t cola_servidor;
    struct mq_attr atributos_cola_c;
    
    // Cola del cliente
    atributos_cola_c.mq_flags = 0;         
    atributos_cola_c.mq_maxmsg = 10;
    atributos_cola_c.mq_msgsize = sizeof(respuesta);
    sprintf(nombre_cola,  "/Cliente-%d", getpid());

    cola_cliente = mq_open(nombre_cola, O_CREAT | O_RDONLY, 0666, &atributos_cola_c);
    if (cola_cliente == -1) {
        perror("ERROR:\nFile: proxy-mq.c\nFunction: tratar_peticion\nError: Error al abrir la cola del cliente");
        return -1;
    }

    // Cola del servidor
    cola_servidor = mq_open("/Servidor", O_WRONLY);
    if (cola_servidor == -1) {
        perror("ERROR:\nFile: proxy-mq.c\nFunction: tratar_peticion\nError: Error al abrir la cola del servidor");
        return -1;
    }

    // Escribir en la cola del servidor

    if (mq_send(cola_servidor, (char *)&peticion, sizeof(peticion), 0) == -1) {
        perror("ERROR:\nFile: proxy-mq.c\nFunction: tratar_peticion\nError: No se puede enviar la peticion");
        mq_close(cola_servidor);
        mq_unlink("/Servidor");
    }

    // Recibir respuesta en la cola del cliente
    if(mq_receive(cola_cliente, (char *)&respuesta, sizeof(respuesta), 0) == -1) {
        perror("ERROR:\nFile: proxy-mq.c\nFunction: tratar_peticion\nError: No se puede recibir la respuesta");
        mq_close(cola_cliente);
        mq_unlink(nombre_cola);
    }


	mq_close(cola_servidor);
	mq_close(cola_cliente);
    mq_unlink(nombre_cola);

    //debug
    printf("Resultado = %d\n", respuesta);

    return 0;
}