#include "Parcial.h"

int validarString(char texto[])
{
    int retorno = 0;

    for (int i = 0; i < strlen(texto); i++)
    {
        if (!((texto[i]>=65 && texto[i]<=90) || (texto[i]>=97 && texto[i]<=122)))
        {
            printf("Solo ingrese letras....\n\n");
            retorno = 1;
            system("pause");
            break;
        }
    }


    return retorno;
}

int menu()
{
    int opcion;

    printf("****************************************************************************\n");
    printf("**********   PARCIAL NOTEBOOK    FRANCISCO ROCHA   CURSO: 1-A   ************\n");
    printf("****************************************************************************\n");
    printf("*********** 1- ALTA de Notebook                                 ************\n");
    printf("***********                                                     ************\n");
    printf("*********** 2- MODIFICAR         / PRECIO / TIPO /              ************\n");
    printf("***********                                                     ************\n");
    printf("*********** 3- BAJA ingresando ID                               ************\n");
    printf("***********                                                     ************\n");
    printf("*********** 4- LISTAR NOTEBOOKS                                 ************\n");
    printf("***********                                                     ************\n");
    printf("*********** 5- LISTAR MARCAS                                    ************\n");
    printf("***********                                                     ************\n");
    printf("*********** 6- LISTAR TIPOS                                     ************\n");
    printf("***********                                                     ************\n");
    printf("*********** 7- LISTAR SERVICIOS                                 ************\n");
    printf("***********                                                     ************\n");
    printf("*********** 8- ALTA TRABAJO                                     ************\n");
    printf("***********                                                     ************\n");
    printf("*********** 9- LISTAR TRABAJO                                   ************\n");
    printf("***********                                                     ************\n");
    printf("*********** 10- MOSTRAR NOTEBOOK SELECCION TIPO                 ************\n");
    printf("***********                                                     ************\n");
    printf("*********** 11- MOSTRAR NOTEBOOK SELECCION MARCA                ************\n");
    printf("***********                                                     ************\n");
    printf("*********** 12- MOSTRAR NOTEBOOK MAS BARATA                     ************\n");
    printf("***********                                                     ************\n");
    printf("*********** 13- MOSTRAR NOTEBOOK POR MARCA                      ************\n");
    printf("***********                                                     ************\n");
    printf("*********** 14- CANTIDAD DE NOTEBOOKS POR TIPO Y MARCA          ************\n");
    printf("***********                                                     ************\n");
    printf("*********** 15- MARCA/S MAS ELEGIDAS POR LOS CLIETNES           ************\n");
    printf("***********                                                     ************\n");
    printf("***********                     16- Salir                       ************\n");
    printf("****************************************************************************\n");
    printf("****************************************************************************\n");

    printf("Ingrese una opcion: ");
    scanf(" %d",&opcion);

    return opcion;
}
