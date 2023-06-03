#ifndef IDIOMA
#define IDIOMA

#include <string>
#include <set>
#include <map>
#include "Usuario.h"
#include "Idioma.h"
#include "IObserver.h"

using namespace std;

class Idioma{
    private:
        string Nombre;
        map<string, IObserver> Suscriptores;
    public:
        void AgregarSuscriptor(IObserver);
        void RemoverSuscriptor()
        string obtenerNombre();
        void NuevoCurso(Curso curso);
        set<Idioma> obtenerSuscripcionesPendientes(Nickname string);
        ~Idioma();
};

#endif