#include "../include/DTEstudiante.h"
#include "../include/DTUsuario.h"

#include <string>
using namespace std;

DTEstudiante::DTEstudiante(string nombre, string descripcion, string paisResidencia): DTUsuario(nombre, descripcion) {
    this->paisResidencia = paisResidencia;
}

string DTEstudiante::getDescripcion() {
    return this->descripcion;
}
string DTEstudiante::getPaisResidencia() {
    return this->paisResidencia;
}
string DTEstudiante::getNombre() {
    return this->nombre;
}
