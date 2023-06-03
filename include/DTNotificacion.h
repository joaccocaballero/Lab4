#pragma once
#ifndef _DTNOTIFICACION
#define _DTNOTIFICACION

#include <string>
using namespace std;

class DTNotificacion{
    private:
        string NombreCurso;
        string NombreIdioma;
    public:
        DTNotificacion(string NombreCurso, string NombreIdioma);
        string getNombreCurso();
        string getNombreIdioma();
};

#endif