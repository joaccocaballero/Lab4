//     public:
//         string tema{}
//         string objetivo;
//         bool aprobacion;
//         set<Ejercicio*> Ejercicios;

//     private:
//         Leccion(string tema, string objetivo, bool aprobacion);
//         set<Ejercicio> obtenerEjercicios();
//         set<string> obtenerEjerciciosPendientes();
//         DTEjercicio obtenerEjerciciosLeccion(int id, l Leccion);
//         ~Leccion()
// }
#include <string>
#include <set>
#include "../include/Leccion.h"


Leccion Leccion::Leccion(string tema, string objetivo, bool aprobacion):tema(tema),objetivo(objetivo),aprobacion(aprobacion){
}

set<Ejercicio> Leccion::obtenerEjercicios(){
    set<Ejercicio> ejercicio;
    return ejercicio;
}
set<string> Leccion::obtenerEjerciciosPendientes(){
    set<string> string;
    return string;
}
DTEjercicio Leccion::obtenerEjerciciosLeccion(int id, l Leccion){
    DTEjercicio ejercicio = new DTEjercicio("sa");
    return ejercicio
}

Leccion::~Leccion(){}