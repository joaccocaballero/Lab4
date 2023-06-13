#pragma once
#ifndef _DTCURSO
#define _DTCURSO

#include <string>
#include "Curso.h"
#include "DTLeccion.h"
#include  "DTInscripcion.h"

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
    bool Habilitacion;
    set<DTLeccion> Lecciones;
    set<DTInscripcion> Inscripciones;
 public:
    DTCurso();
    DTCurso(string Nombre, string Descripcion, EnumDificultad Dificultad,
    string Idioma, string Profesor, bool Habilitacion, set<DTLeccion> Lecciones,
    set<DTInscripcion> Inscripciones);
    string getNombreCurso();
    string getDescripcionCurso();
    EnumDificultad getDificultad();
    string getIdioma();
    string getProfesor();
    bool getHabilitacion();
    set<DTLeccion> getLecciones();
    set<DTInscripcion> getInscripciones();
};

#include "Leccion.h"
#include "Inscripcion.h"

#endif