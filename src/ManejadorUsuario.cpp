#include <string>
using namespace std;
#include "../include/ManejadorUsuario.h"


ManejadorUsuario* ManejadorUsuario::manejadorU = NULL;

ManejadorUsuario::ManejadorUsuario() {}

ManejadorUsuario* ManejadorUsuario::getManejadorU() {
  if (manejadorU == NULL) {
    manejadorU = new ManejadorUsuario();
  }
  return manejadorU;
}

bool ManejadorUsuario::existeNickname(string Nickname){
    if(this->ColeccionDeEstudiantes[Nickname] == NULL && this->ColeccionDeProfesores[Nickname]==NULL){
        return true;
    }
    else{
        return false;
    }
}

void ManejadorUsuario::agregarEstudiante(Estudiante *estudiante, string nickname){
    this->ColeccionDeEstudiantes.insert(make_pair(nickname, estudiante));
};


void ManejadorUsuario::agregarProfesor(Profesor*profesor, string nickname){
    this->ColeccionDeProfesores.insert(make_pair(nickname, profesor));
};

set<string> ManejadorUsuario::obtenerNicknamesProfesores(){};
Profesor ManejadorUsuario::obtenerProfesor(){};
set<string> ManejadorUsuario::obtenerIdiomasProfesor(){};
set<string> ManejadorUsuario::obtenerEstudiantes(){};
set<DTEstadisticaEstudiante> ManejadorUsuario::obtenerEstadisticasEstudiantes(
    string Nickname){};
set<string> ManejadorUsuario::obtenerProfesores(){};
set<DTEstadisticaProfesor> ManejadorUsuario::obtenerEstadisticasProfesor(
    string Nickname){};
set<DTNotificacion> ManejadorUsuario::obtenerNotificaciones(string Nickname){};