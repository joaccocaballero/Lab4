#pragma once
#ifndef _IDIOMA
#define _IDIOMA

#include <string>
#include <set>
#include <map>

using namespace std;

class Usuario;
class Curso;

class Idioma{
    private:
        string Nombre;
        map<string, Usuario> Suscriptores;
    public:
        void AgregarSuscriptor(Usuario);
        string obtenerNombre();
        void NuevoCurso(Curso curso);
        set<Idioma> obtenerSuscripcionesPendientes(string Nickname);
        ~Idioma();
};

#include "Usuario.h"
#include "Curso.h"

#endif