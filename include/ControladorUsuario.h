#ifndef CONTROLADORUSUARIO
#define CONTROLADORUSUARIO

#include <string>
#include <set>
#include <vector>
#include "IControladorUsuario.h"
#include "DTEstadisticaEstudiante.h"
#include "DTEstadisticaProfesor.h"
#include "Usuario.h"
#include "Idioma.h"
#include "DTFecha.h"
#include "Profesor.h"
#include "Estudiante.h"
#include "ManejadorIdioma.h"
#include "ManejadorUsuario.h"
#include "DTUsuario.h"
using namespace std;

class ControladorUsuario : public IControladorUsuario {
    private:
        static ControladorUsuario * instancia;
        ManejadorIdioma * manejadorIdioma;
        ManejadorUsuario * manejadorUsuario;
        string Nickname;
        string Nombre;
        string Contrasenia;
        string Descripcion;
        string PaisResidencia;
        string Instituto;
        DTFecha fechaNacimiento;
        set<string> listadoProfesores;
        set<Idioma*> IdiomasRecordados;
        Usuario * UsuarioRecordado;
        set<Idioma *> SuscripcionesUsuario;
        set<Idioma *> SuscripcionesPendientesUsuario;
        ControladorUsuario();
    public:
         static ControladorUsuario * getInstancia();
         bool confirmarAltaProfesor();
         bool confirmarAltaEstudiante();
         bool confirmarAltaInscripcion(Estudiante* e, Inscripcion* i);
         void ingresarDatosUsuario(string Nickname, string Contrasenia, string Nombre, string Descripcion);
         void ingresarDatosEstudiante(string paisResidencia, DTFecha fechaNacimiento);
         set<string> obtenerIdiomasDisponibles();
         set<string> obtenerProfesores();
         Profesor* obtenerProfesor(string Nickname);
         set<string> obtenerIdiomasProfesor(string nickname);
         void agregarEspecializacion(string Nombreidioma);
         void ingresarInstituto(string NombreInstituto);
         bool agregarIdioma(string Nombre);
         set<string> obtenerEstudiantes();
         Estudiante* obtenerEstudiante(string nickname);
         bool obtenerTipo(string nickname);
         set<DTEstadisticaEstudiante> obtenerEstadisticaEstudiante(string Nickname);
         set<string> obtenerSubscripcionesPendientes(string Nickname);
         vector<DTNotificacion> obtenerNotificaciones(string Nickname);
         void notificarUsuarios(string nombreIdioma, string nombreCurso, vector<string> suscriptores);
         set<string> obtenerUsuarios();
         set<string> obtenerSubscripciones(string nickname);
         bool removerSuscripciones(string nickname, set<string> idiomas);
         DTEstudiante obtenerInfoEstudiante(string Nickname);
         DTProfesor obtenerInfoProfesor(string Nickname);
         set<Inscripcion*> obtenerInscripcionesEstudiante(string nickname);
         bool suscribirUsuario(string nickname, set<string> idiomas);
         set<string> obtenerCursosNoAprobados(string Nickname); 
         virtual ~ControladorUsuario();
    };

#endif