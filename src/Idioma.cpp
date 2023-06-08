#include <string>
#include <set>
#include <map>
#include "../include/Idioma.h"

Idioma::Idioma(string Nombre){
this->Nombre=Nombre;
}
void Idioma::AgregarSuscriptor(IObserver* observer){}
void Idioma::RemoverSuscriptor(){}
string Idioma::obtenerNombre(){
    return this->Nombre;
}
void Idioma::NuevoCurso(Curso curso){}
set<Idioma> Idioma::obtenerSuscripcionesPendientes(string Nickname){}
Idioma::~Idioma(){}