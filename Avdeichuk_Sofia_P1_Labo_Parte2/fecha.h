#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

#endif // FECHA_H_INCLUDED

/** \brief valida la fecha ingresada
 *
 * \param unaFecha eFecha recibe la fecha
 * \return int Return 0 la fecha es valida
 *
 */
int validarFecha(eFecha unaFecha);
