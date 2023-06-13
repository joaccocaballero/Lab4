#pragma once
#ifndef _CURSO
#define _CURSO

#include <algorithm>
#include <set>
#include <string>
#include <vector>

#include "Idioma.h"
#include "Leccion.h"
#include "Inscripcion.h"
#include "DTLeccion.h"
#include "DTInscripcion.h"

using namespace std;

class DTEstadisticaCurso;

enum EnumDificultad { Principiante, Medio, Avanzado };

class Curso {
    private:
        bool habilitacion;
        string nombre;
        string descripcion;
        EnumDificultad dificultad;
        Idioma* IdiomaEnseniado;
        set<Leccion*> Lecciones;
        set<Curso*> cursosPrevios;
        set<Inscripcion*> inscripciones;
        string nombreProf;
    public:
        Curso(bool habilitacion, string nombre, string descripcion, EnumDificultad dificultad, set<Curso*> cursosPrevios, Idioma *idioma, set<Leccion*> lecciones, string nombreProf,
        set<Inscripcion*> colInscripciones);
        string obtenerNombre();
        set<Leccion*> obtenerLecciones();
        Leccion* obtenerLeccion(string nomLeccion);
        set<string> obtenerEjerciciosPendientes(string nombre);
        Idioma* getIdioma();
        bool obtenerHabilitacion();
        void setHabilitacion(bool h);
        void agregarLeccion(Leccion *l);
        void agregarInscripcion(Inscripcion *i);
        string obtenerDescripcion();
        EnumDificultad obtenerDificultad();
        string obtenerNombreProf();
        set<Curso*> obtenerPrevias();
        set<Inscripcion*> obtenerInscripciones();
        set<DTLeccion> obtenerSetDTLeccion();
        set<DTInscripcion> obtenerSetDTInscripcion();
        DTEstadisticaCurso* obtenerEstadisticaCurso(string nombre);
        ~Curso();
};

#include "DTEstadisticaCurso.h"

#endif