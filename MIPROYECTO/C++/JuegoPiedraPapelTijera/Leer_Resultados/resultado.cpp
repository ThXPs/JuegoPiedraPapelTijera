#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>  // Para la lectura de archivos



struct Partida {
    int puntaje;
    bool ganada;
    int duracionMinutos;
    std::string fecha;

    Partida(int puntaje, bool ganada, int duracionMinutos, const std::string& fecha)
        : puntaje(puntaje), ganada(ganada), duracionMinutos(duracionMinutos), fecha(fecha) {}
};

class Estadisticas {
private:
    std::vector<Partida> partidas;
    int partidasGanadas;
    int partidasPerdidas;

public:
    Estadisticas() : partidasGanadas(0), partidasPerdidas(0) {}

    void agregarPartida(int puntaje, bool ganada, int duracionMinutos, const std::string& fecha) {
       partidas.push_back(Partida(puntaje, ganada, duracionMinutos, fecha));

        if (ganada) {
            partidasGanadas++;
        } else {
            partidasPerdidas++;
        }
    }

    bool leerResultadosDesdeArchivo(const std::string& nombreArchivo) {
        std::ifstream archivo(nombreArchivo.c_str());  // Convertir std::string a const char*
        if (!archivo.is_open()) {
            std::cerr << "Error: No se pudo abrir el archivo " << nombreArchivo << std::endl;
            return false;
        }

        int puntaje, duracionMinutos, resultado;
        std::string fecha, hora;
        while (archivo >> puntaje >> resultado >> duracionMinutos >> fecha >> hora) {
            bool ganada = resultado == 1;
            agregarPartida(puntaje, ganada, duracionMinutos, fecha + " " + hora);
        }

        archivo.close();
        return true;
    }

    void mostrarEstadisticas() const {
        std::cout << "Estadísticas Generales:" << std::endl;
        std::cout << "Partidas Jugadas: " << partidas.size() << std::endl;
        std::cout << "Partidas Ganadas: " << partidasGanadas << std::endl;
        std::cout << "Partidas Perdidas: " << partidasPerdidas << std::endl;

        std::cout << "\nDetalle por Partida:" << std::endl;
        std::cout << std::setw(5) << "No." << std::setw(10) << "Puntaje" << std::setw(10) 
                  << "Duración" << std::setw(15) << "Resultado" << std::setw(20) << "Fecha" << std::endl;

        for (size_t i = 0; i < partidas.size(); ++i) {
            std::cout << std::setw(5) << i + 1
                      << std::setw(10) << partidas[i].puntaje
                      << std::setw(10) << partidas[i].duracionMinutos << " min"
                      << std::setw(15) << (partidas[i].ganada ? "Ganada" : "Perdida")
                      << std::setw(20) << partidas[i].fecha
                      << std::endl;
        }
    }
};

int main() {
    Estadisticas estadisticas;

    // Leer resultados desde el archivo
    if (estadisticas.leerResultadosDesdeArchivo("resultados.txt")) {
        estadisticas.mostrarEstadisticas();
    } else {
        std::cerr << "Error al leer el archivo de resultados." << std::endl;
    }

    return 0;
}
