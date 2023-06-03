#pragma once
#ifndef _INSCRIPCION
#define _INSCRIPCION


#ifndef INSCRIPCION
#define INSCRIPCION

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
        int obtenerIdInscripcion();
        ~Inscripcion();
};

#include "../include/Estudiante.h"

#endif