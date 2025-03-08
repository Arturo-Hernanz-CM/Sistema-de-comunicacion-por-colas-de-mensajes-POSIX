#include "estructuras.h"
#include "proxy-mq.h"
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

Peticion peticion;

// Ejemplo 5 -> exist
int main (int argc, char **argv){
  // Valores a asignar a la peticion
  int key = 1;
  struct Coord value3 = {NULL, NULL};

  // Asignacion de valores a la estructura
  peticion.key = key;
  peticion.value1 = NULL;
  peticion.value2 = NULL;
  peticion.N_value2 = 0;
  peticion.value3 = value3;
  peticion.operacion = 5;   // exist
  
  // Envio de peticion
  int err = tratar_peticion(&peticion); 
  if (err == -1) { 
    printf("Error al insertar la tupla\n"); 
    return -1;
  } 
 
  free(peticion.value1);
  return 0; 
}