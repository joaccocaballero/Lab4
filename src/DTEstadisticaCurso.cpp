#include <string>
#include "../include/DTEstadisticaCurso.h"
#include "../include/Leccion.h"
#include "../include/Inscripcion.h"

using namespace std;

DTEstadisticaCurso::DTEstadisticacurso(string Nombre, string Descripcion, EnumDificultad Dificultad,
        string Idioma, string Profesor, string Habilitacion, set<Leccion> Lecciones,
        set<Inscripcion> Inscripciones, integer Avance){
    this->Nombre = Nombre;
    this->Desrcipcion = Descripcion;
    this->Dificultad = Dificultad;
    this->Idioma = Idioma;
    this->Profesor = Profesor;
    this->Habilitacion = Habilitacion,
    this->Lecciones = Lecciones,
    this->Inscripciones = Inscripciones,
    this->Avance = Avance            
}
string getNombreCurso(){
    return this->Nombre;
}
string getDescripcionCurso(){
    return this->Descripcion;
}
EnumDificultad getDificultad(){
    return this->Dificultad;
}
string getIdioma(){
    return this->Idioma;
}
string getProfesor(){
    return this->Profesor;
}
string getHabilitacion(){
    return this->Habilitacion;
}
set<Leccion> getLecciones(){
    return this->Lecciones;
}
set<Inscripcion> getInscripciones(){
    return this->Inscripciones;
}
integer getAvance(){
    return this->Nombre;
}
