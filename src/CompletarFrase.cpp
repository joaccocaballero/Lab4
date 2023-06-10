#include "../include/CompletarFrase.h"
#include <string>
using namespace std;

CompletarFrase::CompletarFrase(int id, string consigna, string descripcion,EnumEjercicios tipo, string sol)
 : Ejercicio(id,consigna,descripcion,tipo){
    this->solucion = sol;
}

bool CompletarFrase::esCorrecto(string sol){
    return sol == solucion;
}

CompletarFrase::~CompletarFrase(){};