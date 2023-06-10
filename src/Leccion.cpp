
#include <string>
#include <set>
#include "../include/Leccion.h"
#include "../include/DTEjercicio.h"
#include "../include/Ejercicio.h"


Leccion::Leccion(string tema, string objetivo, set<Ejercicio*> Ejercicios){
    this->tema = tema;
    this->objetivo = objetivo;
    this->Ejercicios = Ejercicios;
}

string Leccion::obtenerTema(){
    return tema;
}

string Leccion::obtenerObjetivo(){ 
    return objetivo; 
}

set<Ejercicio> Leccion::obtenerEjercicios(){
    set<Ejercicio> ejercicio;
    return ejercicio;
}
set<string> Leccion::obtenerEjerciciosPendientes(){
    set<string> string;
    return string;
}
set<Ejercicio*> Leccion::obtenerEjerciciosLeccion(){
    return Ejercicios;
}

Leccion::~Leccion(){}