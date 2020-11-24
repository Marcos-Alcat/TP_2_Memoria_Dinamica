/*
    EJERCICIO 43:

    El servicio técnico de CosmeFulanito recibe órdenes de trabajo diarias. 
    Las mismas son cargadas en un archivo secuencial por el personal 
    de recepción bajo la siguiente estructura de datos:

            typedef struct{
                long numeroDeOrden;
                char cliente[40];       
                char descripciondeFalla[200];        
                char modelo[65];
                char fecha[10];
                char hora[10];
            }repuestos_t;

    Se pide:

    Hacer una pila con las órdenes de trabajo de forma tal que la más 
    vieja sea la última en cargarse.

*/

#include "../libs/libs.h"

int main(void){
    lista_t *inicio=NULL;
    pila_t *ultimo=NULL;
    while(continuar()){
        lista(cargar(),&inicio);
    }  
    while(inicio){
        ultimo = pila(inicio->dato,&ultimo);
        inicio = inicio->prox;
    }
    cargaArchivo(ultimo);
    return 0;
}