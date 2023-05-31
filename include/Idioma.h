#include <string>
#include <set>
#include "Usuario.h"

using namespace std;

class Idioma{
    private:
        string Nombre;
    public:
        void AgregarSuscriptor(Usuario);
        string obtenerNombre();
        void NuevoCurso(Curso curso);
        set<Idioma> obtenerSuscripcionesPendientes(Nickname string);
}