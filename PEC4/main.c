/*
 * File: main.c
 * Author: Sergi Martinez
 * Description: PEC4 - Comparación paneles solares
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_MARCA_LEN 41 // maximo 41 caracteres para la marca del panel solar
#define MAX_FILENAME_LEN 13 // maximo 13 caracteres para el nombre del archivo
typedef struct { // estructura de la tupla
    char marca[MAX_MARCA_LEN]; // marca del panel, maximo 40 carácteres (EcoPanel)
    double energiaGenerada; // energia generada por el panel en kWh (400.0)
    double superficie; // superficie del panel en metros cuadrados (2.0)
    int coste; // coste del panel en euros (350)
} tPanelSolar;

int main() {
    char fileName1[MAX_FILENAME_LEN] = ""; // guardamos el nombre del archvio 1
    char fileName2[MAX_FILENAME_LEN] = ""; // guardamos el nombre del archvio 2
    double efficiency1 = 0.0; // eficiencia del panel 1
    double efficiency2 = 0.0; // eficiencia del panel 2
    bool isPanel1Better = false; // variable para comparar los paneles

    printf("INPUT \n");
    printf("FILENAME1?\n");
    scanf("%s", fileName1); // nombre del archivo 1

    printf("FILENAME2?\n");
    scanf("%s", fileName2); // nombre del archivo 2

    tPanelSolar panel1, panel2; // creamos dos variables para guardar los datos de cada panel

    
    FILE *archivo = NULL;

    archivo = fopen(fileName1, "r"); // abrimos el archivo 1
    if (archivo != NULL) { // comprobación de seguridad
        fscanf(archivo, "%s %lf %lf %d", panel1.marca, &panel1.energiaGenerada, &panel1.superficie, &panel1.coste); // leemos los datos del panel 1
        fclose(archivo); // cerramos el archivo 1
    }
    archivo = fopen(fileName2, "r"); // abrimos el archivo 2
    if (archivo != NULL) {// comprobación de seguridad
        fscanf(archivo, "%s %lf %lf %d", panel2.marca, &panel2.energiaGenerada, &panel2.superficie, &panel2.coste); // leemos los datos del panel 2
        fclose(archivo); // cerramos el archivo 2
    }

    // calculamos la eficiencia de cada panel y comparamos
    efficiency1 = panel1.energiaGenerada / panel1.superficie;
    efficiency2 = panel2.energiaGenerada / panel2.superficie;

    if (efficiency1 > efficiency2){
        isPanel1Better = true; // el panel 1 es mejor
    }
    else if (efficiency2 > efficiency1){
        isPanel1Better = false; // el panel 2 es mejor
    } else {  // en caso de empate de eficiencia, comparamos el coste
        if (panel1.coste < panel2.coste) {
            isPanel1Better = true; // el panel 1 es mejor
        } else if (panel2.coste < panel1.coste) {
            isPanel1Better = false; // el panel 2 es mejor
        } else {
            if (strcmp(panel1.marca, panel2.marca) < 0) { // si el nombre del panel 1 es menor al del panel 2, entonces el panel 1 es mejor
                isPanel1Better = true; // el panel 1 es mejor
            } else {
                isPanel1Better = false; // el panel 2 es mejor
            }
        }
    }
    printf("OUTPUT\n");
    if (isPanel1Better == true){
        printf("THE BEST PANEL IS %s", panel1.marca); // mostramos el nombre del panel 1
    } else {
        printf("THE BEST PANEL IS %s", panel2.marca); // mostramos el nombre del panel 2
    }
    return 0;
}