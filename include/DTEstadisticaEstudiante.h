#pragma once
#ifndef _DTESTADISTICAESTUDIANTE
#define _DTESTADISTICAESTUDIANTE

#include <string>
using namespace std;

class DTEstadisticaEstudiante {
    private:
        string Curso;
        int Avance;
    public: 
        DTEstadisticaEstudiante(string Curso, int avance);
        string getNombreCurso();
        int getAvance();
};

#endif