#include <stdio.h>
#include <math.h>
#include <string.h>

// Definimos la estructura de datos para representar una muestra de vino
typedef struct {
    int bodega;
    float alcohol;
    float acido_malico;
    float resto_posos;
    float alcalinidad_posos;
    float magnesio;
    float total_fenoles;
    float flavonoides;
    float fenoles_no_flavonoides;
    float proantocianidinas;
    float intensidad_color;
    float tono;
    float OD280_OD315;
    float prolina;
} MuestraVino;

#define MAX_MUESTRAS 178

MuestraVino muestras[MAX_MUESTRAS];

// Prototipos de funciones
int cargar_datos(const char* filename, int firma);
float* obtener_parametro(int parametro, int firma);
float calcular_media(float datos[], int num_muestras);
float calcular_desviacion_estandar(float datos[], int num_muestras, float media);
int guardar_datos_analytics(const char* filename, int firma);
int calidad_muestra(int indice, int firma);
int agregar_muestra(MuestraVino muestra, int firma);
int firma_de_codigo(const char* email);

// Opción 0: Configuración e inicialización
// Prepara el entorno
int configuracion_inicial() {
    printf("Entorno preparado.\n");
    return 1;
}

// Opción 1: Mostrar número de muestras, media y desviación estándar de cada parámetro
void opcion_1(int firma) {
    printf("Opción 1:\n");
    printf("Número de muestras: %d\n", MAX_MUESTRAS);

    float medias[14];
    float desviaciones[14];

    for (int i = 0; i < 14; i++) {
        float* parametro = obtener_parametro(i, firma);
        if (parametro != NULL) {
            medias[i] = calcular_media(parametro, MAX_MUESTRAS);
            desviaciones[i] = calcular_desviacion_estandar(parametro, MAX_MUESTRAS, medias[i]);
            printf("Media de parámetro %d: %.2f\n", i+1, medias[i]);
            printf("Desviación estándar de parámetro %d: %.2f\n", i+1, desviaciones[i]);
        }
    }
}

// Opción 2: Mostrar estadísticas por bodega
void opcion_2(int firma) {
    printf("Opción 2:\n");
    // Implementar
}

// Opción 3: Búsqueda de una muestra por número ordinal
void opcion_3(int num_ordinal, int firma) {
    printf("Opción 3:\n");
    // Implementar
}

// Opción 4: Control de calidad
void opcion_4(int firma) {
    printf("Opción 4:\n");
    // Implementar
}

// Opción 5: Agregar una muestra
void opcion_5(MuestraVino muestra, int firma) {
    printf("Opción 5:\n");
    // Implementar
}

// Opción 6: Ofrecer valor de la firma personalizada de código del alumno
int opcion_6(const char* email) {
    printf("Opción 6:\n");
    int firma = firma_de_codigo(email);
    printf("Firma de código: %d\n", firma);
    return firma;
}

// Función para cargar los datos desde el archivo
int cargar_datos(const char* filename, int firma) {
    // Implementar
    return 0;
}

// Función para obtener un arreglo con los datos de un parámetro específico de todas las muestras
float* obtener_parametro(int parametro, int firma) {
    // Implementar
    return NULL;
}

// Función para calcular la media de un conjunto de datos
float calcular_media(float datos[], int num_muestras) {
    // Implementar
    return 0.0;
}

// Función para calcular la desviación estándar de un conjunto de datos
float calcular_desviacion_estandar(float datos[], int num_muestras, float media) {
    // Implementar
    return 0.0;
}

// Función para guardar los datos en el archivo analytics.txt
int guardar_datos_analytics(const char* filename, int firma) {
    // Implementar
    return 0;
}

// Función para verificar la calidad de una muestra
int calidad_muestra(int indice, int firma) {
    // Implementar
    return 0;
}

// Función para agregar una nueva muestra
int agregar_muestra(MuestraVino muestra, int firma) {
    // Implementar
    return 0;
}

// Función para obtener la firma de código según el email del alumno
int firma_de_codigo(const char* email) {
    const char* dominio = "@alu.ubu.es";
    int nia_length = strcspn(email, dominio);
    if (nia_length != 7)
        return -1;
    
    int firma = 100; // Firma por defecto
    for (int i = 0; i < nia_length; i++) {
        firma ^= email[i];
    }
    return firma;
}

int main() {
    // Opción 0
    configuracion_inicial();

    // Opciones 1-6: Ejemplo de uso
    opcion_1(100);  // Ejemplo de llamada a la opción 1
    opcion_2(100);  // Ejemplo de llamada a la opción 2
    opcion_3(1, 100);  // Ejemplo de llamada a la opción 3
    opcion_4(100);  // Ejemplo de llamada a la opción 4
    MuestraVino nueva_muestra = {1, 12.5, 3.5, 2.7, 6.8, 120, 125, 43, 45, 34, 68, 0.8, 2.5, 890};
    opcion_5(nueva_muestra, 100);  // Ejemplo de llamada a la opción 5
    opcion_6("amc1070@alu.ubu.es");  // Ejemplo de llamada a la opción 6

    return 0;
}
