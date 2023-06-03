#pragma once
#ifndef _TRADUCIR
#define _TRADUCIR

#include <set>
#include <string>

#include "Ejercicio.h"
using namespace std;

class Traducir: public Ejercicio {
    public: 
        string solucion;
    private:
        Traducir(int id, string consigna, EnumEjercicios tipo, bool aprobacion, string solucion);
        virtual bool esCorrecto(string sol);
        ~Traducir();
        
};