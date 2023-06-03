#include <string>
#include <set>
#include "../include/Leccion.h"
#include "../include/DTEstadisticaCurso.h"
#include "../include/Curso.h"

using namespace std;


Curso::Curso(bool habilitacion, string nombre, string descripcion, EnumDificultad dificultad):habilitacion(habilitacion),nombre(nombre),descripcion(descripcion),dificultad(dificultad) {
 }

string Curso::obtenerNombre(){
    return "";
 }

set<Leccion> Curso::obtenerLecciones(){
    set<Leccion> lecciones;
    return lecciones;
 }

set<string> Curso::obtenerEjerciciosPendientes(string nombre){
    set<string> ejercicios;
    return ejercicios
}

DTEstadisticaCurso Curso::obtenerEstadisticaCurso(string nombre){
    DTEstadisticaCurso estadisticas = new DTEstadisticaCurso("a","a",1);
    return estadisticas;
}

Curso::~Curso(){
}