#include "../include/Traducir.h"
#include <string>

using namespace std;

Traducir::Traducir(int id, string consigna, string descripcion,
                   EnumEjercicios tipo
                    , string solucion) : 
                   Ejercicio(id,consigna,descripcion,tipo){
    this->solucion = solucion;
}

bool Traducir::esCorrecto(string sol) { return sol == solucion; }

Traducir::~Traducir(){};