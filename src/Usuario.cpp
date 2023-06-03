#include "../include/Usuario.h"
#include <string>
using namespace std;

Usuario::Usuario(string Nickname, string Contrasenia, string Nombre, string Descripcion){
  this->Nickname = Nickname;
  this->Contrasenia = Contrasenia;
  this->Nombre = Nombre;
  this->Descripcion = Descripcion;
}

string obtenerNickname(){
    return this->Nickname;
}

void Notificar(DTNotificacion Notificacion){
    this->Notificaciones.insert(Notificacion);
}

set<DTNotificacion> obtenerNotificaciones(){}

Usuario ::~Usuario(){}