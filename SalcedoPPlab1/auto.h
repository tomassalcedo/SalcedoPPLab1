#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED
#include "marca.h"
#include "color.h"

typedef struct
{

    int id;
    int patente;
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;




}eAuto;



#endif // AUTO_H_INCLUDED



void inicializarA(eAuto vec[], int tamA);

int buscarLibreA(eAuto vec[],int tamA);

int altaAuto(int idx,eAuto vecA[],int tamA,eMarca vecB[],int tamM,eColor vecC[],int tamC);

void mostrarAuto(eAuto coche,eMarca vecM[],int tamM,eColor vecC[],int tamC);

void mostrarAutos(eAuto vecA[],int tamA,eMarca vecM[],int tamM,eColor vecC[],int tamC);

void bajaAuto(eAuto vecA[], int tamA,eMarca vecM[], int tamM,eColor vecC[],int tamC);

int buscarAuto(int patente, eAuto vecA[],int tamA);

void modificarAuto(eAuto vecA[],int tamA,eMarca vecM[], int tamM,eColor vecC[],int tamC);

void cargarInformacionAuto(char descripcio[] ,int id,eAuto vecA[],int tamA);
