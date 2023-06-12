
#include <string>
#include <set>
#include "../include/Leccion.h"
#include "../include/DTEjercicio.h"
#include "../include/Ejercicio.h"


Leccion::DTLeccion(string tema, string objetivo, set<DTEjercicio*> ejercicios){
    this->tema = tema;
    this->objetivo = objetivo;
    this->Ejercicios = ejercicios;
}

string DTLeccion::obtenerTema(){
    return tema;
}

string DTLeccion::obtenerObjetivo(){ 
    return objetivo; 
}

set<Ejercicio> DTLeccion::obtenerDTEjercicios(){
    set<Ejercicio> ejercicio;
    return ejercicio;
}


Leccion::~DTLeccion(){}