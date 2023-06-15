#include <string>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include "../include/Idioma.h"

Idioma::Idioma(string Nombre){
this->Nombre=Nombre;
}
void Idioma::AgregarSuscriptor(string nickname, IObserver* observer){
    Suscriptores.insert(make_pair(nickname, observer));
}
void Idioma::RemoverSuscriptor(string nickname){
    Suscriptores.erase(nickname);
}
string Idioma::obtenerNombre(){
    return this->Nombre;
}
void Idioma::NuevoCurso(Curso curso){}
bool Idioma::esSuscriptor(string nickname) {
    return (Suscriptores.find(nickname) != Suscriptores.end());
}
vector<string> Idioma::obtenerSuscriptores() {
    map<string, Idioma*>::iterator it;
    vector<string> retorno;
    for (auto it = Suscriptores.begin(); it != Suscriptores.end(); ++it) {
        retorno.push_back(it->first);
    }

    return retorno;
}
set<string> Idioma::obtenerSuscripcionesPendientes(string Nickname) {}
Idioma::~Idioma(){}