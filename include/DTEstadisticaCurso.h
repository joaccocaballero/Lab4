#pragma once
#ifndef _DTESTADISTICACURSO
#define _DTESTADISTICACURSO

#include <string>
#include "Curso.h"

using namespace std;

class Leccion;
class Inscripcion;

class DTEstadisticaCurso {
 private:
    string Nombre;
    string Descripcion;
    EnumDificultad Dificultad;
    string Idioma;
    string Profesor;
    string Habilitacion;
    set<Leccion> Lecciones;
    set<Inscripcion> Inscripciones;
    int Avance;
 public:
    DTEstadisticaCurso();
    DTEstadisticaCurso(string Nombre, string Descripcion, EnumDificultad Dificultad,
    string Idioma, string Profesor, string Habilitacion, set<Leccion> Lecciones,
    set<Inscripcion> Inscripciones, int Avance);
    string getNombreCurso();
    string getDescripcionCurso();
    EnumDificultad getDificultad();
    string getIdioma();
    string getProfesor();
    string getHabilitacion();
    set<Leccion> getLecciones();
    set<Inscripcion> getInscripciones();
    int getAvance();
};

#include "Leccion.h"
#include "Inscripcion.h"

#endif