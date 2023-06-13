#include <string>
#include "../include/DTCurso.h"
#include "../include/Leccion.h"
#include "../include/Inscripcion.h"

using namespace std;

DTCurso::DTCurso(string Nombre, string Descripcion, EnumDificultad Dificultad,
        string Idioma, string Profesor, bool Habilitacion, set<DTLeccion> Lecciones,
        set<DTInscripcion> Inscripciones){
    this->Nombre = Nombre;
    this->Descripcion = Descripcion;
    this->Dificultad = Dificultad;
    this->Idioma = Idioma;
    this->Profesor = Profesor;
    this->Habilitacion = Habilitacion;
    this->Lecciones = Lecciones;
    this->Inscripciones = Inscripciones;
}
string DTCurso::getNombreCurso(){
    return Nombre;
}
string DTCurso::getDescripcionCurso(){
    return Descripcion;
}
EnumDificultad DTCurso::getDificultad(){
    return Dificultad;
}
string DTCurso::getIdioma(){
    return Idioma;
}
string DTCurso::getProfesor(){
    return Profesor;
}
bool DTCurso::getHabilitacion(){
    return Habilitacion;
}
set<DTLeccion> DTCurso::getLecciones(){
    return Lecciones;
}
set<DTInscripcion> DTCurso::getInscripciones(){
    return Inscripciones;
}