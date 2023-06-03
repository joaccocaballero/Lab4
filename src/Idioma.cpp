#include <string>
#include <set>
#include <map>
#include "../include/Idioma.h"

Idioma::Idioma(string Nombre){
this->Nombre=Nombre;
}
void Idioma::AgregarSuscriptor(IObserver){}
void Idioma::RemoverSuscriptor(){}
string Idioma::obtenerNombre(){}
void Idioma::NuevoCurso(Curso curso){}
set<Idioma> Idioma::obtenerSuscripcionesPendientes(string Nickname){}
Idioma::~Idioma(){}