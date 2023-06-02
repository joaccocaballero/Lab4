#include <string>
#include "Usuario.h"
#include "DTEstadisticaCurso.h"
#include "ControladorCurso.h"

using namespace std;

enum EnumDificultad { Principiante, Medio, Avanzado };

class IControladorCurso {
    public:
        virtual void altaProfesor() = 0;
        virtual bool confirmarAltaEstudiante() = 0;
        virtual bool confirmarAltaProfesor() = 0;
        virtual void ingresarInfoCurso(string nombre,  string Descripcion, EnumDificultad Dificultad) = 0;
        virtual void asignarProfesor(string nickname) = 0;
        virtual set<string> obtenerCursosHabilitados() = 0;
        virtual set<string> ingresarCursosPrevios( set<string> nombresCursosPrevios) = 0;
        virtual void seleccionarIdioma(string nomIdioma) = 0;
        virtual void confirmarEliminacion(string nombre) = 0;
        virtual void confirmarAltaCurso() = 0;
        virtual set<string> obtenerCursos() = 0;
        virtual Usuario obtenerProfesor() = 0;
        virtual void obtenerCursosNoAprobados(string nombre) = 0;
        virtual void seleccionarCurso(string nombre) = 0;
        virtual set<string> obtenerEjerciciosPendientes() = 0;
        virtual DTEjercicio seleccionarEjercicio(int id) = 0;
        virtual bool validarEjercicio() = 0;
        virtual set<string> obtenerCursos() = 0;
        virtual DTEstadisticaCurso obtenerEstadisticaCurso(string nombre) = 0;
        virtual ControladorCurso getInstancia() = 0;
        virtual ~IControladorCurso(){};
}