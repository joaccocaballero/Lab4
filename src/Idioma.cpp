#include <string>
#include <iostream>
#include <set>
#include <map>
#include "../include/Idioma.h"

Idioma::Idioma(string Nombre){
this->Nombre=Nombre;
}
void Idioma::AgregarSuscriptor(string nickname, IObserver* observer){
    Suscriptores.insert(make_pair(nickname, observer));
}
void Idioma::RemoverSuscriptor(){}
string Idioma::obtenerNombre(){
    return this->Nombre;
}
void Idioma::NuevoCurso(Curso curso){}
bool Idioma::esSuscriptor(string nickname) {
    return (Suscriptores.find(nickname) != Suscriptores.end());
}
set<string> Idioma::obtenerSuscripcionesPendientes(string Nickname) {}
Idioma::~Idioma(){}