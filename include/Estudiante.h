#include <set>
#include <string>

#include "DTFecha.h"
#include "DTEstadisticaEstudiante.h"
using namespace std;

class Estudiante: public Usuario {
    private:
        string PaisResidencia;
        DTFecha FechaNacimiento;
    public:
        Estudiante(string Nickname, string Contrasenia, string Nombre, string Descripcion, string PaisResidencia, DTFecha FechaNacimiento);
        void obtenerInscripciones();
        set<DTEstadisticaEstudiante> obtenerEstadisticasEstudiante(string nickname);
        ~Estudiante();
}