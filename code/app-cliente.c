#include "estructuras.h"
#include "proxy-mq.h"
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

Peticion peticion;

int main (int argc, char **argv)  {
  // Ejemplo 1
  char *v1 = "ejemplo de valor 1";
  struct Coord v3; 
  peticion.value1 = (char *) malloc(strlen(v1) + 1);

  int key = 5; 
  double v2[] = {2.3, 0.5, 23.45}; 
 
  v3.x = 10; 
  v3.y = 5; 

  memcpy(peticion.value1, v1, strlen(v1) + 1);
  peticion.key = key;
  peticion.N_value2 = 3;
  memcpy(&peticion.value2, v2, sizeof(double));
  peticion.value3 = v3;
  peticion.operacion = 1;
  
  int err = tratar_peticion(&peticion); 
  if (err == -1) { 
    printf("Error al insertar la tupla\n"); 
    return -1;
  } 
 
  free(peticion.value1);
  return 0; 
}