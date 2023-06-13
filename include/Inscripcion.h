#pragma once
#ifndef _INSCRIPCION
#define _INSCRIPCION

#include "DTFecha.h"
#include "Curso.h"

class Estudiante;

class Inscripcion {
    private:
        int id;
        DTFecha Fecha;
        bool    Aprobacion;
        Curso * CursoInscripcion;
        Estudiante * EstudianteInscrito;
    public:
        Inscripcion();
        Inscripcion(DTFecha fecha, Curso* curso, Estudiante* estudiante);
        int obtenerIdInscripcion();
        Curso* obtenerCurso();
        ~Inscripcion();
};

#include "../include/Estudiante.h"

#endif