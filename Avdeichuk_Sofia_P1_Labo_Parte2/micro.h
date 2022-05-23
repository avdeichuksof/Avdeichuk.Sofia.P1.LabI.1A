#ifndef MICRO_H_INCLUDED
#define MICRO_H_INCLUDED
#include "tipo.h"
#include "empresa.h"
#include "chofer.h"

typedef struct
{
    int id;
    int idEmpresa;
    int idTipo;
    int capacidad;
    int idChofer;
    int isEmpty;
}eMicro;

#endif // MICRO_H_INCLUDED

/** \brief menu que da opciones para amodificar la informacion de un micro
 *
 * \return int Devuelve la opcion elegida
 *
 */
int menuModificarMicro();

/** \brief Inicializa todas las posiciones del en 0
 *
 * \param micros[] eMicro Puntero al array micros
 * \param tam int Tamaño del array
* \return int Return 1 está todo vacio, 0 no hay mas espacio
 *
 */
int inicializarMicros(eMicro micros[], int tam);

/** \brief da de alta un micro nuevo
 *
 * \param micros[] eMicro Puntero al array de micros
 * \param tam int Tamaño del array
 * \param pId int* Puntero al Id de micros
 * \param empresas[] eEmpresa Puntero al array de empresaa
 * \param tamE int Tamaño del array
 * \param tipos[] eTipo Puntero al array de tipos
 * \param tamT int Tamaño del array
 * \param choferes[] eChofer  Puntero al array de choferes
 * \param tamC Tamaño del array
 * \return int Devuelve la informacion ingresada
 *
 */
int altaMicro(eMicro micros[], int tam, int* pId, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamC);

/** \brief busca un espacio libre para ingresar o no un nuevo micro
 *
 * \param micros[] eMicro Puntero al array de micros
 * \param tam int Tamaño del array
 * \param pIndex int* Puntero al indice
 * \return int Devuelve 1 si hay lugar y 0 si ya no hay lugar
 *
 */
int buscarMicroLibre(eMicro micros[], int tam, int* pIndex);

int buscarMicro(eMicro micros[], int tam,int id, int* pIndex);

int mostrarMicro(eMicro micros, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamC);

/** \brief Da la posibilidadad de modificar informacion sobre los micros ya ingresados
 *
 * \param mciros[] eMicro Puntero al array micros
 * \param tam int Tamaño del array
 * \param tipos[] eTipo Puntero al array tipos
 * \param tamT int Tamaño del array
 * \param empresas[] eEmpresa  Puntero al array empresas
 * \param tamE int Tamaño del array
 * \param choferes[] eChofer  Puntero al array de choferes
 * \param tamC Tamaño del array
 * \return int Devuelve la informacion modificada
 *
 */
int modificarMicro(eMicro micros[], int tam, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE, eChofer choferes[], int tamC);

/** \brief Da de baja un micro ya ingresado
 *
 * \param micros[] eMicro Puntero al array micros
 * \param tam int Tamaño del array
 * \param empresas[] eEmpresa Puntero al array empresas
 * \param tamE int Tamaño del array
 * \param tipos[] eTipo Puntero al array tipo
 * \param tamT int Tamaño del array
 * \return int elimina el micro
 *
 */
int bajaMicro(eMicro micros[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamC);

/** \brief realiza un listado de los micros
 *
 * \param micros[] eMicro Puntero al array micros
 * \param tam int Tamaño del array
 * \param empresas[] eEmpresa Puntero al array empresas
 * \param tamE int Tamaño del array
 * \param tipos[] eTipo Puntero al array tipos
 * \param tamT int Tamaño del array
 * \param choferes[] eChofer  Puntero al array de choferes
 * \param tamC Tamaño del array
 * \return int devuelve una lista de los micros ingresados
 *
 */
int listarMicros(eMicro micros[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamC);

int ordenarMicrosEmpresaYCapacidad(eMicro micros[], int tam);




