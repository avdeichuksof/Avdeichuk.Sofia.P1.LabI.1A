#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include "empresa.h"
#include "micro.h"
#include "tipo.h"
#include "validaciones.h"
#include "viaje.h"

#endif // INFORMES_H_INCLUDED

int submenuInformes();

int mostrarEmpresaElegida(eMicro micros[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamC);

int mostrarTipoElegido(eMicro micros[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamC);

int informarMicrosXEmpresa(eMicro micros[], int tam, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE, eChofer choferes[], int tamC);

int promedioVip(eMicro micros[], int tam, eTipo tipos[], int tamT, int idTipo, float* pPromedio);

int promedioVipEmpresa(eMicro micros[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT);

int empresaMayorCapacidad(eMicro micros[], int tam, eEmpresa empresas[], int tamE);
