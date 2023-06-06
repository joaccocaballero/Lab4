#ifndef CONTROLADORUSUARIO
#define CONTROLADORUSUARIO

#include <string>
#include <set>
#include "IControladorUsuario.h"
#include "DTEstadisticaEstudiante.h"
#include "DTEstadisticaProfesor.h"
#include "Usuario.h"
#include "Idioma.h"
#include "Profesor.h"
#include "ManejadorIdioma.h"
#include "ManejadorUsuario.h"

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
        set<string> listadoProfesores;
        set<Idioma *> IdiomasRecordados;
        Usuario * UsuarioRecordado;
        set<Idioma *> SuscripcionesUsuario;
        set<Idioma *> SuscripcionesPendientesUsuario;
        ControladorUsuario();
    public:
         static ControladorUsuario * getInstancia();
         void altaProfesor();
         bool confirmarAltaProfesor();
         bool confirmarAltaEstudiante();
         void ingresarDatosUsuario(string Nickname, string Contrasenia, string Nombre, string Descripcion);
         void ingresarPaisResidencia(string nombre);
         set<string> obtenerIdiomasDisponibles();
         set<string> obtenerProfesores();
         Profesor* obtenerProfesor(string Nickname);
         set<string> obtenerIdiomasProfesor(string nickname);
         void agregarEspecializacion(string Nombreidioma);
         void agregarUsuario();
         void ingresarInstituto(string NombreInstituto);
         set<string> obtenerEstudiantes();
         set<DTEstadisticaEstudiante> obtenerEstadisticaEstudiante(string Nickname);
         set<DTEstadisticaProfesor> obtenerEstadisticaProfesor(string Nickname);
         set<Idioma> obtenerSubscripcionesPendientes(string Nickname);
         set<DTNotificacion> obtenerNotificaciones(string Nickname);
         ~ControladorUsuario(){};
    };

#endif