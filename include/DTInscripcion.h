#pragma once
#ifndef _DTINSCRIPCION
#define _DTINSCRIPCION

#include "DTFecha.h"
#include "Curso.h"

class Estudiante;

class DTInscripcion {
    private:
        int id;
        DTFecha Fecha;
        bool    Aprobacion;
        Curso * CursoInscripcion;
        Estudiante * EstudianteInscrito;
    public:
        DTInscripcion(int id, DTFecha fecha, bool Aprobacion, Curso * CursoInscripcion, Estudiante * EstudianteInscrito);
        int obtenerIdInscripcion();
        DTFecha obtenerFecha();
        bool obtenerAprobacion();
        Curso * obtenerCursoInscripcion();
        Estudiante *obtenerEstudianteInscripto();
        ~DTInscripcion();
};

#include "../include/Estudiante.h"

#endif