#include <string>
#include <set>
#include <map>
#include <iostream>
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

bool ManejadorIdioma::agregarNuevoIdioma(string Nombre) {
    if (ColeccionDeIdiomas.count(Nombre) == 0) {
        Idioma* idioma = new Idioma(Nombre);
        ColeccionDeIdiomas.insert(make_pair(Nombre, idioma));
        return true;
    } else {
        return false;
    }
}

bool ManejadorIdioma::existeNickname(string Nickname) {}
set<string> ManejadorIdioma::obtenerNombresIdiomas(){}

Idioma* ManejadorIdioma::obtenerIdioma(string nombreIdioma){
   return ColeccionDeIdiomas[nombreIdioma];
}

set<string> ManejadorIdioma::obtenerIdiomas(){
       set<string> retorno;
    map<string, Idioma*>::iterator it;
    for (it = ColeccionDeIdiomas.begin(); it != ColeccionDeIdiomas.end();
         ++it) {
        retorno.insert(it->first);
    }
    return retorno;
}
set<string> ManejadorIdioma::obtenerEstudiantes() {}
set<string> ManejadorIdioma::obtenerSuscripcionesPendientes(string Nickname) {
    set<string> pendientes;
    map<string, Idioma*> idiomas = obtenerColeccionIdiomas();
    map<string, Idioma*>::iterator it;
    for(it=idiomas.begin(); it!=idiomas.end(); ++it){
        Idioma *current =  it->second;
        if (current->esSuscriptor(Nickname) == false){
            pendientes.insert(current->obtenerNombre());
        }
    }
    return pendientes;
}
set<string> ManejadorIdioma::obtenerSuscripciones(string Nickname) {
    set<string> suscritos;
    map<string, Idioma*> idiomas = obtenerColeccionIdiomas();
    map<string, Idioma*>::iterator it;
    for(it=idiomas.begin(); it!=idiomas.end(); ++it){
        Idioma *current =  it->second;
        if (current->esSuscriptor(Nickname) == true){
            suscritos.insert(current->obtenerNombre());
        }
    }
    return suscritos;
}