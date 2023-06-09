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
#include "../include/DTEjercicio.h"
#include "../include/Ejercicio.h"


Leccion::Leccion(string tema, string objetivo, bool aprobacion):tema(tema),objetivo(objetivo),aprobacion(aprobacion){
}

set<Ejercicio> Leccion::obtenerEjercicios(){
    set<Ejercicio> ejercicio;
    return ejercicio;
}
set<string> Leccion::obtenerEjerciciosPendientes(){
    set<string> string;
    return string;
}
set<Ejercicio*> Leccion::obtenerEjerciciosLeccion(){
    return Ejercicios;
}

Leccion::~Leccion(){}