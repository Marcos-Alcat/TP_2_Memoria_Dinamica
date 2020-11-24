#include "../libs/libs.h"

int continuar(void){
   int opcion = 0;
   printf("\n Cuntinuar: 1");
   printf("\n     Salir: 0");
   printf("\n    Opcion: ");
   fflush(stdin);
   scanf("%d",&opcion);
   fflush(stdin);
   if(opcion) return 1;
   else return 0;
}

repuestos_t cargar(void){
    repuestos_t cargado;
    printf("\nNumero de Orden:");
    scanf("%ld",&cargado.numeroDeOrden);
    fflush(stdin);
    printf("Cliente:");
    scanf("%s",&cargado.cliente);
    fflush(stdin);
    printf("Falla:");
    scanf("%s",&cargado.descripciondeFalla);
    fflush(stdin);
    printf("Modelo:");
    scanf("%s",&cargado.modelo);
    fflush(stdin);
    printf("Fecha:");
    scanf("%s",&cargado.fecha);
    fflush(stdin);
    printf("Hora:");
    scanf("%s",&cargado.hora);
    fflush(stdin);
    return cargado;
}

void lista(repuestos_t dato,struct lista_t **in){
    struct lista_t *pre=NULL, *r=NULL, *aux=NULL; 

    aux=(lista_t*) malloc(sizeof(lista_t));
    if(aux == NULL){
        printf("\n Error");
    }
    else{
        aux->dato=dato;
        aux->prox=NULL;

        if(*in == NULL){
            *in = aux;
        }
        else{
            char auxFyH[20] = "";
            char inFyH[20] = "";
            strcat(auxFyH,aux->dato.fecha);
            strcat(auxFyH,aux->dato.hora);
            strcat(inFyH,(*in)->dato.fecha);
            strcat(inFyH,(*in)->dato.hora);
            if(atoi(auxFyH) < atoi(inFyH)){ 
                aux->prox=(*in); 
                (*in) = aux;
            }
            else
            {
                r = (*in); 
                pre = (*in); 
                while ((atoi(auxFyH) >= atoi(inFyH) && r->prox != NULL)){ 
                    pre = r; 
                    r = r->prox; 
                }
                if(atoi(auxFyH) >= atoi(inFyH)){ 
                    r->prox = aux;
                }
                else{  
                    aux->prox = r; 
                    pre->prox = aux; 
                }
            }  
        }		    
        return;
    }
}

void cargaArchivo (pila_t *pila){
    FILE *fp;
    repuestos_t carga;
    fp = fopen("repuestos.dat", "ab+");
    if (fp == NULL){
        printf("\nNo hay archivo, se creara");
        
        fp = fopen("repuestos.dat", "wb+");
        if (fp == NULL){
            printf("\nError al crear");
            return;
        }  
    }
    else{
        while(pila){
            fwrite(&pila->dato,sizeof(repuestos_t),1,fp);
            pila = pila->siguiente;
        }
        fclose (fp);
    }
}

pila_t* pila(repuestos_t cargado,pila_t **ultimo){
    pila_t *aux = NULL;
    aux=(pila_t *) malloc(sizeof(pila_t));
        if(aux == NULL){
        printf("\n Error");
    }
    else{
    aux->dato = cargado;
    aux->siguiente = *ultimo;
    return aux;
    }
    return NULL;
}