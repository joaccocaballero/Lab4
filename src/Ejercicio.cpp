#include <string>
#include "../include/Ejercicio.h"

using namespace std;

Ejercicio::Ejercicio(int id, string consigna, string descripcion,EnumEjercicios tipo){
    this->id = id;
    this->consigna = consigna;
    this->descripcion = descripcion;
    this->tipo = tipo;
}
string Ejercicio::getConsigna(){
    return consigna;
}
EnumEjercicios Ejercicio::obtenerTipo(){
    return tipo;
}

int Ejercicio::obtenerId(){
    return id;
}

string Ejercicio::obtenerDescripcion(){
    return descripcion;
}

void Ejercicio::setId(int identifier){
   this->id = identifier;
}


bool Ejercicio::esCorrecto(string solucion){
    return true;
}
Ejercicio::~Ejercicio(){
    
}