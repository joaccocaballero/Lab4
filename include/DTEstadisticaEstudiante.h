#pragma once
#ifndef _DTESTADISTICAESTUDIANTE
#define _DTESTADISTICAESTUDIANTE

#include <string>
using namespace std;

class DTEstadisticaEstudiante {
    private:
        string curso;
        int Avance;
    public: 
        DTEstadisticaEstudiante(string curso, int avance);
        string getNombreCurso();
        int getAvance();
        bool operator<(const DTEstadisticaEstudiante& dt) const {
            return Avance < dt.Avance;
        }
};

#endif