#include "../include/ControladorUsuario.h"
#include "../include/Usuario.h"
#include "../include/Profesor.h"
#include "../include/DTFecha.h"
#include "../include/ManejadorIdioma.h"

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

void ControladorUsuario::altaProfesor(){}

bool ControladorUsuario::confirmarAltaProfesor(){
    // Agrega tu implementación aquí
    return false;
}

bool ControladorUsuario::confirmarAltaEstudiante(){
    // Agrega tu implementación aquí
    return false;
}

void ControladorUsuario::ingresarDatosUsuario(string Nickname, string Contrasenia, string Nombre, string Descripcion){
    this->Nickname = Nickname;
    this->Nombre = Nombre;
    this->Contrasenia = Contrasenia;
    this->Descripcion = Descripcion;
}

void ControladorUsuario::ingresarDatosEstudiante(string paisResidencia, string fechaNacimiento){
    this->PaisResidencia = paisResidencia;
    this->fechaNacimiento = fechaNacimiento;
}

set<string> ControladorUsuario::obtenerIdiomasDisponibles(){
    map<string, Idioma*> col = this->manejadorIdioma->obtenerColeccionIdiomas();
    set<string> retorno;
    for (const auto& idioma : col) {
        string nombre = idioma.obtenerNombre();
        retorno.insert(nombre);
    }
    return retorno
}

set<string> ControladorUsuario::obtenerProfesores() {
    // Agrega tu implementación aquí
    set<string> profesores;
    return profesores;
}

Profesor* ControladorUsuario::obtenerProfesor(string Nickname){
    // Agrega tu implementación aquí
    set<Idioma*> idiomas; 
    Profesor* profesor = new Profesor("nombre", "1234asd", "pepe", "anonimo", "liceo", idiomas);
    return profesor;
}

set<string> ControladorUsuario::obtenerIdiomasProfesor(){
    // Agrega tu implementación aquí
    set<string> idiomas;
    return idiomas;
}

void ControladorUsuario::agregarEspecializacion(string Nombreidioma){
    
}

void ControladorUsuario::agregarUsuario(){
    // Agrega tu implementación aquí
}

void ControladorUsuario::ingresarInstituto(string NombreInstituto){
    this->Instituto = NombreInstituto;
}

set<string> ControladorUsuario::obtenerEstudiantes(){
    // Agrega tu implementación aquí
    set<string> estudiantes;
    return estudiantes;
}

set<DTEstadisticaEstudiante> ControladorUsuario::obtenerEstadisticaEstudiante(string Nickname){
    // Agrega tu implementación aquí
    set<DTEstadisticaEstudiante> estadisticas;
    return estadisticas;
}

set<DTEstadisticaProfesor> ControladorUsuario::obtenerEstadisticaProfesor(string Nickname){
    // Agrega tu implementación aquí
    set<DTEstadisticaProfesor> estadisticas;
    return estadisticas;
}
