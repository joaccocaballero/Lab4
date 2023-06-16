#ifndef ESTUDIANTE
#define ESTUDIANTE

#include <set>
#include <string>

#include "DTFecha.h"
#include "DTEstadisticaEstudiante.h"
#include "Inscripcion.h"

using namespace std;
class Inscripcion;

class Estudiante: public Usuario {
    private:
        string PaisResidencia;
        DTFecha FechaNacimiento;
        set<Inscripcion*> InscripcionesCursos;
    public:
        Estudiante(string Nickname, string Contrasenia, string Nombre, string Descripcion, string PaisResidencia, DTFecha FechaNacimiento);
        set<Inscripcion*> obtenerInscripciones();
        Inscripcion* obtenerInscripcionCurso(string nombreCurso);
        set<DTEstadisticaEstudiante> obtenerEstadisticasEstudiante(string nickname);
        void agregarInscripcion(Inscripcion* i);
        void eliminarInscripcion(Inscripcion* i);
        string obtenerPais();
        ~Estudiante();
};

#endif