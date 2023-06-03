#include <string>
#include <set>
#include <map>
#include "Usuario.h"
#include "Idioma.h"

using namespace std;

class Idioma{
    private:
        string Nombre;
        map<string, Usuario> Suscriptores;
    public:
        void AgregarSuscriptor(Usuario);
        string obtenerNombre();
        void NuevoCurso(Curso curso);
        set<Idioma> obtenerSuscripcionesPendientes(Nickname string);
        ~Idioma();
};