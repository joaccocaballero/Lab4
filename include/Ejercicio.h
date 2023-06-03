#pragma once
#ifndef _EJERCICIO
#define _EJERCICIO

#include <string>

using namespace std;

enum EnumEjercicios {Traducir, CompletarFrase};

class Ejercicio {
    public:
        int id;
        string consigna;
        EnumEjercicios tipo;
        bool aprobacion;
    private:
        Ejercicio(int id, string consigna, EnumEjercicios tipo, bool aprobacion);
        string getNombre();
        EnumEjercicios obtenerTipo();
        virtual bool esCorrecto();
        virtual ~Ejercicio();
};

#endif