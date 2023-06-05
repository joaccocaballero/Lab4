#ifndef ICONTROLADORUSUARIO
#define ICONTROLADORUSUARIO

#include <string>
#include <set>
using namespace std;
#include "DTEstadisticaProfesor.h"
#include "DTEstadisticaEstudiante.h"
#include "DTNotificacion.h"
#include "Usuario.h"
#include "Profesor.h"
#include "Idioma.h"

class IControladorUsuario {
    public:
        virtual void altaProfesor()= 0;
        virtual bool confirmarAltaProfesor()= 0;
        virtual bool confirmarAltaEstudiante()= 0;
        virtual void ingresarDatosUsuario(string Nickname, string Contrasenia, string Nombre, string Descripcion)= 0;
        virtual void ingresarDatosEstudiante(string paisResidencia, string fechaNacimiento) = 0;
        virtual set<string> obtenerIdiomasDisponibles()= 0;
        virtual set<string> obtenerProfesores()= 0;
        virtual Profesor* obtenerProfesor(string Nickname)= 0;
        virtual set<string> obtenerIdiomasProfesor( )= 0;
        virtual void agregarEspecializacion(string Nombreidioma) = 0;
        virtual void agregarUsuario()= 0;
        virtual void ingresarInstituto(string NombreInstituto)= 0;
        virtual set<string> obtenerEstudiantes()= 0;
        virtual set<DTEstadisticaEstudiante> obtenerEstadisticaEstudiante(string Nickname)= 0;
        virtual set<DTEstadisticaProfesor> obtenerEstadisticaProfesor(string Nickname)= 0;
        virtual set<Idioma> obtenerSubscripcionesPendientes(string Nickname)= 0;
        virtual set<DTNotificacion> obtenerNotificaciones(string Nickname) = 0;
        //virtual ControladorUsuario getInstancia() = 0;
        virtual ~IControladorUsuario() = 0;
};

#endif