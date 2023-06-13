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
        int id;
        string tema;
        string objetivo;
        set<DTEjercicio*> Ejercicios;
    public:
        DTLeccion(string tema, string objetivo, set<DTEjercicio> ejercicios);
        set<DTEjercicio> obtenerEjercicios();
        string obtenerTema();
        string obtenerObjetivo();
        bool operator<(const DTLeccion& dt) const {
          // Define la lógica de comparación basada en los atributos de la clase
          return id <=
                 dt.id;  // Por ejemplo, compara por el atributo 'id'
        }
        virtual ~DTLeccion();
};

#endif