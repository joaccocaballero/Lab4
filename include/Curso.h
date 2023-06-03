#ifndef CURSO
#define CURSO

#include <string>
#include <set>
#include "Leccion.h"
#include "Idioma.h"
#include "DTEstadisticaCurso.h"
using namespace std;

enum EnumDificultad { Principiante, Medio, Avanzado };

class Curso {
    private:
        bool habilitacion;
        string nombre;
        string descripcion;
        EnumDificultad dificultad;
        Idioma * IdiomaEnseñado;
        set<Leccion*> Lecciones;
       public:
        Curso(bool habilitacion, string nombre, string descripcion, EnumDificultad dificultad);
        string obtenerNombre();
        set<Leccion> obtenerLecciones();
        set<string> obtenerEjerciciosPendientes(string nombre);
        DTEstadisticaCurso obtenerEstadisticaCurso(string nombre);
        ~Curso()
};

#endif