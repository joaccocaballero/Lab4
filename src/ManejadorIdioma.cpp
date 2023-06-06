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

bool existeNickname(string Nickname){}
set<string> obtenerNombresIdiomas(){}
Idioma ManejadoirIdioma::obtenerIdioma(string nombreIdioma){
    Idioma idioma = ColeccionIdiomas.find(nombreIdioma);
    // handlear nulo?
    return idioma;
}
set<string> obtenerIdiomas(){}
set<string> obtenerEstudiantes(){}
set<Idioma> obtenerSuscripcionesPendientes(string Nickname){}