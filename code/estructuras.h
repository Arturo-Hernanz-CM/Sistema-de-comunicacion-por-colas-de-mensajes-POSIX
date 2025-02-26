#ifndef estructuras_h
#define estructuras_h

// Estructuras a usar
struct Coord {
    int x ;
    int y ;
 } ;

typedef struct Nodo{
    int index;
    
    int key;
    char *value1;  // le paso la dir. mem. de un vector para no definir el tamaño máximo
    int N_value2;
    double *value2;
    struct Coord value3; 

    struct Nodo *siguiente;
}Nodo;

typedef struct{
    Nodo *inicio;
    Nodo *final;
    int size;
}Lista;

#endif