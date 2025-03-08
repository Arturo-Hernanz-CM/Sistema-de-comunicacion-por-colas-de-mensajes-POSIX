#include "estructuras.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comprobar_peticion(void *puntero){
    int op;
    Peticion *peticion = NULL;

    // Comprobación del tamaño del puntero
    if (puntero == NULL){
        perror("ERROR:\nFile: estructuras.c\nFunction: comprobar_peticion\nError: Peticion no válida - Puntero a NULL");
        return -1;
    }
    else if(sizeof(peticion) != sizeof(puntero)){
        perror("ERROR:\nFile: estructuras.c\nFunction: comprobar_peticion\nError: Peticion no válida - Tamaño de puntero incorrecto");
        return -1;
    }

    // Comprobación de la operación
    // Se asume que si el tamaño es el mismo, es una estructura igual
    peticion = (Peticion *) puntero;
    op = peticion->operacion;
    if (op == -1){
        perror("ERROR:\nFile: estructuras.c\nFunction: comprobar_peticion\nError: Peticion no válida - Operación incorrecta");
        return -1;
    }
    
    /* En caso de no ser una estructura de tipo Peticion y devolver cualquier cosa, 
    se comprueba que el valor recibido es un entero.
    Se asume el riesgo de generar segfault*/
    if(op >= 0 || op < 6){
        return op;
    }
    else{
        perror("ERROR:\nFile: estructuras.c\nFunction: comprobar_peticion\nError: Peticion no válida");
        return -1;
    }
}