#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED
#include "Notebook.h"
typedef struct
{
    int id;
    int isEmpty;
    float precio;
    char descripcion[26];

}eServicio;


/** \brief Hardcodea la estructura servicios
 *
 * \param servicios[] eServicio estructura servicios
 * \return void
 *
 */
void hardcodearServicios(eServicio servicios[]);

/** \brief Asigna una id a servicios
 *
 * \param void
 * \return La id autoincremental
 *
 */
int cargarIDServicios(void);

/** \brief Muestra un servicio
 *
 * \param unServicio eServicio estructura servicio
 * \return void
 *
 */
void mostrarServicio(eServicio unServicio);

/** \brief Muestra todos los servicios
 *
 * \param unServicio[] eServicio
 * \param tam int
 * \return void
 *
 */
void mostrarServicios(eServicio unServicio[], int tam);


#endif // SERVICIOS_H_INCLUDED
