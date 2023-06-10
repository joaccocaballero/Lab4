#pragma once
#ifndef _DTProfesor
#define _DTProfesor

#include <string>
#include <set>

#include "DTUsuario.h"

using namespace std;

class DTProfesor: public DTUsuario{
    private:
        string nombreInstituto;
        set<string> listaIdiomas;
    public:
        DTProfesor();
        DTProfesor(string nombre, string descripcion, string nombreInstituto, set<string> listaIdiomas);
        string getNombreString();
        string getDescripcionString();
        string getInstituto();
        set<string> getIdiomas();

};

#endif