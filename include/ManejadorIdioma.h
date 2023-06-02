#include <string>
#include <set>
#include "Usuario.h"
#include "Idioma.h"

class ManejadorIdioma {
    private:
        static ManejadorIdioma * manejadorI
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
        

}