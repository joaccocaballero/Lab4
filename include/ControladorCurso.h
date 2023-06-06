#ifndef CONTROLADORCURSO
#define CONTROLADORCURSO

#include <string>
#include <set>
#include "Usuario.h"
#include "Idioma.h"
#include "Curso.h"
#include "Profesor.h"
#include "DTEstadisticaCurso.h"
#include "IControladorCurso.h"
#include "ControladorUsuario.h"
#include "ManejadorCurso.h"

using namespace std;


class ControladorCurso : public IControladorCurso {
    private:
        static ControladorCurso * instancia;
        ManejadorCurso * manejadorCurso;
        ControladorUsuario * controladorUsuario;
        string Nombre;
        string Descripcion;
        EnumDificultad Dificultad;
        string NicknameProfesor;
        string nombreIdioma;
        set<string> CursosPrevios;
        int idEjercicioSeleccionado;
        Idioma* IdiomaSeleccionado;
        Usuario* ProfesorSeleccionado;
        set<string> ListadoProfesores;
        set<string> ListadoIdiomasProfesor;
        set<Curso*> ColeccionCursosPrevios;
        ControladorCurso();
    public:
        static ControladorCurso * getInstancia();
        void altaProfesor();
        bool confirmarAltaEstudiante();
        bool confirmarAltaProfesor();
        void ingresarInfoCurso(string nombre, string Descripcion, EnumDificultad Dificultad);
        void asignarProfesor(string nickname);
        set<string> obtenerCursosHabilitados();
        void ingresarCursosPrevios( set<string> nombresCursosPrevios);
        void seleccionarIdioma(string nomIdioma);
        void confirmarEliminacion(string nombre);
        void confirmarAltaCurso();
        set<string> obtenerCursos();
        Profesor obtenerProfesor();
        set<string> obtenerCursosNoAprobados(string nombre);
        void seleccionarCurso(string nombre);
        set<string> obtenerEjerciciosPendientes();
        DTEjercicio seleccionarEjercicio(int id);
        bool validarEjercicio();
        DTEstadisticaCurso obtenerEstadisticaCurso(string nombre);
        ~ControladorCurso(){};
};

#endif