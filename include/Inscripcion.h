
#include "DTFecha.h"
#include "Estudiante.h"
#include "Curso.h"

class Inscripcion {
    private:
        integer id;
        DTFecha Fecha;
        bool    Aprobacion;
        Curso * CursoInscripcion;
        Estudiante * EstudianteInscrito;
    public:
        integer obtenerIdInscripcion();
        ~Inscripcion();
};