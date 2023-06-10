#include <map>
#include <string>
using namespace std;
#include <iostream>
#include "../include/ManejadorUsuario.h"
#include "../include/DTEstudiante.h"
#include "../include/DTProfesor.h"


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

set<string> ManejadorUsuario::obtenerNicknamesEstudiantes() {
    set<string> retorno;
    map<string, Estudiante*>::iterator it;
    for (it = ColeccionDeEstudiantes.begin(); it != ColeccionDeEstudiantes.end();
         ++it) {
        retorno.insert(it->first);
    }
    return retorno;
}

Profesor* ManejadorUsuario::obtenerProfesor(string nickname){
    return ColeccionDeProfesores[nickname];
}

set<string> ManejadorUsuario::obtenerIdiomasProfesor(string nickname){
    map<string, Profesor*>::iterator it;
    it=ColeccionDeProfesores.find(nickname);
    Profesor* p = it->second;
    return p->consultarIdiomasProfesor();
}

DTUsuario ManejadorUsuario::obtenerUsuario(string nickname) {
    Usuario* u;
    bool esEstudiante = false;
    if (ColeccionDeEstudiantes.count(nickname)) {
        u = ColeccionDeEstudiantes[nickname];
        esEstudiante = true;
    } else {
        u = ColeccionDeProfesores[nickname];
    }
    
    if (esEstudiante) {
        DTEstudiante dtEstudiante = DTEstudiante(u->obtenerNombre(), u->obtenerDescripcion(), u->obtenerPais());
        return dtEstudiante;
    } else {
        set<string> idiomas = obtenerIdiomasProfesor(u->obtenerNickname());
        DTProfesor dtProfesor = DTProfesor(u->obtenerNombre, u->obtenerDescripcion, u->obtenerInstituto, idiomas);
        return DTProfesor;
    }

}

set<string> ManejadorUsuario::obtenerEstudiantes(){}
set<DTEstadisticaEstudiante> ManejadorUsuario::obtenerEstadisticasEstudiantes(
    string Nickname){}
set<string> ManejadorUsuario::obtenerProfesores(){}
set<DTEstadisticaProfesor> ManejadorUsuario::obtenerEstadisticasProfesor(
    string Nickname){}
set<DTNotificacion> ManejadorUsuario::obtenerNotificaciones(string Nickname){}
