#include <string>
#include <set>
#include "../include/Leccion.h"
#include "../include/DTEstadisticaCurso.h"
#include "../include/Curso.h"

using namespace std;


Curso::Curso(bool habilitacion, string nombre, string descripcion, EnumDificultad dificultad,set<Curso*> cursosPrevios, Idioma *idioma){
    this->habilitacion = habilitacion;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->dificultad = dificultad;
    this->IdiomaEnseniado = idioma;
    this->cursosPrevios = cursosPrevios;
}

string Curso::obtenerNombre(){
    return this->nombre;
 }

set<Leccion> Curso::obtenerLecciones(){
    set<Leccion> lecciones;
    return lecciones;
 }

set<string> Curso::obtenerEjerciciosPendientes(string nombre){
    nombre= "";
    set<string> ejercicios;
    return ejercicios;
}

DTEstadisticaCurso* Curso::obtenerEstadisticaCurso(string nombre){
    nombre= "";
    set<Inscripcion> inscriptos;
    set<Leccion> lecciones = this->obtenerLecciones();
    int avance = 10;
    DTEstadisticaCurso* estadisticas = new DTEstadisticaCurso("a","a",Principiante,"idioma", "profe", "false", lecciones, inscriptos, avance);
    return estadisticas;
}

Curso::~Curso(){
}