#include <string>
#include "../include/DTEstadisticaCurso.h"
#include "../include/Leccion.h"
#include "../include/Inscripcion.h"
#include "../include/Idioma.h"

using namespace std;

DTEstadisticaCurso::DTEstadisticaCurso(string Nombre, string Descripcion, EnumDificultad Dificultad,
        Idioma* idioma, string Profesor, string Habilitacion, set<Leccion*> Lecciones,
        set<Inscripcion*> Inscripciones, int Avance){
    this->Nombre = Nombre;
    this->Descripcion = Descripcion;
    this->Dificultad = Dificultad;
    this->Idioma = idioma;
    this->Profesor = Profesor;
    this->Habilitacion = Habilitacion,
    this->Lecciones = Lecciones,
    this->Inscripciones = Inscripciones,
    this->Avance = Avance;            
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
Idioma* DTEstadisticaCurso::getIdioma(){
    return Idioma;
}
string DTEstadisticaCurso::getProfesor(){
    return Profesor;
}
string DTEstadisticaCurso::getHabilitacion(){
    return Habilitacion;
}
set<Leccion*> DTEstadisticaCurso::getLecciones(){
    return Lecciones;
}
set<Inscripcion*> DTEstadisticaCurso::getInscripciones(){
    return Inscripciones;
}
int DTEstadisticaCurso::getAvance(){
    return Avance;
}
