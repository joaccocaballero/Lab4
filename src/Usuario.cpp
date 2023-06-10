#include "../include/Usuario.h"
#include <string>
using namespace std;

Usuario::Usuario(string Nickname, string Contrasenia, string Nombre, string Descripcion){
  this->Nickname = Nickname;
  this->Contrasenia = Contrasenia;
  this->Nombre = Nombre;
  this->Descripcion = Descripcion;
}

string Usuario::obtenerNickname(){
    return Nickname;
}
string Usuario::obtenerNombre(){
    return Nombre;
}

string Usuario::obtenerDescripcion(){
    return Descripcion;
}

void Usuario::Notificar(DTNotificacion Notificacion){
    Notificaciones.push_back(Notificacion);
}

vector<DTNotificacion> Usuario::obtenerNotificaciones(string Nickname){}

Usuario::~Usuario(){}