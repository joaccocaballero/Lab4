#pragma once
#ifndef _CURSO
#define _CURSO

#include <algorithm>
#include <set>
#include <string>
#include <vector>

#include "Idioma.h"
#include "Leccion.h"
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
    public:
        Curso(bool habilitacion, string nombre, string descripcion, EnumDificultad dificultad, set<Curso*> cursosPrevios, Idioma *idioma, set<Leccion*> lecciones);
        string obtenerNombre();
        set<Leccion*> obtenerLecciones();
        Leccion* obtenerLeccion(string nomLeccion);
        set<string> obtenerEjerciciosPendientes(string nombre);
        bool obtenerHabilitacion();
        
        void setHabilitacion(bool h);
        void agregarLeccion(Leccion *l);
        DTEstadisticaCurso* obtenerEstadisticaCurso(string nombre);
        ~Curso();
};

#include "DTEstadisticaCurso.h"

#endif