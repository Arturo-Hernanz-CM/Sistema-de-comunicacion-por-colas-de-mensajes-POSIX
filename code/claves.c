#include "estructuras.h"
#include "claves.h"
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

// Variable global auxiliar
extern Lista *base_datos;

int destroy(void){
    if(base_datos != NULL){
        free(base_datos); 
        base_datos = NULL;
    }
    else{
        Lista *lista = NULL;
        lista = (Lista *) malloc(sizeof(Lista));    
        if (lista == NULL) {
            return -1;
        }
    }
    return 0;
}

int set_value(int key, char *value1, int N_value2, double *V_value2, struct Coord value3){
    if(N_value2 < 1 || N_value2 > 32){
        return -1;
    }

    Nodo *nodo = (Nodo *) malloc(sizeof(Nodo));
    if (nodo == NULL) {
        return -1;
    }
    nodo->key = key;
    nodo->value1 = value1;
    nodo->N_value2 = N_value2;
    nodo->value2 = V_value2;
    nodo->value3 = value3;

    if (base_datos == NULL){ // lista vacia
        nodo->siguiente = NULL;
        nodo->index = 0;

        base_datos = (Lista *) malloc(sizeof(Lista));
        if (base_datos == NULL) {
            return -1;
        }

        base_datos->inicio = nodo;
        base_datos->final = nodo;
        base_datos->size = 1;
        return 0;
    }
    else{
        nodo->siguiente = NULL;
        nodo->index = base_datos->size;
        base_datos->final->siguiente = nodo;
        base_datos->final = nodo;
        base_datos->size++;
        return 0;
    }
}

int get_value(int key, char *value1, int *N_value2, double *V_value2, struct Coord *value3){
    if (exist(key) == -1){
        return -1;
    }
    else{
        Nodo *nodo_actual = base_datos->inicio;
        for(int indice = 0; indice < base_datos->size; indice++){
            if(nodo_actual->key == key){
                strcpy(value1, nodo_actual->value1);
                *N_value2 = nodo_actual->N_value2;
                V_value2 = nodo_actual->value2;
                *value3 = nodo_actual->value3;
                return 0;
            }
            else{
                nodo_actual = nodo_actual->siguiente;
            }
        }
        return -1;
    }
}

int modify_value(int key, char *value1, int N_value2, double *V_value2, struct Coord value3){
    if (exist(key) == -1 || N_value2 < 1 || N_value2 > 32){
        return -1;
    }
    else{
        Nodo *nodo_actual = base_datos->inicio;
        for(int indice = 0; indice < base_datos->size; indice++){
            if(nodo_actual->key == key){
                nodo_actual = (Nodo*)malloc(strlen(value1)+1);
                if (nodo_actual == NULL) {
                    return -1;
                }
                else{
                    strcpy(nodo_actual->value1, value1);
                }
                nodo_actual->N_value2 = N_value2;
                nodo_actual->value2 = V_value2;
                nodo_actual->value3 = value3;
                return 0;
            }
            else{
                nodo_actual = nodo_actual->siguiente;
            }
        }
    }

    return 0;
}

int delete_key(int key){
    if (exist(key) == -1){
        return -1;
    }
    else{
        if(base_datos->size == 1){
            free(base_datos->inicio);
            base_datos->inicio = NULL;
            base_datos->final = NULL;
            base_datos->size = 0;
            return 0;
        }
        Nodo *nodo_actual = base_datos->inicio;
        Nodo *nodo_anterior = NULL;
        for(int indice = 0; indice < base_datos->size; indice++){
            if(nodo_actual->key == key){
                if(nodo_anterior == NULL){
                    base_datos->inicio = nodo_actual->siguiente;
                }
                else if(nodo_actual == base_datos->final){
                    base_datos->final = nodo_anterior;
                }
                else{
                    nodo_anterior->siguiente = nodo_actual->siguiente;
                }
                base_datos->size--;
                free(nodo_actual);
                return 0;
            }
            else{
                nodo_anterior = nodo_actual;
                nodo_actual = nodo_actual->siguiente;
            }
        }
    }
    return 0;
}

int exist(int key){
    if (base_datos == NULL){
        return -1;
    }
    else{
        Nodo *nodo_actual = base_datos->inicio;
        for(int indice = 0; indice < base_datos->size; indice++){
            if(nodo_actual->key == key){
                return 0;
            }
            else{
                nodo_actual = nodo_actual->siguiente;
            }
        }
        return -1;
    }
}