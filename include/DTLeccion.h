#pragma once
#ifndef _DTLECCION
#define _DTLECCION

#include <string>
#include <set>
#include "Ejercicio.h"
#include "DTEjercicio.h"
using namespace std;

class DTLeccion {
    private:
        string tema;
        string objetivo;
        set<DTEjercicio*> Ejercicios;
    public:
        DTLeccion(string tema, string objetivo, set<DTEjercicio*> ejercicios);
        set<DTEjercicio> obtenerEjercicios();
        string obtenerTema();
        string obtenerObjetivo();
        virtual ~DTLeccion();
};

#endif