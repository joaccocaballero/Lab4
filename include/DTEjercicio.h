#pragma once
#ifndef _DTEJERCICIO
#define _DTEJERCICIO

#include <string>
#include "Ejercicio.h"
using namespace std;

class DTEjercicio{
    private:
        int id;
        string descripcion;
        string consigna;
        EnumEjercicios tipo;
    public:
        DTEjercicio();
        DTEjercicio(int id, string descripcion,string consigna, EnumEjercicios tipo);
        string getDescripcionEjercicio();
        string getConsignaEjercicio();
        EnumEjercicios getTipoEjercicio();
        int getId();
        bool operator<(const DTEjercicio& dt) const {
          // Define la lógica de comparación basada en los atributos de la clase
          return id <=
                 dt.id;  // Por ejemplo, compara por el atributo 'id'
        }
};

#endif