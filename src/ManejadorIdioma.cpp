#include <string>
#include <set>
#include <map>

#include "../include/ManejadorIdioma.h"
#include "../include/Idioma.h"

ManejadorIdioma * ManejadorIdioma::instancia = NULL;

ManejadorIdioma::ManejadorIdioma(){}

ManejadorIdioma * ManejadorIdioma::getManejadorI(){
    if (instancia==NULL)
    {
        instancia = new ManejadorIdioma();
    }
    return instancia;
}

map<string, Idioma*> ManejadorIdioma::obtenerColeccionIdiomas(){
    return this->ColeccionDeIdiomas;
}

bool ManejadorIdioma::existeNickname(string Nickname) {}
set<string> ManejadorIdioma::obtenerNombresIdiomas(){}

Idioma* ManejadorIdioma::obtenerIdioma(string nombreIdioma){
   return this->ColeccionDeIdiomas[nombreIdioma];
}

set<string> ManejadorIdioma::obtenerIdiomas(){}
set<string> ManejadorIdioma::obtenerEstudiantes() {}
set<Idioma> ManejadorIdioma::obtenerSuscripcionesPendientes(string Nickname) {}
