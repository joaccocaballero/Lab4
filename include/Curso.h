#pragma once
#ifndef _CURSO
#define _CURSO

#include <string>
#include <set>
#include "Leccion.h"
#include "Idioma.h"
using namespace std;

class DTEstadisticaCurso;

enum EnumDificultad { Principiante, Medio, Avanzado };

class Curso {
    private:
        bool habilitacion;
        string nombre;
        string descripcion;
        EnumDificultad dificultad;
        Idioma * IdiomaEnseniado;
        set<Leccion*> Lecciones;
        set<Curso*> cursosPrevios;
    public:
        Curso(bool habilitacion, string nombre, string descripcion, EnumDificultad dificultad, set<Curso*> cursosPrevios, Idioma idioma);
        string obtenerNombre();
        set<Leccion> obtenerLecciones();
        set<string> obtenerEjerciciosPendientes(string nombre);
        DTEstadisticaCurso* obtenerEstadisticaCurso(string nombre);
        ~Curso();
};

#include "DTEstadisticaCurso.h"

#endif