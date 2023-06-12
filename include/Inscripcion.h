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
        Inscripcion(int id, DTFecha fecha, bool Aprobacion, Curso * CursoInscripcion, EStudiante * EstudianteInscrito);
        int obtenerIdInscripcion();
        DTFecha obtenerFecha();
        bool obtenerAprobacion();
        Curso * obtenerCurso();
        Estudiante *obtenerEstudiante();
        ~Inscripcion();
};

#include "../include/Estudiante.h"

#endif