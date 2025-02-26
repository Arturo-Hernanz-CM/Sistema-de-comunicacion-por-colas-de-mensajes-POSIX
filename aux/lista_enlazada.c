#include "lista_enlazada.h"
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int init(Lista *lista){
    lista = NULL;
    return 0;
}

int set(Lista *lista, int key, char *value1, double *value2, struct Coord *value3){
    Nodo *nodo = (Nodo *) malloc(sizeof(Nodo));
    nodo->key = key;
    nodo->value1 = value1;
    nodo->value2 = value2;
    nodo->value3 = *value3;

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

int exists(Lista *lista, int key){
    if (lista == NULL){
        return -1;
    }
    else{
        Nodo *nodo_actual = lista->inicio;
        for(int indice = 0; indice < lista->size; indice++){
            if(nodo_actual->key == key){
                return indice;
            }
            else{
                nodo_actual = nodo_actual->siguiente;
            }
        }
        return -1;
    }
}

Nodo get(Lista *lista, int key){
    if (exists(lista, key) == -1){
        Nodo nodo;
        return nodo;
    }
    else{
        Nodo *nodo_actual = lista->inicio;
        for(int indice = 0; indice < lista->size; indice++){
            if(nodo_actual->key == key){
                return *nodo_actual;
            }
            else{
                nodo_actual = nodo_actual->siguiente;
            }
        }
        return *nodo_actual;
    }
}

int delete(Lista *lista, int key){
    if (exists(lista, key) == -1){
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

int destroy(Lista *lista){
    if (lista == NULL){
        return 0;
    }
    return 0;
}