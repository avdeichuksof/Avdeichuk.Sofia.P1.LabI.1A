#ifndef VIAJE_H_INCLUDED
#define VIAJE_H_INCLUDED
#include "fecha.h"
#include "destino.h"
#include "micro.h"

typedef struct
{
    int id;
    int idMicro;
    int idDestino;
    int fecha;
    eFecha fechas;
    int isEmpty;
}eViaje;

#endif // VIAJE_H_INCLUDED

int menu();

int inicializarViajes(eViaje viajes[], int tam);

int buscarViajeLibre(eViaje viajes[], int tam, int* pIndex);

int altaViaje(eViaje viajes[], int tam, int* pId, eDestino destinos[], int tamD, eMicro micros[], int tamM, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamC);

int listarViajes(eViaje viajes[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eDestino destinos[], int tamD,  eMicro micros[], int tamM);

int mostrarViajes(eViaje viajes, eMicro micros[], int tamM, eDestino destinos[], int tamD);
