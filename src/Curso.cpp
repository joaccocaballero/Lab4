#include <string>
#include <set>
#include <iostream>
#include "../include/Leccion.h"
#include "../include/DTEstadisticaCurso.h"
#include "../include/Curso.h"

using namespace std;


Curso::Curso(bool habilitacion, string nombre, string descripcion, EnumDificultad dificultad,set<Curso*> cursosPrevios, Idioma *idioma, set<Leccion*> lecciones){
    this->habilitacion = habilitacion;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->dificultad = dificultad;
    this->IdiomaEnseniado = idioma;
    this->cursosPrevios = cursosPrevios;
    this->Lecciones = lecciones;
}

string Curso::obtenerNombre(){
    return nombre;
 }

bool Curso::obtenerHabilitacion(){
    return habilitacion;
}

set<Leccion*> Curso::obtenerLecciones(){
    return Lecciones;
}

set<string> Curso::obtenerEjerciciosPendientes(string nombre){
    nombre= "";
    set<string> ejercicios;
    return ejercicios;
}

Leccion* Curso::obtenerLeccion(string temaLeccion){
    auto it = std::find_if(Lecciones.begin(), Lecciones.end(), [&](Leccion* obj) {
      return obj->obtenerTema() == temaLeccion;
    });
    if (it != Lecciones.end()) {
      // Object found
       Leccion* leccion = *it;
       return leccion;
    } else {
      // Object not found
      std::cout << "Leccion no encontrada!" << std::endl;
    }
}


void Curso::agregarLeccion(Leccion* l){
    Lecciones.insert(l);
}

DTEstadisticaCurso* Curso::obtenerEstadisticaCurso(string nombre){
    /*nombre= "";
    set<Inscripcion> inscriptos;
    set<Leccion*> lecciones = obtenerLecciones();
    int avance = 10;
    DTEstadisticaCurso* estadisticas = new DTEstadisticaCurso("a","a",Principiante,"idioma", "profe", "false", lecciones, inscriptos, avance);
    return estadisticas;*/
}

Curso::~Curso(){
}