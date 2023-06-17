#pragma once
#ifndef _DTESTADISTICACURSO
#define _DTESTADISTICACURSO

#include <string>
#include "Curso.h"
#include "Idioma.h"

using namespace std;

class Leccion;
class Inscripcion;
class Idioma;

class DTEstadisticaCurso {
 private:
    string Nombre;
    string Descripcion;
    EnumDificultad Dificultad;
    Idioma* Idioma;
    string Profesor;
    string Habilitacion;
    set<Leccion*> Lecciones;
    set<Inscripcion*> Inscripciones;
    int Avance;
 public:
    DTEstadisticaCurso();
    DTEstadisticaCurso(string Nombre, string Descripcion, EnumDificultad Dificultad,
    Idioma* idioma, string Profesor, string Habilitacion, set<Leccion*> Lecciones,
    set<Inscripcion*> Inscripciones, int Avance);
    string getNombreCurso();
    string getDescripcionCurso();
    EnumDificultad getDificultad();
    Idioma* getIdioma();
    string getProfesor();
    string getHabilitacion();
    set<Leccion> getLecciones();
    set<Inscripcion> getInscripciones();
    int getAvance();
};

#include "Leccion.h"
#include "Inscripcion.h"

#endif