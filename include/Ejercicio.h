#pragma once
#ifndef _EJERCICIO
#define _EJERCICIO

#include <string>

using namespace std;

enum EnumEjercicios {TraducirFrase, CompletarPalabras};

class Ejercicio {
    private:
        int id;
        string consigna;
        string descripcion;
        EnumEjercicios tipo;
    public:
        Ejercicio(int id, string consigna, string descripcion, EnumEjercicios tipo);
        string getConsigna();
        int obtenerId();
        void setId(int identifier);
        EnumEjercicios obtenerTipo();
        string obtenerDescripcion();
        virtual bool esCorrecto(string solucion);
        virtual ~Ejercicio();
};

#endif