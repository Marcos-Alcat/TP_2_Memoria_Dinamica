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

void imprimirLista (lista_t* inicio){
    printf("\n***Impresion de la lista***");
    while(inicio != NULL){
        printf("\nNumero de Parte: %ld\tNumero de Serie:%ld\tDescripcion:%s\t Ubicacion:%s",inicio->repuesto.partNumber,inicio->repuesto.serialNumber,inicio->repuesto.descripcion,inicio->repuesto.ubicacion);
        inicio = inicio->siguiente;
    }
}

repuestos_t cargarDatos (void){
    repuestos_t repuesto;
    long partNumber;
    long serialNumber;
    char descripcion[40];       
    char ubicacion[100];
    printf("\nIngrese Numero de serie:");
    scanf("%ld", &repuesto.serialNumber);
    printf("\nIngrese Ubicacion:");
    fflush(stdin);
    gets(repuesto.ubicacion);
    printf("\nIngrese Numero de parte:");
    scanf("%ld", &repuesto.partNumber);
    printf("\nIngrese Descripcion:");
    fflush(stdin);
    gets(repuesto.descripcion);
    return repuesto;
}

void cargaArchivo (lista_t** inicio){
    FILE *fp;
    lista_t *aux = NULL;
    fp = fopen("repuestos.dat", "wb+");
    if(fp==NULL){printf("\nNo se pudo abrir el archivo repuestos.dat");}
    else{
        while (*inicio != NULL){
            fwrite(&(*inicio)->repuesto, sizeof(repuestos_t),1, fp);
            aux = (&inicio);
            *inicio = (*inicio)->siguiente;
            free(aux);
        }
        fclose(fp);
    }
}

lista_t* listar(void){
    struct lista_t *r=NULL, *pre=NULL, *inicio=NULL, *aux=NULL, registro; 
    repuestos_t repuesto;
 
        while(continuar()){ 
            repuesto = cargarDatos();
            aux=(lista_t*) malloc(sizeof(lista_t));
            aux->repuesto = repuesto;
            aux->siguiente=NULL;

            if(inicio == NULL){
                inicio = aux;
            }
            else{
                if(0 > strcmp(aux->repuesto.descripcion, inicio->repuesto.descripcion)){ 
                    aux->siguiente=inicio; 
                    inicio = aux;
                }
                else
                {
                    r = inicio; 
                    pre = inicio;
                    
                    while (0 <= strcmp(aux->repuesto.descripcion, r->repuesto.descripcion) && r->siguiente != NULL){ 
                        pre = r; 
                        r = r->siguiente; 
                    }
                    if(0 <= strcmp(aux->repuesto.descripcion, r->repuesto.descripcion)){
                        r->siguiente = aux;
                    }
                    else{  
                        aux->siguiente = r; 
                        pre->siguiente = aux; 
                    }
                }  
            }
        imprimirLista(inicio); 		
        }

    return inicio;
}





