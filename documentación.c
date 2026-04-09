/*
 * File: main.c
 * Author: Sergi Martinez
 * Description: EJEMPLO DE DOCUMENTACIÓN EN C
 */

#include <stdio.h>   // Entrada/Salida básica (printf, scanf, archivos)
#include <string.h>  // Manipulación de texto (strcmp, strcpy, strlen)
#include <stdbool.h> // Para usar tipos booleanos (true, false)

// --- 1. DEFINICIONES GLOBALES ---
#define PI 3.14159       // Macro (constante de preprocesador, sin ';')
const int MAX_VIDAS = 3; // Constante de lenguaje (con tipo y ';')

// --- 2. TIPOS DE DATOS Y FORMATOS ---
/*
   int    -> %d  (Enteros: 1, -5, 42)
   float  -> %f  (Reales: 3.14, -0.5)
   double -> %lf (Reales de alta precisión)
   char   -> %c  (Un solo carácter: 'A', '9')
   char[] -> %s  (Cadenas de texto: "Hola")
*/

int main()
{

    // --- 3. DECLARACIÓN E INICIALIZACIÓN ---
    int edad = 20;
    float temperatura = 25.5;
    char inicial = 'S';
    char nombre[20] = "Sergi"; // Las cadenas necesitan un tamaño máximo

    // --- 4. ENTRADA Y SALIDA (CONSOLA) ---
    printf("Hola %s, tienes %d años.\n", nombre, edad); // \n es salto de línea

    // IMPORTANTE: scanf necesita el '&' para variables numéricas
    // printf("Dime tu edad: ");
    // scanf("%d", &edad);

    // --- 5. OPERADORES ---
    // Aritméticos: +, -, *, /, % (módulo/resto de división)
    // Lógicos: && (AND), || (OR), ! (NOT)
    // Comparación: == (igual), != (distinto), <, >, <=, >=
    // Incrementos: edad++; (suma 1) | edad--; (resta 1)

    // --- 6. ESTRUCTURAS DE CONTROL ---

    // IF - ELSE (Selección)
    if (temperatura >= 30.0)
    {
        printf("Hace calor.\n");
    }
    else if (temperatura < 15.0)
    {
        printf("Hace frío.\n");
    }
    else
    {
        printf("Clima agradable.\n");
    }
    // SWITCH (Selección múltiple para casos fijos)
    int opcion = 2;
    switch (opcion)
    {
    case 1:
        printf("Opción A\n");
        break;
    case 2:
        printf("Opción B\n");
        break;
    default:
        printf("Opcion no válida\n");
    }

    // --- 7. BUCLES (ITERACIÓN) ---

    // FOR: Cuando sabemos cuántas veces repetir
    // (inicio; condición; incremento)
    for (int i = 0; i < 5; i++)
    {
        printf("Vuelta número %d\n", i);
    }

    // WHILE: Repite mientras la condición sea cierta
    int contador = 0;
    while (contador < 3)
    {
        contador++;
    }

    // --- 8. VECTORES (ARRAYS) ---
    // Importante: El primer elemento SIEMPRE es el índice 0
    int notas[3] = {10, 8, 9};
    notas[0] = 7; // Cambiamos el 10 por un 7

    // --- 9. CADENAS DE TEXTO (STRINGS) ---
    char palabra1[] = "Hola";
    char palabra2[] = "Adiós";

    // Comparar: strcmp devuelve 0 si son iguales
    if (strcmp(palabra1, palabra2) == 0)
    {
        // Son iguales
    }

    // Copiar: strcpy(destino, origen)
    strcpy(palabra1, "Nuevo");

    // --- 10. FUNCIONES MATEMÁTICAS COMUNES ---
    // (Requieren #include <math.h>)
    // pow(base, exponente); -> Potencia
    // sqrt(numero);         -> Raíz cuadrada

    // --- 11. MANEJO DE ARCHIVOS (FILE I/O) SIN FUNCIONES ---

    // Declaramos el puntero al archivo
    FILE *f;
    int numeroLeido;
    float datoEscrito = 10.5;

    // A) LECTURA
    f = fopen("datos.txt", "r");
    if (f != NULL)
    {
        // Leemos hasta que no haya más datos (EOF)
        while (fscanf(f, "%d", &numeroLeido) != EOF)
        {
            // Aquí iría el procesamiento (sumas, máximos, etc.)
        }
        fclose(f);
    }

    // B) ESCRITURA / EDICIÓN
    // Importante: "w" borra lo que había. "a" escribe al final sin borrar.
    f = fopen("reporte.txt", "w");
    if (f != NULL)
    {
        fprintf(f, "Resultado del análisis: %.2f\n", datoEscrito);
        fclose(f);
    }

    // --- 12. ESTRUCTURAS (Las "Tuplas" o Registros) ---
    // Se definen ARRIBA, fuera del main, para que C sepa qué forma tienen.
    struct Medicion
    {
        int id;
        float valor;
        int tipo; // 1, 2 o 3
    };

    // --- DENTRO DEL MAIN ---

    // 1. Crear una variable tipo estructura
    struct Medicion m1;

    // 2. Asignar valores (como en una tupla, pero con nombres)
    m1.id = 1;
    m1.valor = 23.5;
    m1.tipo = 2;

    // 3. VECTORES DE ESTRUCTURAS
    // Esto es como una tabla: cada fila es una "tupla"
    struct Medicion historial[MAX_ELEMENTOS];

    // Guardar datos en la primera posición
    historial[0].id = 101;
    historial[0].valor = 45.2;
    historial[0].tipo = 1;

    // Leer datos de la estructura
    printf("El valor del primer registro es: %.2f", historial[0].valor);
    return 0; // Fin del programa
}