#include <string>
#include "../include/DTEjercicio.h"

using namespace std;

DTEjercicio::DTEjercicio() {}

DTEjercicio::DTEjercicio(int id, string descripcion, string consigna, EnumEjercicios tipo){
    this->id = id;
    this->consigna = consigna;
    this->descripcion = descripcion;
    this->tipo = tipo;
}
string DTEjercicio::getDescripcionEjercicio(){
    return descripcion;
}

EnumEjercicios DTEjercicio::getTipoEjercicio(){
    return tipo;
}

string DTEjercicio::getConsignaEjercicio(){
    return consigna;
}

int DTEjercicio::getId(){
    return id;
}