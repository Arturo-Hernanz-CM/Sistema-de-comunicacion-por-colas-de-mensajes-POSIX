#include "estructuras.h"
#include "proxy-mq.h"
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

// Ejemplo 0 -> destroy
int main (int argc, char **argv){
   
  // Envio de peticion 
  int err = destroy(); 
  if (err == -1) { 
    perror("ERROR:\nFile: app-cliente0.c\nFunction: main\nError al insertar la tupla"); 
    return -1;
  } 
 
  return 0; 
}