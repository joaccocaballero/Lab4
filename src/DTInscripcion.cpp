#include "../include/DTInscripcion.h"

DTInscripcion::DTInscripcion(int id, DTFecha fecha,string nombre){
    this->id = id;
    this->Fecha = fecha;
    this->Nombre = nombre;
}

int DTInscripcion::obtenerIdInscripcion(){
    return id;
}
DTFecha DTInscripcion::obtenerFecha(){
    return Fecha;
}
string DTInscripcion::obtenerNombre(){
    return Nombre;
}
