/*
 * File: main.c
 * Author: Sergi Martinez
 * Description: PEC4 - Comaración paneles solares
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
typedef struct
{                           // estructura de la tupla
    char marca[40];         // marca del panel, maximo 40 carácteres (EcoPanel)
    double energiaGenerada; // energia generada por el panel en kWh (400.0)
    double superficie;      // superficie del panel en metros cuadrados (2.0)
    int coste;              // coste del panel en euros (350)
} PanelSolar;

int main()
{
    char archivo1[12], archivo2[12]; // guardamos los nombres de los archivos
    double ef1, ef2;                 // eficiencia de cada panel
    bool panel1Mejor;                // variable para comparar los paneles

    printf("INPUT \n");
    printf("FILENAME1?\n");
    scanf("%s", archivo1); // nombre del archivo 1

    printf("FILENAME2?\n");
    scanf("%s", archivo2); // nombre del archivo 2

    PanelSolar panel1, panel2; // creamos dos variables para guardar los datos de cada panel

    FILE *archivo = fopen(archivo1, "r");                                                                       // abrimos el archivo 1
    fscanf(archivo, "%s %lf %lf %d", panel1.marca, &panel1.energiaGenerada, &panel1.superficie, &panel1.coste); // leemos los datos del panel 1
    fclose(archivo);                                                                                            // cerramos el archivo 1

    archivo = fopen(archivo2, "r");                                                                             // abrimos el archivo 2
    fscanf(archivo, "%s %lf %lf %d", panel2.marca, &panel2.energiaGenerada, &panel2.superficie, &panel2.coste); // leemos los datos del panel 2
    fclose(archivo);                                                                                            // cerramos el archivo 2

    // calculamos la eficiencia de cada panel y comparamos
    ef1 = panel1.energiaGenerada / panel1.superficie;
    ef2 = panel2.energiaGenerada / panel2.superficie;

    if (ef1 > ef2)
    {
        panel1Mejor = true; // el panel 1 es mejor
    }
    else if (ef2 > ef1)
    {
        panel1Mejor = false; // el panel 2 es mejor
    }
    else // en caso de empate de eficiencia, comparamos el coste
    {
        if (panel1.coste < panel2.coste)
        {
            panel1Mejor = true; // el panel 1 es mejor
        }
        else if (panel2.coste < panel1.coste)
        {
            panel1Mejor = false; // el panel 2 es mejor
        }
        else
        {
            if (strcmp(panel1.marca, panel2.marca))
            {
                panel1Mejor = true; // el panel 1 es mejor
            }
            else
            {
                panel1Mejor = false; // el panel 2 es mejor
            }
        }
    }
    printf("OUTPUT\n");
    if (panel1Mejor == true)
    {
        printf("THE BEST PANEL IS %s", panel1.marca); // mostramos el nombre del panel 1
    }
    else
    {
        printf("THE BEST PANEL IS %s", panel2.marca); // mostramos el nombre del panel 2
    }

}