#pragma once
#ifndef _DTESTADISTICAPROFESOR
#define _DTESTADISTICAPROFESOR

#ifndef DTESTADISTICAPROFESOR
#define DTESTADISTICAPROFESOR

#include <string>
using namespace std;

class DTEstadisticaProfesor{
    private:
        string Curso;
        int Avance;
        int Promedio;
    public:
        DTEstadisticaProfesor(string Curso, int Avance, int Promedio);
        string getNombreCurso();
        int getAvance();
        int getPromedio();

};

#endif