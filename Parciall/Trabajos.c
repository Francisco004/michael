#include "Trabajos.h"
int cargarIDTrabajo (void)
{
    static int idTrabajo = 0;

    idTrabajo++;
    return idTrabajo;
}

void altaTrabajo(eTrabajo unTrabajo[], eNotebook unaNotebook[],int tam)
{
    int id;
    int entero;
    int opcion;
    int idTrabajo;
    char confirmar;

    idTrabajo = cargarIDTrabajo();

    unTrabajo[idTrabajo].id = idTrabajo;

    printf("   ID               MODELO     PRECIO                MARCA                 TIPO\n");
    for (int i = 0; i < tam; i++)
    {
        if(unaNotebook[i].isEmpty == LLENO)
        {
            mostrarNotebookConID(unaNotebook[i]);
        }
    }

    printf("\nIngese la id con la notebook que quiere trabajar: ");
    scanf(" %d",&id);

    for(int i = 0; i < tam; i++)
    {
        if (unaNotebook[i].id == id)
        {
            system("cls");
            printf("\nLa notebook que selecciono es: \n");
            printf("              MODELO     PRECIO                MARCA                 TIPO\n");
            mostrarNotebook(unaNotebook[i]);

            printf("\n\nDesea trabajar con esta notebook? S = SI: ");
            scanf(" %c",&confirmar);

            confirmar = toupper(confirmar);

            if(confirmar == 'S')
            {
                system("cls");
                printf("Se trabaja entonces...\n");
                system("pause");

                unTrabajo[idTrabajo].isEmpty = LLENO;
                unTrabajo[idTrabajo].idNotebook = id;

                do
                {
                    printf("\nQue servicio que desea \n1) Bateria: $250\n2) Antivirus: $300\n3) Actualizacion: $400\n4) Fuente: $600\nutilize los numeros mostrados arriba: ");
                    scanf(" %d",&opcion);

                    switch (opcion)
                    {
                    case 1:
                        printf("\nServicio bateria seleccionado\n\n");
                        unTrabajo[idTrabajo].idServicio = 20001;
                        break;

                    case 2:
                        printf("\nServicio antivirus seleccionado\n\n");
                        unTrabajo[idTrabajo].idServicio = 20002;
                        break;

                    case 3:
                        printf("\nServicio actualizacion seleccionado\n\n");
                        unTrabajo[idTrabajo].idServicio = 20003;
                        break;

                    case 4:
                        printf("\nServicio fuente seleccionado\n\n");
                        unTrabajo[idTrabajo].idServicio = 20004;
                        break;

                    default:
                        system("cls");
                        printf("Opcion incorrecta...\n");
                        system("pause");
                        break;
                    }

                }
                while(opcion > 4 || opcion < 1);

                system("pause");
                system("cls");



                ///DIA DE SERVICIO



                do
                {
                    printf("Ingrese el dia que desea el servicio: ");
                    entero = scanf(" %d",&unTrabajo[idTrabajo].fecha.dia);
                    fflush(stdin);
                }
                while(entero == 0 || unTrabajo[idTrabajo].fecha.dia > 31);




                ///MES DE SERVICIO




                if(unTrabajo[idTrabajo].fecha.dia <= 28)
                {
                    do
                    {
                        printf("\nIngrese el mes que desea el servicio: ");
                        entero = scanf(" %d",&unTrabajo[idTrabajo].fecha.mes);
                        fflush(stdin);
                    }
                    while(entero == 0 || unTrabajo[idTrabajo].fecha.mes > 12);
                }

                if(unTrabajo[idTrabajo].fecha.dia > 28)
                {
                    if(unTrabajo[idTrabajo].fecha.dia > 30)
                    {
                        do
                        {
                            printf("\nIngrese el mes que desea el servicio: ");
                            entero = scanf(" %d",&unTrabajo[idTrabajo].fecha.mes);
                            fflush(stdin);
                        }
                        while(entero == 0 || unTrabajo[idTrabajo].fecha.mes == 2 || unTrabajo[idTrabajo].fecha.mes == 4 || unTrabajo[idTrabajo].fecha.mes == 6 || unTrabajo[idTrabajo].fecha.mes == 9 || unTrabajo[idTrabajo].fecha.mes == 11 || unTrabajo[idTrabajo].fecha.mes > 12);
                    }
                    else
                    {
                        do
                        {
                            printf("\nIngrese el mes que desea el servicio: ");
                            entero = scanf(" %d",&unTrabajo[idTrabajo].fecha.mes);
                            fflush(stdin);
                        }
                        while(entero == 0 || unTrabajo[idTrabajo].fecha.mes == 2 || unTrabajo[idTrabajo].fecha.mes > 12);
                    }
                }



                ///AÑO DE SERVICIO



                do
                {
                    printf("\nIngrese el anio que desea el servicio: ");
                    entero = scanf(" %d",&unTrabajo[idTrabajo].fecha.anio);
                    fflush(stdin);
                }
                while(entero == 0 || unTrabajo[idTrabajo].fecha.anio < 2020);
            }
            else
            {
                printf("No se trabaja...\n");
            }
            break;
        }
        else if (i == 999)
        {
            printf("No hay una notebook con esta id...\n");
            system("pause");
        }
    }
}

void mostrarTrabajos(eNotebook unaNotebook[], eTrabajo unTrabajo[], eServicio unServicio[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        if(unTrabajo[i].isEmpty == LLENO)
        {
            printf("\n----------------------------------Trabajo Numero %d----------------------------------\n",i);

            printf("\nNotebook:\n");
            for(int j = 0; j < tam; j++)
            {
                if(unaNotebook[j].id == unTrabajo[i].idNotebook)
                {
                    printf("              MODELO     PRECIO                MARCA                 TIPO\n");
                    mostrarNotebook(unaNotebook[j]);
                }
            }

            printf("\nServicio:\n");
            for(int x = 0; x < tam; x++)
            {
                if(unServicio[x].id == unTrabajo[i].idServicio)
                {
                    printf("            PRECIO             SERVICIO\n");
                    printf("            ");
                    mostrarServicio(unServicio[x]);
                }
            }

            printf("\nFecha:\n");
            printf("            DIA  MES  ANIO\n");
            if(unTrabajo[i].fecha.mes < 10)
            {
                printf("            %d / 0%d / %d\n\n",unTrabajo[i].fecha.dia,unTrabajo[i].fecha.mes,unTrabajo[i].fecha.anio);
            }
            else
            {
                printf("            %d / %d / %d\n\n",unTrabajo[i].fecha.dia,unTrabajo[i].fecha.mes,unTrabajo[i].fecha.anio);
            }
        }
    }
}

