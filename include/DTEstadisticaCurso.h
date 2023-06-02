
#include <string>
#include "Leccion.h"
#include "Inscripcion.h"
using namespace std;
enum EnumDificultad { Principiante, Medio, Avanzado };

class DTEstadisticaCurso {
 private:
    string Nombre;
    string Descripcion;
    EnumDificultad Dificultad;
    string Idioma;
    string Profesor;
    string Habilitacion;
    set<DTLeccion> Lecciones;
    set<DTInscripcion> Inscripciones;
    integer Avance;
 public:
    DTEstadisticaCurso(string Nombre, string Descripcion, EnumDificultad Dificultad,
        string Idioma, string Profesor, string Habilitacion, set<Leccion> Lecciones,
        set<Inscripcion> Inscripciones, integer Avance);
    string getNombreCurso();
    string getDescripcionCurso();
    EnumDificultad getDificultad();
    string getIdioma();
    string getProfesor();
    string getHabilitacion();
    set<Leccion> getLecciones();
    set<Inscripcion> getInscripciones();
    integer getAvance();
    }