#include <string>
#include <set>
#include <iostream>
#include "../include/Leccion.h"
#include "../include/DTEstadisticaCurso.h"
#include "../include/Curso.h"
#include "../include/DTLeccion.h"
#include "../include/DTInscripcion.h"

using namespace std;


Curso::Curso(bool habilitacion, string nombre, string descripcion, EnumDificultad dificultad,set<Curso*> cursosPrevios, Idioma *idioma, set<Leccion*> lecciones, string nombreProf,
set<Inscripcion*> colInscripciones){
    this->habilitacion = habilitacion;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->dificultad = dificultad;
    this->IdiomaEnseniado = idioma;
    this->cursosPrevios = cursosPrevios;
    this->Lecciones = lecciones;
    this->nombreProf = nombreProf;
    this->inscripciones = inscripciones;
}

string Curso::obtenerNombre(){
    return nombre;
 }

bool Curso::obtenerHabilitacion(){
    return habilitacion;
}

Idioma* Curso::getIdioma(){
    return IdiomaEnseniado;
}

void Curso::setHabilitacion(bool h){
    habilitacion=h;
}

set<Leccion*> Curso::obtenerLecciones(){
    return Lecciones;
}

string Curso::obtenerNombreProf(){
    return nombreProf;
}

string Curso::obtenerDescripcion(){
    return descripcion;
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

set<Inscripcion*> Curso::obtenerInscripciones(){
    return inscripciones;
}


void Curso::agregarLeccion(Leccion* l){
    Lecciones.insert(l);
}

void Curso::agregarInscripcion(Inscripcion *i){
    inscripciones.insert(i);
}

EnumDificultad Curso::obtenerDificultad(){
    return dificultad;
}

set<Curso*> Curso::obtenerPrevias(){
    return cursosPrevios;
}

set<DTLeccion> Curso::obtenerSetDTLeccion(){
    set<DTLeccion> retorno;
    set<Leccion*> col = obtenerLecciones();
    set<Leccion*>::iterator it;
    for (it=col.begin(); it!=col.end(); ++it){
        Leccion * current = *it;
        DTLeccion l = DTLeccion(current->obtenerTema(), current->obtenerObjetivo(), current->obtenerSetDTEjercicio());
        retorno.insert(l);
    }
    return retorno;
}

set<DTInscripcion> Curso::obtenerSetDTInscripcion(){
    set<DTInscripcion> retorno;
    set<Inscripcion*> col = obtenerInscripciones();
    set<Inscripcion*>::iterator it;
    for (it = col.begin(); it != col.end(); ++it) {
        Inscripcion* current = *it;
        DTInscripcion ins = DTInscripcion(current->obtenerIdInscripcion(), current->obtenerFecha(),
        current->obtenerEstudiante()->obtenerNombre());
        retorno.insert(ins);
    }
    return retorno;
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