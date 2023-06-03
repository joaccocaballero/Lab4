
#include "DTFecha.h"
#include "Curso.h"

class Curso;
class Estudiante;

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