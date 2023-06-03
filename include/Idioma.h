#pragma once
#ifndef _IDIOMA
#define _IDIOMA

#include <string>
#include <set>
#include <map>
#include "Usuario.h"
#include "Idioma.h"
#include "IObserver.h"

using namespace std;

class Usuario;
class Curso;

class Idioma{
    private:
        string Nombre;
        map<string, IObserver> Suscriptores;
    public:
        void AgregarSuscriptor(IObserver);
        void RemoverSuscriptor()
        string obtenerNombre();
        void NuevoCurso(Curso curso);
        set<Idioma> obtenerSuscripcionesPendientes(string Nickname);
        ~Idioma();
};

<<<<<<< HEAD
=======
#include "Usuario.h"
#include "Curso.h"

>>>>>>> 0df75013558da927cdc2eb538cca6b875247e2a8
#endif