#pragma once
#ifndef _CURSO
#define _CURSO

#include <algorithm>
#include <set>
#include <string>
#include <vector>

#include "Idioma.h"
#include "Leccion.h"
#include "DTLeccion.h"
#include "DTInscripcion.h"
#include "DTEstadisticaProfesor.h"
using namespace std;

enum EnumDificultad { Principiante, Medio, Avanzado };

class DTEstadisticaCurso;
class Inscripcion;


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
        DTEstadisticaProfesor EstadisticaProfesor;
        string nombreProf;
    public:
        Curso(bool habilitacion, string nombre, string descripcion, EnumDificultad dificultad, set<Curso*> cursosPrevios, Idioma* idioma, set<Leccion*> lecciones, string nombreProf, set<Inscripcion*> colInscripciones);
        string obtenerNombre();
        set<Leccion*> obtenerLecciones();
        Leccion* obtenerLeccion(string nomLeccion);
        set<string> obtenerEjerciciosPendientes(string nombre);
        Idioma* getIdioma();
        bool obtenerHabilitacion();
        bool esPrevio(Curso * c);
        void setHabilitacion(bool h);
        void agregarLeccion(Leccion *l);
        void agregarInscripcion(Inscripcion *i);
        int getCantidadLecciones();
        string obtenerDescripcion();
        EnumDificultad obtenerDificultad();
        string obtenerNombreProf();
        set<Curso*> obtenerPrevias();
        void eliminarCursoPrevio(Curso * curso);
        set<Inscripcion*> obtenerInscripciones();
        set<DTLeccion> obtenerSetDTLeccion();
        set<DTInscripcion> obtenerSetDTInscripcion();
        DTEstadisticaProfesor obtenerEstadisticasProfesor();
        DTEstadisticaCurso obtenerEstadisticaCurso();
        string HabilitacionToString();
        ~Curso();
};

#include "DTEstadisticaCurso.h"
#include "Inscripcion.h"


#endif