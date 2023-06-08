#include "../include/ControladorUsuario.h"
#include "../include/Usuario.h"
#include "../include/Profesor.h"
#include "../include/DTFecha.h"
#include "../include/ManejadorIdioma.h"
#include "../include/ManejadorUsuario.h"

#include <set>
#include <string>
#include <iostream>

using namespace std;

ControladorUsuario * ControladorUsuario::instancia = NULL;
ControladorUsuario::ControladorUsuario(){}

ControladorUsuario * ControladorUsuario::getInstancia(){
    if (instancia == NULL){
        instancia = new ControladorUsuario();
    }
    return instancia; 
}

bool ControladorUsuario::confirmarAltaProfesor(){
    ManejadorUsuario * manejador = manejadorUsuario->getManejadorU();
    if(!manejador->existeNickname(Nickname)){
        Profesor *p = new Profesor(Nickname, Contrasenia, Nombre, Descripcion,
        Instituto, IdiomasRecordados);
        manejadorUsuario->agregarProfesor(p,Nickname);
        return true;
    } else {
        return false;
    }
}

bool ControladorUsuario::confirmarAltaEstudiante(){
    ManejadorUsuario *manejador = manejadorUsuario->getManejadorU();
    if (!manejador->existeNickname(this->Nickname)) {
        Estudiante *e = new Estudiante(Nickname, Contrasenia, Nombre,
        Descripcion, PaisResidencia, fechaNacimiento);
        manejador->agregarEstudiante(e, Nickname);
        return true;
   }
   else{
        return false;
   }
}

void ControladorUsuario::ingresarDatosUsuario(string Nickname, string Contrasenia, string Nombre, string Descripcion){
    this->Nickname = Nickname;
    this->Nombre = Nombre;
    this->Contrasenia = Contrasenia;
    this->Descripcion = Descripcion;
}

void ControladorUsuario::ingresarDatosEstudiante(string paisResidencia, DTFecha fechaNacimiento){
    this->PaisResidencia = paisResidencia;
    this->fechaNacimiento = fechaNacimiento;
}

set<string> ControladorUsuario::obtenerIdiomasDisponibles(){
    ManejadorIdioma * manejador = manejadorIdioma->getManejadorI();
    map<string, Idioma*> col = manejador->obtenerColeccionIdiomas();
    map<string, Idioma*>::iterator it; 
    set<string> retorno;
    for (it= col.begin(); it != col.end(); ++it) {
        retorno.insert(it->first);
    }
    return retorno;
}

set<string> ControladorUsuario::obtenerProfesores() {
    ManejadorUsuario * manejador = manejadorUsuario->getManejadorU();
    return manejador->obtenerNicknamesProfesores();
}

Profesor* ControladorUsuario::obtenerProfesor(string Nickname){
    ManejadorUsuario *manejador = manejadorUsuario->getManejadorU();
    return manejador->obtenerProfesor(Nickname);
}

set<string> ControladorUsuario::obtenerIdiomasProfesor(string nickname){
    ManejadorUsuario *manejador = manejadorUsuario->getManejadorU();
    set<string> idiomas = manejador->obtenerIdiomasProfesor(nickname);
    return idiomas;
}

void ControladorUsuario::agregarEspecializacion(string Nombreidioma){
    ManejadorIdioma *manejador = manejadorIdioma->getManejadorI();
    Idioma *i = manejador->obtenerIdioma(Nombreidioma);
    IdiomasRecordados.insert(i);
}

void ControladorUsuario::ingresarInstituto(string NombreInstituto){
    this->Instituto = NombreInstituto;
}

set<string> ControladorUsuario::obtenerEstudiantes(){
    ManejadorUsuario *manejador = manejadorUsuario->getManejadorU();
    return manejador->obtenerNicknamesEstudiantes();
}

bool ControladorUsuario::agregarIdioma(string Nombre) {
    ManejadorIdioma *manejador = manejadorIdioma->getManejadorI();
    if(manejador->agregarNuevoIdioma(Nombre)){
        return true;
    }
    else{
        return false;
    }
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

ControladorUsuario::~ControladorUsuario() { delete instancia; }