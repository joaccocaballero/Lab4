#ifndef ICONTROLADORUSUARIO
#define ICONTROLADORUSUARIO

#include <string>
using namespace std;
#include "DTEstadisticaProfesor.h"
#include "DTEstadisticaEstudiante.h"
#include "DTNotificacion.h"
#include "ControladorUsuario.h"
#include "Usuario.h"

class IcontroladorUsuario{
    virtual void altaProfesor()= 0;
    virtual bool confirmarAltaProfesor()= 0;
    virtual bool confirmarAltaErofesor()= 0;
    virtual void ingresarDatosUsuario(string Nickname, string Contrasenia, string Nombre, string Descripcion)= 0;
    virtual void ingresarPaisResidencia(string nombre)= 0;
    virtual set<string> obtenerIdiomasDisponibles()= 0;
    virtual set<string> obtenerProfesores()= 0;
    virtual Usuario obtenerProfesor(string Nickname)= 0;
    virtual set<string> obtenerIdiomasProfesor( )= 0;
    virtual void agregarEspecializacion(string Nombreidioma);
    virtual void agregarUsuario()= 0;
    virtual void ingresarInstituto(string NombreInstituto)= 0;
    virtual set<string> obtenerEstudiantes()= 0;
    virtual set<DTEstadisticaEstudiante> obtenerEstadisticaEstudiante(string Nickname)= 0;
    virtual set<DTEstadisticaProfesor> obtenerEstadisticaProfesor(string Nickname)= 0;
    virtual set<Idioma> obtenerSubscripcionesPendientes(string Nickname)= 0;
    virtual set<DTNotificacion> obtenerNotificaciones(Nickname: string) = 0;
    virtual ControladorUsuario getInstancia() = 0;
    
    virtual ~IcontroladorUsuario(){};
};

#endif