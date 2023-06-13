#pragma once
#ifndef _DTINSCRIPCION
#define _DTINSCRIPCION

#include <string>

using namespace std;

#include "DTFecha.h"

class DTInscripcion {
    private:
        int id;
        DTFecha Fecha;
        string Nombre;
    public:
        DTInscripcion(int id, DTFecha fecha, string Nombre);
        int obtenerIdInscripcion();
        string obtenerNombre();
        DTFecha obtenerFecha();
        bool operator<(const DTInscripcion& dt) const {
          // Define la lógica de comparación basada en los atributos de la clase
          return id <=
                 dt.id;  // Por ejemplo, compara por el atributo 'id'
        }
        ~DTInscripcion();
};

#include "../include/Estudiante.h"

#endif