#pragma once
#ifndef _IDIOMA
#define _IDIOMA

#include <string>
#include <set>
#include <map>
#include <vector>

#include "Usuario.h"
#include "IObserver.h"

using namespace std;

class Usuario;
class Curso;

class Idioma{
    private:
        string Nombre;
        map<string, IObserver*> Suscriptores;
    public:
        Idioma(string Nombre);
        void AgregarSuscriptor(string nickname, IObserver* observer);
        void RemoverSuscriptor(string nickname);
        string obtenerNombre();
        void NuevoCurso(Curso curso);
        bool esSuscriptor(string Nickname);
        vector<string> obtenerSuscriptores();
        set<string> obtenerSuscripcionesPendientes(string Nickname);
        ~Idioma();
};

#include "Usuario.h"
#include "Curso.h"

#endif