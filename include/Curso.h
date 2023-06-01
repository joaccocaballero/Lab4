#include <string>
#include "Leccion.h"
#include "DTEstadisticaCurso.h"
using namespace std;

enum EnumDificultad { Principiante, Medio, Avanzado };

class Curso {
    private:
        bool habilitacion;
        string descripcion;
        EnumDificultad dificultad;
    public:
        Curso(bool habilitacion, string descripcion, EnumDificultad dificultad);
        string obtenerNombre();
        set<Leccion> obtenerLecciones();
        set<string> obtenerEjerciciosPendientes(string nombre);
        DTEstadisticaCurso obtenerEstadisticaCurso(string nombre);
        ~Curso()
}