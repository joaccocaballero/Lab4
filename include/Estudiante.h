#include <set>
#include <string>

#include "DTFecha.h"
#include "DTEstadisticaEstudiante.h"
#include "Inscripcion.h"
using namespace std;

class Estudiante: public Usuario {
    private:
        string PaisResidencia;
        DTFecha FechaNacimiento;
        set<Inscripcion*> InscripcionesCursos;
    public:
        Estudiante(string Nickname, string Contrasenia, string Nombre, string Descripcion, string PaisResidencia, DTFecha FechaNacimiento);
        void obtenerInscripciones();
        set<DTEstadisticaEstudiante> obtenerEstadisticasEstudiante(string nickname);
        ~Estudiante();
};