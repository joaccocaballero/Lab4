
#include <string>
#include <set>
#include "../include/Leccion.h"
#include "../include/DTEjercicio.h"
#include "../include/Ejercicio.h"


Leccion::Leccion(string tema, string objetivo, set<Ejercicio*> ejercicios){
    this->tema = tema;
    this->objetivo = objetivo;
    this->Ejercicios = ejercicios;
}

string Leccion::obtenerTema(){
    return tema;
}

string Leccion::obtenerObjetivo(){ 
    return objetivo; 
}

void Leccion::agregarEjercicio(Ejercicio * e){
    Ejercicios.insert(e);
}

set<DTEjercicio> Leccion::obtenerSetDTEjercicio(){
    set<DTEjercicio> retorno;
    set<Ejercicio*> col = obtenerEjerciciosLeccion();
    set<Ejercicio*>::iterator it;
    for (it = col.begin(); it != col.end(); ++it) {
      Ejercicio* current = *it;
      DTEjercicio e = DTEjercicio(current->obtenerId(), current->obtenerDescripcion(), current->getConsigna(),
      current->obtenerTipo());
      retorno.insert(e);
    }
    return retorno;
}

set<string> Leccion::obtenerEjerciciosPendientes(){
    set<string> string;
    return string;
}
set<Ejercicio*> Leccion::obtenerEjerciciosLeccion(){
    return Ejercicios;
}

Leccion::~Leccion(){}