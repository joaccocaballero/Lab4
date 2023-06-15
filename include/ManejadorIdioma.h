#ifndef MANEJADORIDIOMA
#define MANEJADORIDIOMA

#include <string>
#include <set>
#include <map>
#include "Usuario.h"
#include "Idioma.h"

using namespace std;

class ManejadorIdioma {
    private:
        static ManejadorIdioma * instancia;
        map<string, Idioma*> ColeccionDeIdiomas;
        ManejadorIdioma();
    public:
        static ManejadorIdioma * getManejadorI();
        bool existeNickname(string Nickname);
        set<string> obtenerNombresIdiomas();
        bool agregarNuevoIdioma(string Nombre);
        Idioma* obtenerIdioma(string nombreIdioma);
        set<string> obtenerIdiomas();
        set<string> obtenerEstudiantes();
        set<string> obtenerSuscripcionesPendientes(string Nickname);
        set<string> obtenerSuscripciones(string Nickname);
        map<string, Idioma*> obtenerColeccionIdiomas();
};

#endif