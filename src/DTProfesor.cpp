#include "../include/DTProfesor.h"
#include "../include/DTUsuario.h"

#include <set>
#include <string>
using namespace std;

DTProfesor::DTProfesor(string nombre, string descripcion, string instituto, set<string> idiomas): DTUsuario(nombre, descripcion) {
    this->nombreInstituto = instituto;
    this->listaIdiomas = idiomas;
}

string DTProfesor::getDescripcionString() {
    return this->getDescripcion();
}
set<string> DTProfesor::getIdiomas() {
    return this->listaIdiomas;
}
string DTProfesor::getNombreString() {
    return this->getNombre();
}
string DTProfesor::getInstituto() {
    return this->nombreInstituto;
}