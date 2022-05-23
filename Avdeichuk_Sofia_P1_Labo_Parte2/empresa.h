#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eEmpresa;

#endif // EMPRESA_H_INCLUDED

/** \brief realiza un listado de las empresas ingresadas
 *
 * \param empresas[] eEmpresa Array empresa
 * \param tam int Tamaño del array
 * \return int Devuelve el listado
 *
 */
int listarEmpresas(eEmpresa empresas[], int tam);

int buscarEmpresa(eEmpresa empresas[], int tam, int id, int* pIndice);

int cargarDescripcionEmpresa(eEmpresa empresas[], int tam, int id, char descripcion[]);
