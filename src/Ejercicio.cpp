#include <string>
#include "../include/Ejercicio.h"

using namespace std;

Ejercicio::Ejercicio(int id, string consigna, EnumEjercicios tipo, bool aprobacion){
    this->id = id;
    this->consigna = consigna;
    this->tipo = tipo;
    this->aprobacion = aprobacion;
}
string Ejercicio::getNombre(){
    return this->consigna;
}
EnumEjercicios Ejercicio::obtenerTipo(){
    return this->tipo;
}
bool Ejercicio::esCorrecto(){
    return true;
}
Ejercicio::~Ejercicio(){}