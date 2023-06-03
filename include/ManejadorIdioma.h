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
        bool existeNickname(string Nickname)
        void agregarUsuario(Usuario usuario)
        set<string> obtenerNombresIdiomas();
        Idioma obtenerIdioma(string nombreIdioma);
        set<string> obtenerIdiomas();
        set<string> obtenerEstudiantes();
        set<Idioma> obtenerSuscripcionesPendientes(string Nickname);
        

};

#endif