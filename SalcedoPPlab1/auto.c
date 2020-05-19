#include "auto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marca.h"
#include "color.h"
#include "validaciones.h"


void inicializarA(eAuto vec[], int tamA)
{

    for(int i=0; i < tamA ; i++)
    {

        vec[i].isEmpty=1;




    }



}

int buscarLibreA(eAuto vec[],int tamA)
{

    int indice = -1;

    for(int i=0; i < tamA ; i++)
    {

        if(vec[i].isEmpty==1)
        {
            indice= i;
            break;

        }


    }

    return indice;
}








int altaAuto(int idx,eAuto vecA[],int tamA,eMarca vecB[],int tamM,eColor vecC[],int tamC)
{


    int todoOk=0;



    int indice = buscarLibreA(vecA,tamA);
    eAuto auxAuto;

    system("cls");
    printf("*****Alta Auto*****\n");

    if(indice== -1)
    {
        printf("Sistema Completo\n\n");
    }
    else
    {
        auxAuto.id= idx;
        mostrarMarcas(vecB,tamM);
        mostrarColores(vecC,tamC);

        if((utn_getEntero(&auxAuto.patente,3,"\n\nIngrese patente: ","\nError.Reingrese patente: ",1,999))==0 && (utn_getEntero(&auxAuto.idMarca,3,"Ingrese id de la marca: ","\nError.Reingrese id de la marca: ",1000,1004))==0 && (utn_getEntero(&auxAuto.idColor,3,"Ingrese id del color: ","\nError .reingrese id del color: ",5000,5004))==0 &&(utn_getEntero(&auxAuto.modelo,3,"Ingrese modelo(anio de fabricacion): ","\nError reingrese modelo: ",1950,2020))==0)
        {

            todoOk=1;
            auxAuto.isEmpty=0;

            vecA[indice]=auxAuto;
            printf("\n\nAlta Exitosa\n\n");
            system("pause");




        }
        else{

            printf("\nDatos erroneos,reingreselos\n\n");
        }



    }

    return todoOk;


}


void mostrarAuto(eAuto coche,eMarca vecM[],int tamM,eColor vecC[],int tamC)
{
    char descripcionMarca[20];
    char descripcionColor[20];

    cargarDescripcionMarca(descripcionMarca,coche.idMarca,vecM,tamM);
    cargarDescripcionColor(descripcionColor,coche.idColor,vecC,tamC);

    printf("%d  %d %10s%10s  %d\n\n",coche.id,coche.patente,descripcionMarca,descripcionColor,coche.modelo);



}


void mostrarAutos(eAuto vecA[],int tamA,eMarca vecM[],int tamM,eColor vecC[],int tamC)
{

    int flag=0;
    printf("*****Listado de Autos*****\n\n");
    printf("  id  Patente  Marca    Color  Modelo\n\n");

    for(int i=0; i < tamA; i++)
    {


        if(vecA[i].isEmpty==0)
        {
            mostrarAuto(vecA[i],vecM,tamM,vecC,tamC);
            flag=1;

        }

    }

    if(flag==0)
    {
        printf("\nNo hay autos que mostrar\n\n");
    }


}



int buscarAuto(int patente, eAuto vecA[],int tamA)
{

    int indice= -1;

    for(int i=0; i < tamA; i++)
    {
        if(vecA[i].patente == patente && vecA[i].isEmpty==0)
        {
            indice=i;
            break;

        }

    }
    return indice;






}


void bajaAuto(eAuto vecA[], int tamA,eMarca vecM[], int tamM,eColor vecC[],int tamC)
{

    int indice;
    int patente;
    char confirma;

    system("cls");
    printf("*****Baja Auto*****\n\n");
    printf("Ingrese patente: ");
    scanf("%d",&patente);

    indice = buscarAuto(patente,vecA,tamA);

    if(indice== -1)
    {
        printf("No hay registro de un auto con la patente: %d\n",patente);

    }
    else
    {   printf("  id  Patente  Marca    Color  Modelo\n\n");
        mostrarAuto(vecA[indice],vecM,tamM,vecC,tamC);
        printf("\nConfirma baja?: ");
        fflush(stdin);
        scanf("%c",&confirma);
        if(confirma=='s')
        {
            vecA[indice].isEmpty=1;
            printf("Se ha realizado la baja exitosamente\n\n");

        }

        else
        {
            printf("Se ha cancelado la operacion\n\n");

        }


    }


}



void modificarAuto(eAuto vecA[],int tamA,eMarca vecM[], int tamM,eColor vecC[],int tamC)
{

    int indice;
    int patente;
    int nuevoColor;
    int nuevoModelo;
    int seguir='s';
    char confirma;


    do
    {

        switch(menuMod())
        {

        case 'a':
            printf("Ingrese patente: ");
            scanf("%d",&patente);


            indice = buscarAuto(patente,vecA,tamA);




            //MOSTRAR LOS COLORES CON UNA FUNCION.
            if(indice== -1)
            {

                printf("No hay registro de un auto con la patente: %d\n",patente);

            }

            else
            {    printf("  id  Patente  Marca    Color  Modelo\n\n");
                 mostrarAuto(vecA[indice],vecM,tamM,vecC,tamC);

                 mostrarColores(vecC,tamC);

                printf("Ingrese id del color: ");
                scanf("%d",&nuevoColor);
                vecA[indice].idColor=nuevoColor;
                printf("\nColor actualizado con exito\n\n");
                system("pause");
                break;
            }




        case 'b':
            printf("Ingrese patente: ");
            scanf("%d",&patente);

            indice = buscarAuto(patente,vecA,tamA);



            if(indice== -1){

        printf("No hay registro de un auto con la patente: %d\n",patente);
            }
            else{

                    printf("  id  Patente  Marca    Color  Modelo\n\n");
            mostrarAuto(vecA[indice],vecM,tamM,vecC,tamC);

                printf("Ingrese modelo: ");
                scanf("%d",&nuevoModelo);

                vecA[indice].modelo = nuevoModelo;
                printf("\nModelo actualizado con exito\n\n");
                system("pause");
                break;


            }

        case 'c':
            printf("Confirma salida?: ");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma=='s')
        {
            seguir='n';
        }


 break;




        }




    }
    while(seguir=='s');



}


void cargarInformacionAuto(char descripcion[] ,int id,eAuto vecA[],int tamA)
{

     int todoOk= 0;

    for(int i=0; i<tamA; i++)
    {
        if(vecA[i].id == id)
        {
            strncpy(descripcion,vecA[i].idMarca,20);
            todoOk= 1;
        }
    }
    return todoOk;
}


void ordenarAutos(eAuto vecA[],int tamA,eMarca vecM[],int tamM)
{

    eAuto auxAuto;

    char marca1[20];
    char marca2[20];

    for(int i=0; i < tamA-1;i++)
    {
        cargarDescripcionMarca(marca1,vecA[i].idMarca,vecM,tamM);

        for(int j=i+1; j < tamA;j++)
        {

            cargarDescripcionMarca(marca2,vecA[j].idMarca,vecM,tamM);

            if(strcmp(marca1,marca2)>0)
            {
                auxAuto=vecA[i];
                vecA[i]=vecA[j];
                vecA[j]=auxAuto;



            }
            else
            {
               if((strcmp(marca1,marca2)==0)&&(strcmp(vecA[i].patente,vecA[j].patente)>0))
               {


                auxAuto=vecA[i];
                vecA[i]=vecA[j];
                vecA[j]=auxAuto;



               }
            }

        }

    }


}


