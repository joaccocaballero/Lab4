#include "../include/ControladorUsuario.h"
#include "../include/Usuario.h"
#include <set>
#include <string>

ControladorUsuario * ControladorUsuario::instancia = NULL;
ControladorUsuario::ControladorUsuario(){}
ControladorUsuario * ControladorUsuario::getInstancia(){
    if (instancia == NULL){
        instancia = new ControladorUsuario();
    }
    return instancia; 
}

void altaProfesor(){}

bool confirmarAltaProfesor(){}

bool confirmarAltaEstudiante(){}

void ingresarDatosUsuario(string Nickname, string Contrasenia, string Nombre, string Descripcion){
    this->Nickname = Nickname;
    this->Nombre = Nombre;
    this->Contrasenia = Contrasenia;
    this->Descripcion = Descripcion;
}
void ingresarPaisResidencia(string nombre){
    this->PaisResidencia = nombre;
}

set<string> obtenerIdiomasDisponibles(){}

set<string> obtenerProfesores(){}

Usuario obtenerProfesor(string Nickname){}

set<string> obtenerIdiomasProfesor(){}

void agregarEspecializacion(string Nombreidioma){}

void agregarUsuario(){}

void ingresarInstituto(string NombreInstituto){
    this->Instituto = NombreInstituto;
}

set<string> obtenerEstudiantes(){}

set<DTEstadisticaEstudiante> obtenerEstadisticaEstudiante(string Nickname){}

set<DTEstadisticaEstudiante> obtenerEstadisticaProfesor(string Nickname){}

set<Idioma> obtenerSubscripcionesPendientes(string Nickname){}

set<DTNotificacion> obtenerNotificaciones(string Nickname){}

ControladorUsuario ::~ControladorUsuario() {}
