#include <claves.h>

/**
 * @brief Esta llamada permite inicializar el servicio de elementos clave-valor1-valor2-valor3.
 * Mediante este servicio se destruyen todas las tuplas que estuvieran almacenadas previamente.
 * 
 * @return int La función devuelve 0 en caso de éxito y -1 en caso de error.
 * @retval 0 en caso de exito.
 * @retval -1 en caso de error.
 */
int destroy(void){
    return 0;
}

int set_value(int key, char *value1, int N_value2, double *V_value2, struct Coord value3){
    return 0;
}

int get_value(int key, char *value1, int *N_value2, double *V_value2, struct Coord *value3){
    return 0;
}

int modify_value(int key, char *value1, int N_value2, double *V_value2, struct Coord value3){
    return 0;
}

int delete_key(int key){
    return 0;
}

int exist(int key){
    return 0;
}