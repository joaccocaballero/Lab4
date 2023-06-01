#include <string>
#include "Usuario.h"
#include "DTEstadisticaCurso.h"
#include "IControladorCurso.h"

using namespace std;

enum EnumDificultad { Principiante, Medio, Avanzado };

class ControladorCurso : public IControladorCurso {
    private:
        static ControladorCurso * instancia;
        ControladorCurso();
    public:
        static ControladorCurso * getInstancia();
        void altaProfesor() ;
        bool confirmarAltaEstudiante() ;
        bool confirmarAltaProfesor() ;
        void ingresarInfoCurso(string nombre,  string Descripcion, EnumDificultad Dificultad) ;
        void asignarProfesor(string nickname) ;
        set<string> obtenerCursosHabilitados() ;
        set<string> ingresarCursosPrevios( set<string> nombresCursosPrevios) ;
        void seleccionarIdioma(string nomIdioma) ;
        void confirmarEliminacion(string nombre) ;
        void confirmarAltaCurso() ;
        set<string> obtenerCursos() ;
        Usuario obtenerProfesor() ;
        void obtenerCursosNoAprobados(string nombre) ;
        void seleccionarCurso(string nombre) ;
        set<string> obtenerEjerciciosPendientes() ;
        DTEjercicio seleccionarEjercicio(int id) ;
        bool validarEjercicio() ;
        set<string> obtenerCursos() ;
        DTEstadisticaCurso obtenerEstadisticaCurso(string nombre) ;
        ~ControladorCurso(){};
}