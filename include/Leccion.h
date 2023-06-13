#pragma once
#ifndef _LECCION
#define _LECCION

#include <string>
#include <set>
#include "Ejercicio.h"
#include "DTEjercicio.h"
using namespace std;

class Leccion {
    private:
        string tema;
        string objetivo;
        set<Ejercicio*> Ejercicios;
    public:
        Leccion(string tema, string objetivo, set<Ejercicio*> ejercicios);
        string obtenerTema();
        string obtenerObjetivo();
        void agregarEjercicio(Ejercicio* e);
        set<string> obtenerEjerciciosPendientes();
        set<Ejercicio*> obtenerEjerciciosLeccion();
        virtual ~Leccion();
};

#endif