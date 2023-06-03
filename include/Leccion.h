#pragma once
#ifndef _LECCION
#define _LECCION

#include <string>
#include <set>
#include "Ejercicio.h"
#include "DTEjercicio.h"
using namespace std;

class Leccion {
    public:
        string tema;
        string objetivo;
        bool aprobacion;
        set<Ejercicio*> Ejercicios;

    private:
        Leccion(string tema, string objetivo, bool aprobacion);
        set<Ejercicio> obtenerEjercicios();
        set<string> obtenerEjerciciosPendientes();
        DTEjercicio obtenerEjerciciosLeccion(int id, Leccion l);
        ~Leccion();
};

#endif