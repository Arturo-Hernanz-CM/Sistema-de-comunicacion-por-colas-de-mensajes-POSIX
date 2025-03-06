#include <stdio.h> 
#include <string.h>
 
// numero de argumentos: 2, 3, 7
int main (int argc, char **argv)  {
  // Comprobacion de argumentos
  if (argc != 2 && argc != 3 && argc != 7){
    perror("ERROR:\nFile: app-cliente.c\nFunction: main\nError: Número de argumentos incorrecto, debe ser 1, 2 o 6");
    return -1;
  }

  // Funciones
  if (argc == 2){   // destroy
    if (strcmp(argv[1], "destroy") != 0){
      perror("ERROR:\nFile: app-cliente.c\nFunction: main\nError: Argumento incorrecto");
      return -1;
    }
  }
  else if (argc == 3){    // delete_key o esist
    if (strcmp(argv[1], "delete_key") != 0 && strcmp(argv[1], "exist") != 0){
      perror("ERROR:\nFile: app-cliente.c\nFunction: main\nError: Argumento incorrecto");
      return -1;
    }
  }
  else if (argc == 7){
    if (strcmp(argv[1], "set_value") != 0 && strcmp(argv[1], "modify_value") != 0 && strcmp(argv[1], "get_value") != 0){
      perror("ERROR:\nFile: app-cliente.c\nFunction: main\nError: Argumento incorrecto");
      return -1;
    }
  }

  return 0; 
} 