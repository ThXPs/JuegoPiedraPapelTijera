#include <stdio.h>
#include <unistd.h>  // Para usleep

int main() {
    // Declaro una matriz para almacenar el nombre del usuario
    char nombre[100];

    // Solicito al usuario que ingrese su nombre
    printf("Ingrese su nombre: ");
    // Lee el nombre del usuario y lo almacena en la matriz 'nombre'
    scanf("%99s", nombre);  // Limita la entrada para evitar desbordamiento de búfer

    // Muestra un saludo usando el nombre ingresado
    printf("Hola, %s. Bienvenido al juego Piedra, Papel o Tijera.\n", nombre);

    // Pausa de 3 segundos (3000000 microsegundos)
    usleep(3000000);

    // Agregar una pausa antes de cerrar la consola
    printf("Presiona Enter para salir del Juego...");
    getchar();  // Espero a que el usuario presione Enter

    return 0;
}