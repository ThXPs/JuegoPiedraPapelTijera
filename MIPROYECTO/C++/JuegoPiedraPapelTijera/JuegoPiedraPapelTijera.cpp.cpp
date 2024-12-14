#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
string nombre;
cout << "Ingrese su nombre: ";
cin >> nombre;
cout << "Hola, " << nombre << ". Bienvenido al juego Piedra, Papel o Tijera." << endl;
string opciones[3] = {"Piedra", "Papel", "Tijera"};
int eleccionUsuario, eleccionComputadora;
srand(time(0)); // Inicializa el generador de números aleatorios
// Obtener la elección del usuario
cout << "Elige una opcion:" << endl;
cout << "1. Piedra" << endl;
cout << "2. Papel" << endl;
cout << "3. Tijera" << endl;
cin >> eleccionUsuario;
do{
if (eleccionUsuario < 1 || eleccionUsuario > 3) {
        cout << "Opcion no validda. Por favor elige 1, 2, o 3." << endl;
        return 1;
    }
  }while (eleccionUsuario < 1 || eleccionUsuario > 3); // Repite hasta que la opción sea válida

// Generar la elección de la computadora
 eleccionComputadora = (rand() % 3) + 1;
// Mostrar las elecciones
cout << "Tu eleccion: " << opciones[eleccionUsuario - 1 ] << endl;
cout << "Eleccion de la computadora: " << opciones[eleccionComputadora - 1] << endl;
// Determinar el resultado
if ((eleccionUsuario == eleccionComputadora ))
cout << "¡Empate!" << endl;
else if ((eleccionUsuario == 1 && eleccionComputadora == 2) ||
(eleccionUsuario == 2 && eleccionComputadora == 3) ||
(eleccionUsuario == 3 && eleccionComputadora == 1))
cout << "¡Perdiste!" << endl;
else if ((eleccionUsuario == 1 && eleccionComputadora == 3) ||
(eleccionUsuario == 2 && eleccionComputadora == 1) ||
(eleccionUsuario == 3 && eleccionComputadora == 2))
cout << "¡Ganaste!" << endl;
return 0;
}
