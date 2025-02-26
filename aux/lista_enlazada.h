#ifndef lista_enlazada_h
#define lista_enlazada_h

// Estructuras a usar
struct Coord {
    int x ;
    int y ;
 } ;

typedef struct Nodo{
    int key;
    int index;
    char *value1;  // le paso la dir. mem. de un vector para no definir el tamaño máximo
    double *value2;
    struct Coord value3; 

    struct Nodo *siguiente;
}Nodo;

typedef struct{
    Nodo *inicio;
    Nodo *final;
    int size;
}Lista;


// Funciones
int init(Lista *lista);
int set(Lista *lista, int key, char *value1, double *value2, struct Coord *value3);
int exists(Lista *lista, int key);  // -1 si no existe else index
Nodo get(Lista *lista, int key);
int delete(Lista *lista, int index);
int destroy(Lista *lista);

#endif