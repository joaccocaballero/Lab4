#pragma once
#ifndef _DTESTADISTICAPROFESOR
#define _DTESTADISTICAPROFESOR

#include <string>
using namespace std;

class DTEstadisticaProfesor{
    private:
        string curso;
        int Promedio;
    public:
        DTEstadisticaProfesor();
        DTEstadisticaProfesor(string curso, int Promedio);
        string getNombreCurso();
        int getPromedio();
        bool operator<(const DTEstadisticaProfesor& dt) const {
            return Promedio < dt.Promedio;
        }
};

#endif