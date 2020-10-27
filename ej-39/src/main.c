/*
    EJERCICIO 39:
    Hacer un programa que tome los datos de medición de potencia, cargados por el usuario, 
    de un sistema de medición a distancia.

    Los datos que cargará el usuario tienen la siguiente estructura:

        char desc[60];
        unsigned char potencia;
        unsigned int estado;

    Donde estado es la multiplicación del valor ASCII de la primer letra de la descripción 
    por la potencia. Los datos cargados se deberán guardar en una lista ordenada, de 
    mayor a menor, del valor de potencia. Una vez finalizada la carga guardar los datos 
    en un archivo de organización directa llamado "potencia.dat" imprimiendo en pantalla 
    los datos.
*/

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



datos_t cargaDeDatos(){
    datos_t datos;
    printf("Ingrese Descripcion:");
    fflush(stdin);
    gets(datos.desc);
    fflush(stdin);
    printf("Ingrese valor de potencia:");
    scanf("%d", &datos.potencia);
    datos.estado = ((int)datos.desc[0])*datos.potencia;

    return datos;
}



lista_t* listar(lista_t** in,datos_t misDatos){

    struct lista_t *nuevo;
    struct lista_t *r;
    struct lista_t *ant;

    nuevo=(lista_t*)malloc(sizeof(struct lista_t));
    nuevo->dato = misDatos;
    nuevo->prox=NULL;

    if((*in) == NULL){
        (*in) = nuevo;
    }
    else{
        if(misDatos.potencia > (*in)->dato.potencia){ 
            nuevo->prox=(*in);
            (*in) = nuevo;
        }
        else{
            r = (*in);
            ant = (*in);  
            while (misDatos.potencia <= r->dato.potencia && r->prox != NULL){
                ant = r;
                r = r->prox; 
            }
            if(misDatos.potencia <= r->dato.potencia){ 
                r->prox = nuevo;
            }
            else{  
                nuevo->prox = r;
                ant->prox = nuevo;
            }
        }  
    }
    return (*in);
}



void cargaArchivo(lista_t **in){
    struct lista_t *r;
    struct lista_t *b;
    FILE *fp;
    carga_t input;
    unsigned int i=0;
    fp = fopen ("potencia.dat", "wb+"); 
    if (fp == NULL) 
    { 
        fprintf(stderr, "\nError al abrir archivo\n"); 
        exit (1);
    }
    r = (*in);
	while(r){
		fseek(fp,(-1L)*(long)sizeof(struct lista_t),SEEK_END);
		fread(&input,sizeof(struct lista_t),1,fp);
		fseek(fp,0L,SEEK_END); 
        input.leidos = r->dato;
        input.id = i++;
        input.estado = 'A';
		fwrite(&input,sizeof(carga_t),1,fp);
		b = r;
		r = r->prox;
		free(b);
	}
	fclose(fp);
}



void leerarchivo(void){
    carga_t datosleidos;
    FILE *fp;
	printf("\n\nAbro archivo <---\n\n");
	fp = fopen("potencia.dat", "rb+");
	if (fp == NULL){
		printf ("Error en la apertura");
	}
	fseek(fp, (0L)*(sizeof(carga_t)), SEEK_SET);
	fread(&datosleidos,sizeof(carga_t),1,fp);
		while(!feof(fp)){
			printf ("ID: %d\t Desc: %s\t Potencia: %d\t Estado: %d \t Baja/Alta: %c\n",  datosleidos.id, datosleidos.leidos.desc ,datosleidos.leidos.potencia, datosleidos.leidos.estado, datosleidos.estado);
			fread(&datosleidos,sizeof(carga_t),1,fp);
		}
	fclose(fp);
}



int main (void){
    struct lista_t *in=NULL;
    while(continuar())in = listar(&in,cargaDeDatos());
    cargaArchivo(&in);
    leerarchivo();
    return 0;
}



