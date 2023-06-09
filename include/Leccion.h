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
        bool aprobacion;
        set<Ejercicio*> Ejercicios;

    public:
        Leccion(string tema, string objetivo, bool aprobacion);
        set<Ejercicio> obtenerEjercicios();
        set<string> obtenerEjerciciosPendientes();
        set<Ejercicio*> obtenerEjerciciosLeccion();
        virtual ~Leccion();
};

#endif