#include "estructuras.h"
#include "proxy-mq.h"
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

Peticion peticion;

// Ejemplo 1 -> set_value
int main (int argc, char **argv){
  // Valores a asignar a la peticion
  int key = 1; 
  char *v1 = "ejemplo de valor 1";
  double v2[] = {2.3, 0.5, 23.45}; 
  struct Coord v3;
  v3.x = 10; 
  v3.y = 5; 

  // Asignacion de valores a la estructura
  strcpy(peticion.value1, v1);
  printf("%s\n", peticion.value1);
  peticion.key = key;
  peticion.N_value2 = 3;
  memcpy(&peticion.value2, v2, sizeof(double));
  peticion.value3 = v3;
  peticion.operacion = 1;   // set_value
  
  // Envio de peticion
  int err = tratar_peticion(&peticion); 
  if (err == -1) { 
    printf("Error al insertar la tupla\n"); 
    return -1;
  } 
 
  return 0; 
}