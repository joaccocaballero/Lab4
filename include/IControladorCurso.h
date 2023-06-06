#pragma once
#ifndef _ICONTROLADORCURSO
#define _ICONTROLADORCURSO

#include <string>
#include "Usuario.h"
#include "Curso.h"
#include "Profesor.h"
#include "DTEstadisticaCurso.h"
using namespace std;
class IControladorCurso {
    public:
        virtual void ingresarInfoCurso(string nombre,  string Descripcion, EnumDificultad Dificultad) = 0;
        virtual void asignarProfesor(string nickname) = 0;
        virtual set<string> obtenerCursosHabilitados() = 0;
        virtual void ingresarCursosPrevios(set<string> nombresCursosPrevios) = 0;
        virtual void seleccionarIdioma(string nomIdioma) = 0;
        virtual void confirmarEliminacion(string nombre) = 0;
        virtual void confirmarAltaCurso() = 0;
        virtual set<string> obtenerCursos() = 0;
        virtual set<string> obtenerCursosNoAprobados(string nombre) = 0;
        virtual void seleccionarCurso(string nombre) = 0;
        virtual set<string> obtenerEjerciciosPendientes() = 0;
        virtual DTEjercicio seleccionarEjercicio(int id) = 0;
        virtual bool validarEjercicio() = 0;
        virtual DTEstadisticaCurso obtenerEstadisticaCurso(string nombre) = 0;
        virtual ControladorCurso getInstancia() = 0;
        virtual ~IControladorCurso(){};
};

#endif