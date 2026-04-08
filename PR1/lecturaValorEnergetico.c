/*
 * File: main.c
 * Author: Sergi Martinez
 * Description: PR1 - Lectura del valor energético
 */

#include <stdio.h>
#include <stdbool.h>
#define MAX_READINGS 100 // valor maximo de lecturas
#define ERROR_VALUE 0.0 // valor de error para lecturas no validas
enum tTariffType
{
    VALLEY,
    FLAT,
    PEAK
}; // tipos de tarifa, 1 ,2 y 3

int main()
{
    float powerData[MAX_READINGS]; // guardamos valores de energia
    int tariffData[MAX_READINGS];  // guardamos valores de tarifa
    float maxPower = 0.0;          // valor maximo de potencia
    float averagePower = 0.0;      // promedio de potencia
    int maxTariff = 0;             // tipo de tarifa maxima
    float totalConsumption = 0.0;  // consumo total
    int totalElements = 0;         // numero total de elementos
    int validReadingsCount = 0;    // contador de lecturas validas
    int invalidReadingsCount = 0;  // contador de lecturas no validas
    // contadores para cada tipo de tarifa
    int countValley = 0;
    int countFlat = 0;
    int countPeak = 0;

    int i, j = 0;      // variables de control para los bucles
    char filename[20]; // nombre del archivo a leer, maximo 20 caracteres
    FILE *fileToRead;

    printf("--- Smart Grid Analysis System (PR1) ---\n");
    printf("LOAD DATA FROM FILE. ENTER FILE NAME >> ");
    scanf("%s", filename); // leemos el nombre del archivo a leer
    fileToRead = fopen(filename, "r");

    fscanf(fileToRead, "%d", &totalElements); // leemos el numero total de elementos del archivo
    // nos aseguramos que no superamor el maximo de lectura
    // si el totalElements (ej: 5) es mayor que MAX_READINGS (100) entonces lo limitamos a 100
    if (totalElements > MAX_READINGS)
    {
        totalElements = MAX_READINGS;
    }

    // lectura de los datos de carga y tarifas del archivo
    for (i = 0; i < totalElements; i++)
    {
        fscanf(fileToRead, "%f", &powerData[i]); // leemos la potencia del archivo
        fscanf(fileToRead, "%d", &tariffData[i]); // leemos la tarifa del archivo
    }

    fclose(fileToRead); // cerramos el archivo despues de leer los datos

    // procesamiento de datos
    printf("\nProcessing %d records... \n", totalElements);
    for (j = 0; j < totalElements; j++)
    { // lee desde la posicion 1 hasta la maxima de lectura que tenga
        if (powerData[j] < ERROR_VALUE)
        {                           // si la potencia es menor que el valor de error, es una lectura no valida
            invalidReadingsCount++; // incrementamos el contador de lecturas no validas
        }
        else
        {
            // registro valido de lecturas y consumo total
            validReadingsCount++;             // incrementamos el contador de lecturas validas
            totalConsumption += powerData[j]; // sumamos la potencia al consumo total
            // pico de potencia
            if (powerData[j] > maxPower)
            {                              // si la potencia es mayor que el maximo registrado
                maxPower = powerData[j];   // actualizamos el maximo de potencia
                maxTariff = tariffData[j]; // actualizamos la tarifa maxima asociada a ese pico de potencia
            }
            // contado de tarifas
            if (tariffData[j] == 1)
            {                  // si la tarifa es Valley
                countValley++; // incrementamos el contador de tarifa Valley
            }
            else if (tariffData[j] == 2)
            {                // si la tarifa es Flat
                countFlat++; // incrementamos el contador de tarifa Flat
            }
            else if (tariffData[j] == 3)
            {                // si la tarifa es Peak
                countPeak++; // incrementamos el contador de tarifa Peak
            }
        }
    }
    printf("----------------------------------------\n");
    printf("ANALISYS SUMMARY\n");
    printf("----------------------------------------\n");

    if (validReadingsCount > 0)
    {                                                         // si hay lecturas validas, calculamos el promedio
        averagePower = totalConsumption / validReadingsCount; // calculamos el promedio de potencia
        // salida de datos
        printf("Total consumption: %.2f kW\n", totalConsumption); // mostramos el consumo total
        printf("Average power: %.2f kW\n", averagePower);         // mostramos el promedio de potencia
        printf("Maximum peak: %.2f kW ", maxPower);                // mostramos el pico de potencia
        printf("(Tariff:");                       // mostramos la tarifa asociada al pico de potencia
        if (maxTariff == 1)
        { // si la tarifa es Valley
            printf(" VALLEY)\n");
        }
        else if (maxTariff == 2)
        { // si la tarifa es Flat
            printf(" FLAT)\n");
        }
        else if (maxTariff == 3)
        { // si la tarifa es Peak
            printf(" PEAK)\n");
        }
        printf("\nDistribution by Tariff: \n");

        for (j = 1; j <= 3; j++)
        { // mostramos la distribucion de las tarifas
            if (j == 1)
            { // si es tarifa Valley
                printf("- VALLEY intervals: %d\n", countValley);
            }
            else if (j == 2)
            { // si es tarifa Flat
                printf("- FLAT intervals: %d\n", countFlat);
            }
            else if (j == 3)
            { // si es tarifa Peak
                printf("- PEAK intervals: %d\n", countPeak);
            }
        }

        printf("\nDiscarded readings: %d\n", invalidReadingsCount); // mostramos el numero de lecturas no validas

        for (j = 0; j < totalElements; j++)
        { // mostramos las lecturas no validas
            if (powerData[j] < ERROR_VALUE)
            {
                printf("%.2f kW\n",powerData[j]);
            }
        }
        printf("----------------------------------------\n");
    }
}
