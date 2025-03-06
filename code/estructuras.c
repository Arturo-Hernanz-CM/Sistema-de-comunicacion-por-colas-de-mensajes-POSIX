#include "estructuras.h"
#include <stdio.h>

int comprobar_peticion(void *puntero){
    int op;
    Peticion *peticion = NULL;

    // Comprobación del tamaño del puntero
    if (puntero == NULL){
        perror("ERROR:\nFile: estructuras.c\nFunction: comprobar_peticion\nError: Peticion no válida");
        return -1;
    }
    else if(sizeof(Peticion) != sizeof(puntero)){
        perror("ERROR:\nFile: estructuras.c\nFunction: comprobar_peticion\nError: Peticion no válida");
        return -1;
    }

    // Comprobación de la operación
    // Se asume que si el tamaño es el mismo, es una estructura
    peticion = (Peticion *) puntero;
    op = atoi(peticion->operacion);
    if (op == 0){
        if (strcmp(peticion->operacion, "0") != 0){
            perror("ERROR:\nFile: estructuras.c\nFunction: comprobar_peticion\nError: Peticion no válida");
            return -1;
        }
    }
    
    /* En caso de no ser una estructura de tipo Peticion y devolver cualquier cosa, 
    se comprueba que el valor recibido es un entero.
    Se asume el riesgo de generar segfault*/
    if(op > 0 || op < 5){
        return op;
    }
    else{
        perror("ERROR:\nFile: estructuras.c\nFunction: comprobar_peticion\nError: Peticion no válida");
        return -1;
    }
}