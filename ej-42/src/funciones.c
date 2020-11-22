#include "../libs/libs.h"


void cargaEnArchivo (cola_t** fin){
    FILE *fp;
    cola_t *aux = NULL;
    fp = fopen("fallados.dat", "wb+");
    if(fp==NULL){
        printf("\n***No se pudo abrir el archivo %s***", "fallados.dat");
    }
    else{
        while(*fin != NULL){
            fwrite(&(*fin)->datos, sizeof(repuestos_t),1, fp);          
            aux = (&fin);
            *fin = (*fin)->ant;
            free(aux);
        }
        fclose(fp);
    }
}


void encolar(repuestos_t dato,cola_t **inicio, cola_t **fin){
    if( (dato.partNumber == 1234) && (dato.serialNumber&(1 << 3))  && (dato.serialNumber&(1 << 5))){
        cola_t *aux;
        aux = (cola_t *)malloc(sizeof(cola_t));
        aux->datos = dato;
        aux->prox = NULL;
        if((*inicio) == NULL){
            aux->prox = (*inicio);
            (*inicio) = (*fin) = aux;
            (*inicio)->ant = NULL; 
        }
        else{
            (*fin)->prox = aux;
            aux->ant = (*fin);
            aux->prox = NULL;
            (*fin) = aux;
        } 
    }
    else{printf("\n Criterio no cumplido");}
}


void leerArchivo (cola_t **inicio, cola_t **fin){
    FILE *fp;
    repuestos_t datos;
	printf("\n\n---> Lectura del archivo ordenado <---\n\n");
	fp = fopen("repuestos.dat", "rb+");
	if (fp == NULL){
		printf ("Error en la apertura del archivo repuestos.dat, puede que no exista\n");
	}
	fseek(fp, (0L), SEEK_SET);
	fread(&datos,sizeof(repuestos_t),1,fp);
		while(!feof(fp)){
			printf("\nNumero de Parte: %ld\tNumero de Serie:%ld\tDescripcion:%s\t Ubicacion:%s",datos.partNumber,datos.serialNumber,datos.descripcion,datos.ubicacion);
			encolar(datos,&(*inicio), &(*fin));
            fread(&datos,sizeof(repuestos_t),1,fp);
		}
	fclose(fp);
}




