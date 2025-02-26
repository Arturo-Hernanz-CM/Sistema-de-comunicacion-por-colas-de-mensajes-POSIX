#include "estructuras.h"
#include "claves.h"
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

Lista *lista = NULL;

int destroy(void){
    if(lista != NULL){
        free(lista); 
        lista = NULL;
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

    if (lista == NULL){ // lista vacia
        nodo->siguiente = NULL;
        nodo->index = 0;
        lista->inicio = nodo;
        lista->final = nodo;
        lista->size = 1;
        return 0;
    }
    else{
        nodo->siguiente = NULL;
        nodo->index = lista->size;
        lista->final->siguiente = nodo;
        lista->final = nodo;
        lista->size = lista->size++;
        return 0;
    }
}

int get_value(int key, char *value1, int *N_value2, double *V_value2, struct Coord *value3){
    if (exist(key) == -1){
        return -1;
    }
    else{
        Nodo *nodo_actual = lista->inicio;
        for(int indice = 0; indice < lista->size; indice++){
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
    }
}

int modify_value(int key, char *value1, int N_value2, double *V_value2, struct Coord value3){
    if (exist(key) == -1 || N_value2 < 1 || N_value2 > 32){
        return -1;
    }
    else{
        Nodo *nodo_actual = lista->inicio;
        for(int indice = 0; indice < lista->size; indice++){
            if(nodo_actual->key == key){
                nodo_actual->value1 = value1; // no uso strcpy porque directamente cambio el puntero
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
        if(lista->size == 1){
            free(lista->inicio);
            lista->inicio = NULL;
            lista->final = NULL;
            lista->size = 0;
            return 0;
        }
        Nodo *nodo_actual = lista->inicio;
        Nodo *nodo_anterior = NULL;
        for(int indice = 0; indice < lista->size; indice++){
            if(nodo_actual->key == key){
                if(nodo_anterior == NULL){
                    lista->inicio = nodo_actual->siguiente;
                }
                else{
                    nodo_anterior->siguiente = nodo_actual->siguiente;
                }
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
    if (lista == NULL){
        return -1;
    }
    else{
        Nodo *nodo_actual = lista->inicio;
        for(int indice = 0; indice < lista->size; indice++){
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