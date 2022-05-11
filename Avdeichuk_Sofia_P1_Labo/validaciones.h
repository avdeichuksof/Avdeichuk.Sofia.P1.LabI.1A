#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

#include "empresa.h"
#include "tipo.h"
#include "destino.h"
#include "micro.h"


#endif // VALIDACIONES_H_INCLUDED

int validarEmpresa(eEmpresa empresas[], int tam, int id);
int validarTipo(eTipo tipos[], int tam, int id);
int validarDestino(eDestino destinos[], int tam, int id);
int validarMicro(eMicro micros[], int tam, int id);
