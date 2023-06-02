#include <string>
#include "../include/Leccion.h"
#include "../include/DTEstadisticaCurso.h"
#include "../include/Curso.h"

using namespace std;

/*enum EnumDificultad { Principiante, Medio, Avanzado };

class Curso {
    private:
        bool habilitacion;
        string nombre;
        string descripcion;
        EnumDificultad dificultad;
    public:
        Curso(bool habilitacion, string nombre, string descripcion, EnumDificultad dificultad);
        string obtenerNombre();
        set<Leccion> obtenerLecciones();
        set<string> obtenerEjerciciosPendientes(string nombre);
        DTEstadisticaCurso obtenerEstadisticaCurso(string nombre);
        ~Curso()
}*/

 Curso::Curso(bool habilitacion, string nombre, string descripcion, EnumDificultad dificultad):habilitacion(habilitacion),nombre(nombre),descripcion(descripcion),dificultad(dificultad) {}

 string Curso::obtenerNombre(){}

 set<Leccion> Curso::obtenerLecciones(){}

 set<string> Curso::obtenerEjerciciosPendientes(string nombre){}

DTEstadisticaCurso Curso::obtenerEstadisticaCurso(string nombre){}

Curso::~Curso(){}