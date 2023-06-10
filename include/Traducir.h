#pragma once
#ifndef _TRADUCIR
#define _TRADUCIR

#include <set>
#include <string>

#include "Ejercicio.h"
using namespace std;

class Traducir: public Ejercicio {
    private: 
        string solucion;
    public:
        Traducir(int id, string consigna,string descripcion, EnumEjercicios tipo, string solucion);
        bool esCorrecto(string sol);
        ~Traducir();
        
};

#endif