#ifndef LIBS_H
#define LIBS_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct d{                                                                                            
    long clave; //Clave o Id del registro
    char d[30]; // Descripcion                                                                                          
    unsigned char tipo; //Tipo de datos como entero sin signo                                                                                                                                            
    char b; //'A':Alta 'B':Baja                                                                                                                                                                          
};

typedef struct{
	long clave;
	int posicion;
}nodo_t;

typedef struct pila_t {
    nodo_t dato;
    struct pila_t *prox;
} pila_t;


#endif /* LIBS_h */