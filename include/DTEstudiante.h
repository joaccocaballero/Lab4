#pragma once
#ifndef _DTUsuario
#define _DTUsuario

#include <string>

#include "DTUsuario.h"
#include <set>

using namespace std;

class DTEstudiante: public DTUsuario{
    private:
        string paisResidencia;
    public:
        DTEstudiante();
        DTEstudiante(string nombre, string descripcion, string paisResidencia);
        string getNombreString();
        string getPaisResidencia();
        string getDescripcionString();

};

#endif