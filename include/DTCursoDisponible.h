#pragma once
#ifndef DTCURSODISPONIBLE
#define DTCURSODISPONIBLE

#include <string>
#include "Curso.h"

using namespace std;


class DTCursoDisponible {
    private:
        string nombre;
        string descripcion;
        EnumDificultad dificultad;
        string idioma;
        string profesor;
        int ctdLecciones;
        int ctdEjercicios;
    public:
        DTCursoDisponible();
        DTCursoDisponible(string nombre, string descripcion, string idioma, string profesor, int ctdLecciones, int ctdEjercicios, EnumDificultad dificultad);
        string getNombre();
        string getDescripcion();
        string getIdioma();
        string getProfesor();
        int getLecciones();
        int getEjercicios();
        EnumDificultad getDificultad();
};

#endif