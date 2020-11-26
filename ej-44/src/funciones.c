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

void cargaArchivo (pila_t *pila){
    FILE *fp;
    repuestos_t carga;
    fp = fopen("repuestos.dat", "ab+");
    if (fp == NULL){
        printf("\nNo se pudo abrir el el archivo, se va a crear");
        
        fp = fopen("repuestos.dat", "wb+");
        if (fp == NULL){
            printf("\nError al crear archivo");
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
    struct lista_t *cursor=NULL, *r=NULL, *aux=NULL; 

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
            //se genera la concatenación para conseguir un numero total que luego sera comparado al convertirlo en entero.
            char aux1[20] = "";
            char aux2[20] = "";
            strcat(aux1,aux->dato.fecha);
            strcat(aux1,aux->dato.hora);
            strcat(aux2,(*in)->dato.fecha);
            strcat(aux2,(*in)->dato.hora);
            if(atoi(aux1) < atoi(aux2)){ 
                aux->prox=(*in); 
                (*in) = aux;
            }
            else
            {
                r = (*in); 
                cursor = (*in); 
                while ((atoi(aux1) >= atoi(aux2) && r->prox != NULL)){ 
                    cursor = r; 
                    r = r->prox; 
                }
                if(atoi(aux1) >= atoi(aux2)){ 
                    r->prox = aux;
                }
                else{  
                    aux->prox = r; 
                    cursor->prox = aux; 
                }
            }  
        }		    
        return;
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


//44
void listados(void){
    FILE *fp;
    repuestos_t leido;

    fp = fopen("repuestos.dat", "rb+");
    if (fp == NULL){
        printf("\nNo se pudo abrir el el archivo");
        return;
    }
    else{
        printf("\n\n *** Impresion del Archivo *** ");
        //Lectura anticipada
        fread(&leido, sizeof(repuestos_t),1,fp);
        while (!feof(fp)){ //pregunta al principio
            printf ("\nNumero de Orden: %ld \t Cliente: %s \t Falla: %s \t Modelo: %s \t Fecha y Hora: %s - %s",  leido.numeroDeOrden, leido.cliente, leido.descripciondeFalla, leido.modelo, leido.fecha, leido.hora);
            fread(&leido, sizeof(repuestos_t),1,fp);
        }
        fclose (fp);
    }
}


void extraccion(extraccionRepuestos_t dato,struct extraccionLista_t **in){
    struct extraccionLista_t *cursor=NULL, *r=NULL, *aux=NULL; 
    aux=(extraccionLista_t*) malloc(sizeof(extraccionLista_t));
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
            if(strcmp(aux->dato.repuesto.modelo,(*in)->dato.repuesto.modelo) < 0 ){ 
                aux->prox=(*in);
                (*in) = aux;
            }
            else
            {
                r = (*in); 
                cursor = (*in); 
                
                while ((strcmp(aux->dato.repuesto.modelo,r->dato.repuesto.modelo) > 0) && (r->prox != NULL)){
                    cursor = r; 
                    r = r->prox;             
                }

                if(strcmp(aux->dato.repuesto.modelo,r->dato.repuesto.modelo) > 0){ 
                    r->prox = aux; 
                }
                else if(strcmp(aux->dato.repuesto.modelo,r->dato.repuesto.modelo) == 0){
                    printf("\nIguales IF (parte central)\n");
                    r->dato.cantidad = r->dato.cantidad + aux->dato.cantidad;
                    free(aux);
                }
                else{ 
                    aux->prox = r; 
                    cursor->prox = aux; 
                }
            }  
        }		    
        return;
    }
}


void imprimeExtracLista(extraccionLista_t *var){  
	while(var){
		printf ("\nModelo: %s \t Cantidad: %d \t Numero de Orden: %ld \t Cliente: %s \t Falla: %s \t  Fecha y Hora: %s - %s",  var->dato.repuesto.modelo, var->dato.cantidad, var->dato.repuesto.numeroDeOrden, var->dato.repuesto.cliente, var->dato.repuesto.descripciondeFalla, var->dato.repuesto.fecha, var->dato.repuesto.hora);
		var = var->prox;
	}
}