#include "Marcas.h"
void hardcodearMarcas(eMarca marcas[])
{
    char marca[CANT][10] = {"Compaq","Asus","Acer","HP"};

    for ( int i = 0; i < CANT; i++ )
    {
        strcpy(marcas[i].descripcion, marca[i]);
        marcas[i].id = cargarIDMarcas();
        marcas[i].isEmpty = LLENO;
    }
}


int cargarIDMarcas (void)
{
    static int idMarca = 1000;

    idMarca++;
    return idMarca;
}

void mostrarMarcas(eNotebook unaNotebook[], eMarca unaMarca[], int tam)
{
    int vandera = VACIO;
    int prueba = 0;

    for (int i = 0; i < tam; i++)
    {
        if(unaMarca[i].isEmpty == LLENO)
        {
            prueba = 1;
            printf("%10d %20s\n",unaMarca[i].id,unaMarca[i].descripcion);
        }
    }

    for (int i = 0; i < tam; i++)
    {
        if(unaNotebook[i].isEmpty == LLENO)
        {
            printf("%10d %20s\n",unaNotebook[i].marcaDescripcion.id,unaNotebook[i].marcaDescripcion.descripcion);
            vandera = LLENO;
        }
    }

    if(vandera == VACIO && prueba == 0)
    {
        printf("No hay marcas que listar...\n\n");
    }
}
