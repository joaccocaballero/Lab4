#pragma once
#ifndef _DTCURSO
#define _DTCURSO

#include <string>
#include "Curso.h"

using namespace std;

class Leccion;
class Inscripcion;

class DTCurso {
 private:
    string Nombre;
    string Descripcion;
    EnumDificultad Dificultad;
    string Idioma;
    string Profesor;
    string Habilitacion;
    set<DTLeccion> Lecciones;
    set<DTInscripcion> Inscripciones;
 public:
    DTCurso();
    DTCurso(string Nombre, string Descripcion, EnumDificultad Dificultad,
    string Idioma, string Profesor, string Habilitacion, set<DTLeccion> Lecciones,
    set<DTInscripcion> Inscripciones);
    string getNombreCurso();
    string getDescripcionCurso();
    EnumDificultad getDificultad();
    string getIdioma();
    string getProfesor();
    string getHabilitacion();
    set<DTLeccion> getLecciones();
    set<DTInscripcion> getInscripciones();
};

#include "Leccion.h"
#include "Inscripcion.h"

#endif