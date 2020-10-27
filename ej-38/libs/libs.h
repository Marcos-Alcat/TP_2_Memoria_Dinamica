#ifndef LIBS_H
#define LIBS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


typedef struct cola{
    char datos;
    struct cola *prox;
    struct cola *ant;
}cola_t;



#endif 