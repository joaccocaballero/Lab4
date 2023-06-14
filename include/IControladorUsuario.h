#ifndef ICONTROLADORUSUARIO
#define ICONTROLADORUSUARIO

#include <string>
#include <set>
using namespace std;
#include "DTEstadisticaProfesor.h"
#include "DTEstadisticaEstudiante.h"
#include "DTNotificacion.h"
#include "DTFecha.h"
#include "Usuario.h"
#include "DTUsuario.h"
#include "Profesor.h"
#include "DTProfesor.h"
#include "Estudiante.h"
#include "DTEstudiante.h"
#include "Idioma.h"

class IControladorUsuario {
    public:
        virtual bool confirmarAltaProfesor()= 0;
        virtual bool confirmarAltaEstudiante()= 0;
        virtual void ingresarDatosUsuario(string Nickname, string Contrasenia, string Nombre, string Descripcion)= 0;
        virtual void ingresarDatosEstudiante(string paisResidencia, DTFecha fechaNacimiento) = 0;
        virtual set<string> obtenerIdiomasDisponibles()= 0;
        virtual set<string> obtenerProfesores()= 0;
        virtual Profesor* obtenerProfesor(string Nickname)= 0;
        virtual set<string> obtenerIdiomasProfesor(string Nickname )= 0;
        virtual void agregarEspecializacion(string Nombreidioma) = 0;
        virtual void ingresarInstituto(string NombreInstituto)= 0;
        virtual set<string> obtenerEstudiantes()= 0;
        virtual set<DTEstadisticaEstudiante> obtenerEstadisticaEstudiante(string Nickname)= 0;
        virtual set<DTEstadisticaProfesor> obtenerEstadisticaProfesor(string Nickname)= 0;
        virtual set<string> obtenerSubscripcionesPendientes(string Nickname)= 0;
        virtual set<DTNotificacion> obtenerNotificaciones(string Nickname) = 0;
        virtual bool agregarIdioma(string Nombre) = 0;
        virtual set<string> obtenerUsuarios()= 0;
        virtual bool obtenerTipo(string nickname) = 0;
        virtual DTEstudiante obtenerInfoEstudiante(string Nickname)=0;
        virtual DTProfesor obtenerInfoProfesor(string Nickname)=0;
        virtual set<Inscripcion*> obtenerInscripcionesEstudiante(string nickname)=0;
        virtual bool suscribirUsuario(string nickname, set<string> idiomas) = 0;
        virtual ~IControladorUsuario() = 0;
};

#endif