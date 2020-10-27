#ifndef _LIBS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct misDatos_t {
    char nombre[20];
    char apellido[20];
    char edad;
    char tel[20];
    char mail[40];
} misDatos_t;
 
typedef struct pila_t {
    misDatos_t dato;
    struct pila_t *siguiente;
} pila_t;

#endif