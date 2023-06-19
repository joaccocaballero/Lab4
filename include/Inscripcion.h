#pragma once
#ifndef _INSCRIPCION
#define _INSCRIPCION

#include "DTFecha.h"
#include "Curso.h"
#include <map>

class Estudiante;
class Curso;
class DTEstadisticaEstudiante;

class Inscripcion {
    private:
        int id;
        DTFecha Fecha;
        bool    Aprobacion;
        Curso * CursoInscripcion;
        Estudiante * EstudianteInscrito;
        DTEstadisticaEstudiante estadistica;
        map<string,set<Ejercicio*>> ejerciciosAprobados;
        map<string, set<Leccion*>> leccionesAprobadas;
       public:
        Inscripcion();
        Inscripcion(DTFecha fecha, Curso* curso, Estudiante* estudiante);
        int obtenerIdInscripcion();
        bool obtenerAprobacion();
        void setAprobacion(bool a);
        DTFecha obtenerFecha();
        Curso* obtenerCurso();
        DTEstadisticaEstudiante crearEstadisticaEstudiante();
        void agregarEjercicioAprobado(Ejercicio* ej, string nombreCurso);
        void agregarLeccionAprobada(Leccion* lec, string nombreCurso);
        set<Ejercicio*> obtenerEjerciciosAprobados(string nombreCurso);
        set<Leccion*> obtenerLeccionesAprobadas(string nombreCurso);
        Estudiante * obtenerEstudiante();
        ~Inscripcion();
};

#include "../include/Estudiante.h"
#include "DTEstadisticaEstudiante.h"

#endif