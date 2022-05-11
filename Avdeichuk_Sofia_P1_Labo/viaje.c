#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "viaje.h"
#include "destino.h"

int menu()
{
    int opcion;
    system("cls");
    printf("*** ABM Micros ***\n");
    printf("1- Alta Micro\n");
    printf("2- Modificar Micro\n");
    printf("3- Baja Micro\n");
    printf("4- Listar Micros\n");
    printf("5- Listar Empresas\n");
    printf("6- Listar Tipos\n");
    printf("7- Listar Destinos\n");
    printf("8- Alta viaje\n");
    printf("9- Listar viajes\n");
    printf("10- Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int inicializarViajes(eViaje viajes[], int tam)
{
    int todoOk = 0;
    if(viajes != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            viajes[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarViajeLibre(eViaje viajes[], int tam, int* pIndex)
{
    int todoOk = 0;
    if(viajes!= NULL && tam>0 && pIndex!=NULL)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( viajes[i].isEmpty )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int altaViaje(eViaje viajes[], int tam, int* pId, eDestino destinos[], int tamD, eMicro micros[], int tamM, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT)
{
    int todoOk = 0;
    int indice;
    char auxCad[100];
    eViaje nuevoViaje;
    eFecha fechas;

    if(viajes!=NULL && tam>0 && pId!=NULL)
    {
        if(buscarViajeLibre(viajes, tam, &indice))
        {
            if(indice == - 1)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {
                listarMicros(micros, tamM, empresas, tamE, tipos, tamT);
                printf("Ingrese micro con el que desea viajar: ");
                scanf("%d", &nuevoViaje.idMicro);
                while(!validarMicro(micros, tamM, nuevoViaje.idMicro))
                {
                    printf("Micro invalido. Ingrese micro: ");
                    scanf("%d", &nuevoViaje.idMicro);
                }

                listarDestinos(destinos, tamD);
                printf("Ingrese destino: ");
                scanf("%d", &nuevoViaje.idDestino);
                while(!validarDestino(destinos, tamD, nuevoViaje.idDestino))
                {
                    printf("Destino invalido. Ingrese destino: ");
                    scanf("%d", &nuevoViaje.idDestino);
                }

                printf("Ingrese Fecha de viaje dd/mm/aaaa: ");
                scanf("%d/%d/%d", &fechas.dia, &fechas.mes, &fechas.anio);
                nuevoViaje.fechas = fechas;

                nuevoViaje.isEmpty = 0;
                nuevoViaje.id = *pId;
                *pId = *pId + 1;
                viajes[indice] = nuevoViaje;
                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros\n");
        }
    }
    return todoOk;
}

int mostrarViajes(eViaje viajes, eMicro micros[], int tamM, eDestino destinos[], int tamD)
{
    int todoOk = 0;
    char descDestino[20];

    if(micros!= NULL && tamM> 0 && destinos!=NULL && tamD>0)
    {

        cargarDescripcionDestino(destinos, tamD, viajes.idDestino, descDestino);

        printf("  %4d    %d    %s    %02d/%02d/%d\n", viajes.id, viajes.idMicro, descDestino, viajes.fechas.dia, viajes.fechas.mes, viajes.fechas.anio);
        todoOk = 1;
    }
    return todoOk;
}

int listarViajes(eViaje viajes[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eDestino destinos[], int tamD, eMicro micros[], int tamM)
{
    int todoOk = 0;
    int flag=0;

    if(viajes!= NULL && tam>0)
    {
        system("cls");
        printf("        *** Lista de Viajes ***\n");
        printf("  Id     Micro     Destino    Fecha\n");
        printf("----------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
            if(!viajes[i].isEmpty)
            {
                mostrarViajes(viajes[i], micros, tamM, destinos, tamD);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("No hay viajes en el sistema");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}
