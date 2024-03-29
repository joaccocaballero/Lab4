#include <string>
#include <set>
#include <iostream>
#include "../include/Leccion.h"
#include "../include/Curso.h"
#include "../include/DTLeccion.h"
#include "../include/DTInscripcion.h"
#include "../include/DTEstadisticaProfesor.h"


using namespace std;


Curso::Curso(bool habilitacion, string nombre, string descripcion, EnumDificultad dificultad, set<Curso*> cursosPrevios, Idioma *idioma, set<Leccion*> lecciones, string nombreProf, set<Inscripcion*> colInscripciones){
    this->habilitacion = habilitacion;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->dificultad = dificultad;
    this->IdiomaEnseniado = idioma;
    this->cursosPrevios = cursosPrevios;
    this->Lecciones = lecciones;
    this->nombreProf = nombreProf;
    this->inscripciones = colInscripciones;
    this->EstadisticaProfesor = DTEstadisticaProfesor("asd", 0);
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

int Curso::getCantidadLecciones(){
    return Lecciones.size();
}

void Curso::eliminarCursoPrevio(Curso * curso){
    cursosPrevios.erase(curso);
}

bool Curso::esPrevio(Curso *c){
    if(cursosPrevios.count(c)){
        return true;
    } 
    else{
        return false;
    }
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

DTEstadisticaCurso Curso::obtenerEstadisticaCurso(){
    int avance = 0;
    int Promedio = 0;
    std::set<Inscripcion*>::iterator it;
    cout << "Seleccione un Profesor: "<< endl;
    int cantidad = inscripciones.size();
    for (it= inscripciones.begin(); it!=inscripciones.end(); ++it) {
        Inscripcion* current = *it;
        DTEstadisticaEstudiante estudianteInscripto = current->crearEstadisticaEstudiante();
        avance += estudianteInscripto.getAvance();
    }
    if(cantidad != 0 ){
        Promedio = avance/cantidad*100;
    }
    else {
        Promedio = 0;
    }
    DTEstadisticaCurso estadistica = DTEstadisticaCurso(nombre, descripcion, dificultad, IdiomaEnseniado, nombreProf, HabilitacionToString(), Lecciones, inscripciones, Promedio);
    return estadistica;
}

DTEstadisticaProfesor Curso::obtenerEstadisticasProfesor(){
    string nombreCurso = nombre;
    int avance = 0;
    int promedio = 0;
    int cantidad = inscripciones.size();
    set<Inscripcion*>::iterator it;
    for (it= inscripciones.begin(); it!=inscripciones.end(); ++it) {
        Inscripcion* current = *it;
        DTEstadisticaEstudiante estudianteInscripto = current->crearEstadisticaEstudiante();
        avance += estudianteInscripto.getAvance();
    }
    if(cantidad != 0 ){
        promedio = static_cast<int>(avance/cantidad*100);
    }
    else {
        promedio = 0;
    }
    DTEstadisticaProfesor retorno = DTEstadisticaProfesor(nombreCurso, promedio);
    this->EstadisticaProfesor = retorno;
    return retorno;
}

string Curso::HabilitacionToString(){
    if (habilitacion) return "Hablitado";
    return "No habilitado";
}

Curso::~Curso(){
    set<Inscripcion*>::iterator itInscripcion;
    for (auto itInscripcion = inscripciones.begin();
         itInscripcion != inscripciones.end(); ++itInscripcion) {
        delete *itInscripcion;
    }
    inscripciones.clear();
    

    set<Leccion*>::iterator itLeccion;
    for (auto itLeccion = Lecciones.begin(); itLeccion != Lecciones.end(); ++itLeccion) {
        delete *itLeccion;
    }
    Lecciones.clear();
    cursosPrevios.clear();

}