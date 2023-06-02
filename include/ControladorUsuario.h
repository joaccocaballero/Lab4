#include <string>
#include <set>
#include "DTEstadisticaEstudiante.h"
#include "DTEstadisticaProfesor.h"
#include "DTNotificacion.h"
#include "Usuario.h"
#include "ManejadorIdioma.h"
#include "ManejadorUsuario.h"


using namespace std;

class ControladorUsuario : public IControladorUsuario {
    private:
    static ControladorUsuario * instancia;
    ManejadorIdioma * manejadorIdioma;
    ManejadorUsuario * manejadorUsuario;
    ControladorUsuario();
    public:
        static ControladorUsuario * getInstancia();
         void altaProfesor();
         bool confirmarAltaProfesor();
         bool confirmarAltaErofesor();
         void ingresarDatosUsuario(string Nickname, string Contrasenia, string Nombre, string Descripcion);
         void ingresarPaisResidencia(string nombre);
         set<string> obtenerIdiomasDisponibles();
         set<string> obtenerProfesores();
         Usuario obtenerProfesor(string Nickname);
         set<string> obtenerIdiomasProfesor( );
         void agregarEspecializacion(string Nombreidioma);
         void agregarUsuario();
         void ingresarInstituto(string NombreInstituto);
         set<string> obtenerEstudiantes();
         set<DTEstadisticaEstudiante> obtenerEstadisticaEstudiante(string Nickname);
         set<DTEstadisticaProfesor> obtenerEstadisticaProfesor(string Nickname);
         set<Idioma> obtenerSubscripcionesPendientes(string Nickname);
         set<DTNotificacion> obtenerNotificaciones(Nickname: string);
         ~ControladorUsuario(){};
    }