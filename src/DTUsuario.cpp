#include "../include/DTUsuario.h"

#include <string>
using namespace std;

DTUsuario::DTUsuario(string nombre, string descripcion) {
    this->nombre = nombre;
    this->descripcion = descripcion;
}

string DTUsuario::getDescripcion(){
    return this->descripcion;
}
string DTUsuario::getNombre(){
    return this->nombre;
}