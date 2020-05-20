#ifndef BIBLIOTECAEMPLEADO_H_INCLUDED
#define BIBLIOTECAEMPLEADO_H_INCLUDED
#include "Notebook.h"

/** \brief Menu de opciones
 *
 * \return int retorna la opcion seleccionada
 *
 */
int menu();


/** \brief Valida si lo que se ingreso son letras
 *
 * \param texto[] char cadena de caracteres
 * \return int retorna 0 si esta bien y 1 si esta mal
 *
 */
int validarString(char texto[]);

#endif // BIBLIOTECAEMPLEADO_H_INCLUDED
