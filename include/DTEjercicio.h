#pragma once
#ifndef _DTEJERCICIO
#define _DTEJERCICIO

#include <string>
using namespace std;

class DTEjercicio{
    private:
        string NombreEjercicio;
    public:
        DTEjercicio(string NombreEjercicio);
        string getNombreEjercicio();
};

#endif