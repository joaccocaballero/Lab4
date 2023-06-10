#include "../include/DTProfesor.h"
#include "../include/DTUsuario.h"

#include <set>
#include <string>
using namespace std;

DTProfesor::DTProfesor(string nombre, string descripcion, string instituto, set<string> idiomas): DTUsuario(string nombre, string descripcion) {
    this->nombreInstituto = instituto;
    this->listaIdiomas = idiomas;
}

string DTProfesor::getDescripcion() {
    return this->descripcion;
}
set<string> DTProfesor::getIdiomas() {
    return this->listaIdiomas;
}
string DTProfesor::getNombre() {
    return this->nombre;
}
string DTProfesor::getDInstituto() {
    return this->dnombreInstituto;
}