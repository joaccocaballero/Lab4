#include <string>
#include "../include/DTEjercicio.h"

using namespace std;


DTEjercicio::DTEjercicio(int id, string descripcion, EnumEjercicios tipo){
    this->id = id;
    this->descripcion = descripcion;
    this->tipo = tipo;
}
string DTEjercicio::getDescripcionEjercicio(){
    return descripcion;
}

EnumEjercicios DTEjercicio::getTipoEjercicio(){
    return tipo;
}

int DTEjercicio::getId(){
    return id;
}