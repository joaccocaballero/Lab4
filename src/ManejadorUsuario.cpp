#include <map>
#include <string>
using namespace std;
#include <iostream>
#include "../include/ManejadorUsuario.h"
#include "../include/DTEstudiante.h"
#include "../include/DTProfesor.h"
#include "../include/DTEstudiante.h"
#include "../include/DTEstadisticaProfesor.h"


ManejadorUsuario* ManejadorUsuario::manejadorU = NULL;

ManejadorUsuario::ManejadorUsuario() {}

ManejadorUsuario* ManejadorUsuario::getManejadorU() {
  if (manejadorU == NULL) {
    manejadorU = new ManejadorUsuario();
  }
  return manejadorU;
}

bool ManejadorUsuario::existeNickname(string Nickname){
    bool res = false;
    if (ColeccionDeEstudiantes.size() != 0 || ColeccionDeProfesores.size() != 0){
        if(ColeccionDeEstudiantes.count(Nickname) != 0 || ColeccionDeProfesores.count(Nickname) != 0){
            res = true;
        }

    }
    return res;
}

void ManejadorUsuario::agregarEstudiante(Estudiante *estudiante, string nickname){
    ColeccionDeEstudiantes.insert(make_pair(nickname, estudiante));
}

Estudiante* ManejadorUsuario::obtenerEstudiante(string nickname) {
    return ColeccionDeEstudiantes[nickname];
}

set<Inscripcion*> ManejadorUsuario::obtenerInscripcionesEstudiante(string nickname) {
    Estudiante *e = obtenerEstudiante(nickname);
    return e->obtenerInscripciones();
}

void ManejadorUsuario::agregarProfesor(Profesor *profesor, string nickname){
    ColeccionDeProfesores.insert(make_pair(nickname, profesor));
}

set<string> ManejadorUsuario::obtenerNicknamesProfesores(){
    set<string> retorno;
    map<string, Profesor*>::iterator it;
    for (it = ColeccionDeProfesores.begin(); it != ColeccionDeProfesores.end(); ++it) {
        retorno.insert(it->first);
    }
    return retorno;
}

set<string> ManejadorUsuario::obtenerNicknamesEstudiantes(){
    set<string> retorno;
    map<string, Estudiante*>::iterator it;
    for (it = ColeccionDeEstudiantes.begin(); it != ColeccionDeEstudiantes.end(); ++it) {
        retorno.insert(it->first);
    }
    return retorno;
}


DTProfesor ManejadorUsuario::obtenerDTProfesor(string nickname) {
    Profesor* p = ColeccionDeProfesores[nickname];
    set<string> idiomas = p->consultarIdiomasProfesor();
    DTProfesor dtProfesor = DTProfesor(p->obtenerNombre(), p->obtenerDescripcion(), p->obtenerInstituto(), idiomas);
    return dtProfesor;
}

DTEstudiante ManejadorUsuario::obtenerDTEstudiante(string nickname){
    Estudiante* e = ColeccionDeEstudiantes[nickname];
    DTEstudiante dtEstudiante = DTEstudiante(e->obtenerNombre(), e->obtenerDescripcion(), e->obtenerPais());
    return dtEstudiante;
}

bool ManejadorUsuario::esEstudiante(string nickname){
    return (ColeccionDeEstudiantes.count(nickname) == 1);
}

void ManejadorUsuario::agregarInscripcion(Estudiante* e, Inscripcion* i){
    e->agregarInscripcion(i);
}

set<string> ManejadorUsuario::obtenerEstudiantes(){}

set<DTEstadisticaEstudiante> ManejadorUsuario::obtenerEstadisticasEstudiantes(
    string Nickname){
        Estudiante* e = ColeccionDeEstudiantes[Nickname];
        set<DTEstadisticaEstudiante> dtEstadisEstudiante = e->obtenerEstadisticas();
        return dtEstadisEstudiante;
    }

set<string> ManejadorUsuario::obtenerProfesores(){
}

set<DTEstadisticaProfesor> ManejadorUsuario::obtenerEstadisticasProfesor(
    string Nickname){}

Profesor* ManejadorUsuario::obtenerProfesor(string nickname){
    return ColeccionDeProfesores[nickname];
}
set<string> ManejadorUsuario::obtenerIdiomasProfesor(string nickname){
    return ColeccionDeProfesores[nickname]->consultarIdiomasProfesor();
}

set<string> ManejadorUsuario::obtenerCursosNoAprobados(string Nickname){
    set<string> noAprobados;
    Estudiante* e = ColeccionDeEstudiantes[Nickname];
    
    set<Inscripcion*> inscripciones = e->obtenerInscripciones();
    set<Inscripcion*>::iterator it;
    for (it = inscripciones.begin(); it != inscripciones.end(); ++it) {
        Inscripcion *current  = *it;
        if (current->obtenerAprobacion() == false){
            Curso* curso= current->obtenerCurso();
            noAprobados.insert(curso->obtenerNombre());
        }
    }
    return noAprobados;
}

vector<DTNotificacion> ManejadorUsuario::obtenerNotificaciones(string Nickname){
    bool esEstudiante = (ColeccionDeEstudiantes.count(Nickname) == 1);
    vector<DTNotificacion> notificaciones;
    if(esEstudiante) {
        Estudiante *e = obtenerEstudiante(Nickname);
        notificaciones = e->obtenerNotificaciones();
    } else {
        Profesor *p = obtenerProfesor(Nickname);
        notificaciones = p->obtenerNotificaciones();
    }
    return notificaciones;
}
