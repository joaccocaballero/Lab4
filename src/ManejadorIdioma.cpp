#include <string>
#include <set>
#include <map>

#include "../include/ManejadorIdioma.h"

ManejadorIdioma * ManejadorIdioma::instancia = NULL;

ManejadorIdioma::ManejadorIdioma(){}

static ManejadorIdioma * getManejadorI(){
    if (instancia==NULL)
    {
        instancia = new ManejadorIdioma();
    }
    return instancia;
}

map<string, Idioma*> ManejadorIdioma::obtenerColeccionIdiomas(){
    return this->ColeccionDeIdiomas;
}

bool existeNickname(string Nickname){}
set<string> obtenerNombresIdiomas(){}
Idioma obtenerIdioma(string nombreIdioma){}
set<string> obtenerIdiomas(){}
set<string> obtenerEstudiantes(){}
set<Idioma> obtenerSuscripcionesPendientes(string Nickname){}