#pragma once
#ifndef _DTUSUARIO
#define _DTUSUARIO

#include <string>

using namespace std;

class DTUsuario {
    private:
        string nombre;
        string descripcion;
    public:
        DTUsuario();
        DTUsuario(string nombre, string descripcion);
        string getNombre();
        string getDescripcion();
};

#endif