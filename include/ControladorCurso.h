#ifndef CONTROLADORCURSO
#define CONTROLADORCURSO

#include <string>
#include <set>
#include "Usuario.h"
#include "Idioma.h"
#include "Curso.h"
#include "Profesor.h"
#include "Ejercicio.h"
#include "DTEstadisticaCurso.h"
#include "IControladorCurso.h"
#include "ControladorUsuario.h"
#include "ManejadorCurso.h"
#include "ManejadorIdioma.h"

using namespace std;


class ControladorCurso : public IControladorCurso {
    private:
        static ControladorCurso * instancia;
        ManejadorCurso * manejadorCurso;
        ManejadorIdioma * manejadorIdioma;
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
        Curso* CursoSeleccionado;
        Leccion* LeccionSeleccionada;
        string TemaLeccion;
        string ObjetivoLeccion;
        set<Leccion*> leccionesRecordadas;
        string DescripcionEjercicio;
        set<Ejercicio*> ColeccionEjerciciosLeccion;
        string frase;
        string solucion;
        ControladorCurso();
    public:
        static ControladorCurso * getInstancia();
        void ingresarInfoCurso(string nombre, string Descripcion, EnumDificultad Dificultad);
        void ingresarInfoLeccion(string Tema, string Objetivo);
        void ingresarInfoEjercicio(string Descripcion);
        void agregarDatosCompletar(string frase, string solucion);
        void agregarDatosTraducir(string frase, string traduccion);
        void asignarProfesor(string nickname);
        set<string> obtenerCursosHabilitados();
        void ingresarCursosPrevios(set<string> nombresCursosPrevios);
        void seleccionarIdioma(string nomIdioma);
        void seleccionarCurso(string nomCurso);
        void seleccionarLeccion(string nomLeccion);
        void confirmarEliminacion(string nombre);
        void confirmarAltaCurso();
        void confirmarAltaLeccion();
        void confirmarAltaEjercicio(EnumEjercicios tipo);
        set<string> obtenerCursos();
        set<string> obtenerCursosNoAprobados(string nombre);
        set<string> obtenerCursosNoHabilitados();
        set<string> obtenerEjerciciosPendientes();
        set<string> obtenerLecciones();
        DTEjercicio seleccionarEjercicio(int id);
        bool validarEjercicio();
        DTEstadisticaCurso obtenerEstadisticaCurso(string nombre);
        bool confirmarHabilitacion(string nombre);
        virtual ~ControladorCurso();
};

#endif