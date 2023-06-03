#ifndef LECCION
#define LECCION

#include <string>
#include <set>
#include "Ejercicio.h"
using namespace std;

class Leccion {
    public:
        string tema;
        string objetivo;
        bool aprobacion;
        set<Ejercicio*> Ejercicios;

    private:
        Leccion(string tema, string objetivo, bool aprobacion);
        set<Ejercicio> obtenerEjercicios();
        set<string> obtenerEjerciciosPendientes();
        DTEjercicio obtenerEjerciciosLeccion(int id, l Leccion);
        ~Leccion()
};

#endif