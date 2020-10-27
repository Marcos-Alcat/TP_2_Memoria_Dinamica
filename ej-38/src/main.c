/*
EJERCICIO 38:
Hacer una cola con los valores muestreados de un cuarto de ciclo de una señal sinusoidal, en 8 bits, 
para luego recorrerla y recomponer la señal completa. 
Las muetras deberán ir de 127 a -127 utilizando el bit más significativo en 1 para los valores negativos y 
en 0 para los valores positivos. Imprimir en pantalla los valores.
*/

#include "../libs/libs.h"


void encolar(char dato,cola_t **primero, cola_t **ultimo){
    cola_t *aux;
    aux = (cola_t *)malloc(sizeof(cola_t));
    aux->datos = dato;
    aux->prox = NULL;
    
    
    if((*primero) == NULL){ //cola vacia
        aux->prox = (*primero);
        (*primero) = (*ultimo) = aux;
        (*primero)->ant = NULL; 
    }
   
    else{//agrego al final
        (*ultimo)->prox = aux;
        aux->ant = (*ultimo);
        aux->prox = NULL;
        (*ultimo) = aux;
    }
}


void impresionDeCiclo( cola_t *primero, cola_t *ultimo, int cuarto){
    
    if(cuarto == 1){
        printf("\n\t---Primer Cuarto");
        while(primero != NULL){
            printf("\n%d", primero->datos);
            primero = primero->prox;
        }
    }
    else if(cuarto == 2){
        printf("\n\t---Segundo Cuarto");
        while(ultimo != NULL){
            printf("\n%d", ultimo->datos);
            ultimo = ultimo->ant;
        }
    } 
    else if(cuarto == 3){ 
        printf("\n\t---Tercer Cuarto");
        while(primero!= NULL){
            printf("\n%d", (primero->datos) | (1<<7));
            primero = primero->prox;
        }
    }    
    else if(cuarto == 4){ 
        printf("\n\t---Ultimo Cuarto");
        while(ultimo != NULL){
            printf("\n%d", (ultimo->datos) | (1<<7));
            ultimo = ultimo->ant;
        }    
    }

}



int main(void){

    cola_t *primero=NULL, *ultimo=NULL;

    int x = 0;

    for(x=0; x<91; x+=5) encolar((char)((double)127.0*sin((double)x*3.14/180)), &primero, &ultimo); //cargo muestras.

    for(x=0; x < 5; x++) impresionDeCiclo(primero,ultimo,x); //imprimo la señal en cuartos para reconstruirla.

    return 0;
}
