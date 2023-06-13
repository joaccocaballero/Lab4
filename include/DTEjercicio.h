#pragma once
#ifndef _DTEJERCICIO
#define _DTEJERCICIO

#include <string>
using namespace std;

class DTEjercicio{
    private:
        int id;
        string descripcion;
        EnumEjercicios tipo;
    public:
        DTEjercicio(int id, string descripcion, EnumEjercicios tipo);
        string getDescripcionEjercicio();
        EnumEjercicios getTipoEjercicio();
        int getId();
        bool operator<(const DTEjercicio& dt) const {
          // Define la lógica de comparación basada en los atributos de la clase
          return id <=
                 dt.id;  // Por ejemplo, compara por el atributo 'id'
        }
};

#endif