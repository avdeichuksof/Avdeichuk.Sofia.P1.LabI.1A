#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "viaje.h"
#include "fecha.h"
#include "empresa.h"
#include "tipo.h"
#include "micro.h"
#include "destino.h"

#define TAME 4
#define TAMT 4
#define TAMD 4
#define TAMM 10
#define TAMV 10

int main()
{
    char salir='n';
    int flagMicros=0;
    int proximoIdEmpresa=1000;
    int proximoIdTipo=5000;
    int proximoIdDestino=20000;
    int proximoIdViaje=3000;
    int proximoIdMicros=4000;

    eMicro micros[TAMM];
    eViaje viajes[TAMV];
    eEmpresa empresas[TAME]={
        {1000, "Plusmar"},
        {1001, "Flecha Bus"},
        {1002, "Tas"},
        {1003, "El Rapido"}
    };
    eTipo tipos[TAMT]={
        {5000, "Comun"},
        {5001, "Coche Cama"},
        {5002, "Doble"},
        {5003, "Vip"}
    };
    eDestino destinos[TAMD]={
        {20000, "Calafate", 22250},
        {20001, "Bariloche", 103000},
        {20002, "Iguazu", 84400},
        {20003, "Mendoza", 95600}
    };

    inicializarMicros(micros, TAMM);
    inicializarViajes(viajes, TAMV);

    do{
        switch(menu())
        {
            case 1:
                altaMicro(micros, TAMM, &proximoIdMicros, empresas, TAME, tipos, TAMT);
                flagMicros=1;
                break;
            case 2:
                if(flagMicros==1)
                {
                    modificarMicro(micros, TAMM, tipos, TAMT, empresas, TAME);
                }
                else
                {
                    printf("Primero se debe ingresar un micro\n");
                }
                break;
            case 3:
                if(flagMicros==1)
                {
                    bajaMicro(micros, TAMM, empresas, TAME, tipos, TAMT);
                }
                else
                {
                    printf("Primero se debe ingresar un micro\n");
                }
                break;
            case 4:
                if(flagMicros==1)
                {
                    listarMicros(micros, TAMM, empresas, TAME, tipos, TAMT);
                }
                else
                {
                    printf("Primero se debe ingresar un micro\n");
                }
                break;
            case 5:
                if(flagMicros==1)
                {
                    listarEmpresas(empresas, TAME);
                }
                else
                {
                    printf("Primero se debe ingresar un micro\n");
                }
                break;
            case 6:
                if(flagMicros==1)
                {
                    listarTipos(tipos, TAMT);
                }
                else
                {
                    printf("Primero se debe ingresar un micro\n");
                }
                break;
            case 7:
                if(flagMicros==1)
                {
                    listarDestinos(destinos, TAMD);
                }
                else
                {
                    printf("Primero se debe ingresar un micro\n");
                }
                break;
            case 8:
                if(flagMicros==1)
                {
                    altaViaje(viajes, TAMV, &proximoIdViaje, destinos, TAMD, micros, TAMM, empresas, TAME, tipos, TAMT);
                }
                else
                {
                    printf("Primero se debe ingresar un micro\n");
                }
                break;
            case 9:
                if(flagMicros==1)
                {
                   listarViajes(viajes, TAMV, empresas, TAME, tipos, TAMT, destinos, TAMD, micros, TAMM);
                }
                else
                {
                    printf("Primero se debe ingresar un micro\n");
                }
                break;
            case 10:
                salir='s';
                break;
        }
        system("pause");
    }while(salir!='s');


    return 0;
}
