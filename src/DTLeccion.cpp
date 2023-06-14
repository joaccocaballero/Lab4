
#include <string>
#include <set>
#include "../include/Leccion.h"
#include "../include/DTEjercicio.h"
#include "../include/DTLeccion.h"


DTLeccion::DTLeccion(string tema, string objetivo, set<DTEjercicio> ejercicios){
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

set<DTEjercicio> DTLeccion::obtenerEjercicios(){
    return Ejercicios;
}