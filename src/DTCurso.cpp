#include <string>
#include "../include/DTEstadisticaCurso.h"
#include "../include/Leccion.h"
#include "../include/Inscripcion.h"

using namespace std;

DTEstadisticaCurso::DTEstadisticaCurso(string Nombre, string Descripcion, EnumDificultad Dificultad,
        string Idioma, string Profesor, string Habilitacion, set<DTLeccion> Lecciones,
        set<DTInscripcion> Inscripciones){
    this->Nombre = Nombre;
    this->Descripcion = Descripcion;
    this->Dificultad = Dificultad;
    this->Idioma = Idioma;
    this->Profesor = Profesor;
    this->Habilitacion = Habilitacion,
    this->Lecciones = Lecciones,
    this->Inscripciones = Inscripciones
}
string DTEstadisticaCurso::getNombreCurso(){
    return Nombre;
}
string DTEstadisticaCurso::getDescripcionCurso(){
    return Descripcion;
}
EnumDificultad DTEstadisticaCurso::getDificultad(){
    return Dificultad;
}
string DTEstadisticaCurso::getIdioma(){
    return Idioma;
}
string DTEstadisticaCurso::getProfesor(){
    return Profesor;
}
string DTEstadisticaCurso::getHabilitacion(){
    return Habilitacion;
}
set<DTLeccion> DTEstadisticaCurso::getLecciones(){
    return Lecciones;
}
set<DTInscripcion> DTEstadisticaCurso::getInscripciones(){
    return Inscripciones;
}