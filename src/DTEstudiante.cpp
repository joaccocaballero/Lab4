#include "../include/DTEstudiante.h"
#include "../include/DTUsuario.h"

#include <string>
using namespace std;

DTEstudiante::DTEstudiante(string nombre, string descripcion, string paisResidencia): DTUsuario(nombre, descripcion) {
    this->paisResidencia = paisResidencia;
}

string DTEstudiante::getDescripcionString() {
    return this->getDescripcion();
}
string DTEstudiante::getPaisResidencia() {
    return this->paisResidencia;
}
string DTEstudiante::getNombreString() {
    return this->getNombre();
}
