#include "Servicios.h"
void hardcodearServicios(eServicio servicios[])
{
    int precios[] = {250,300,400,600};
    char servicioss[][25] = {"Bateria","Antivirus","Actualizacion","Fuente"};

    for ( int i = 0; i < CANT; i++ )
    {
        servicios[i].id = cargarIDServicios();
        servicios[i].precio = precios[i];
        strcpy(servicios[i].descripcion, servicioss[i]);
    }
}

int cargarIDServicios (void)
{
    static int idServicio = 20000;

    idServicio++;
    return idServicio;
}


void mostrarServicio(eServicio unServicio)
{
    printf("%5.2f %20s\n",unServicio.precio,unServicio.descripcion);
}

void mostrarServicios(eServicio unServicio[], int tam)
{
    printf("   ID      PRECIO                  SERVICIO\n");

    for (int i = 0; i < CANT; i++)
    {
        printf("%5d %10.0f$ %25s\n",unServicio[i].id,unServicio[i].precio,unServicio[i].descripcion);
    }
}


