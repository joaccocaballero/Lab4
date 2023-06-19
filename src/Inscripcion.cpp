#include "../include/Inscripcion.h"
#include <string>
#include <iostream>
using namespace std;
#include "../include/DTEstadisticaProfesor.h"


Inscripcion::Inscripcion(DTFecha fecha, Curso* curso, Estudiante* estudiante) {
    this->CursoInscripcion = curso;
    this->EstudianteInscrito = estudiante;
    this->Fecha = fecha;
    this->Aprobacion= false;
    this->estadistica = DTEstadisticaEstudiante(curso->obtenerNombre(), 0);
}

int Inscripcion::obtenerIdInscripcion(){
    return id;
}

bool Inscripcion::obtenerAprobacion(){
    return Aprobacion;
}

void Inscripcion::setAprobacion(bool a){
    Aprobacion = a;
}

Curso* Inscripcion::obtenerCurso(){
    return CursoInscripcion;
}
Estudiante* Inscripcion::obtenerEstudiante() { 
    return EstudianteInscrito; 
}

DTFecha Inscripcion::obtenerFecha() { 
    return Fecha; 
}
set<Ejercicio*> Inscripcion::obtenerEjerciciosAprobados(string nombreCurso){
    return ejerciciosAprobados[nombreCurso];
}

set<Leccion*> Inscripcion::obtenerLeccionesAprobadas(string nombreCurso){
    return leccionesAprobadas[nombreCurso];
}

void Inscripcion::agregarEjercicioAprobado(Ejercicio* ej, string nombreCurso){
    ejerciciosAprobados[nombreCurso].insert(ej);
}

void Inscripcion::agregarLeccionAprobada(Leccion* lec, string nombreCurso){
    leccionesAprobadas[nombreCurso].insert(lec);
}

Inscripcion::~Inscripcion(){
    EstudianteInscrito->eliminarInscripcion(this);
    
}
DTEstadisticaEstudiante Inscripcion::crearEstadisticaEstudiante(){
    int avance = 0;
    Curso* cursoIns = obtenerCurso();
    set<Ejercicio*> setAprobados = this->obtenerEjerciciosAprobados(CursoInscripcion->obtenerNombre());
    int aprobados = setAprobados.size();
    set<Leccion*> setTotales = cursoIns->obtenerLecciones();
    set<Leccion*>::iterator it;
    set<Ejercicio*> ejerciciosLecciones;
    for (it=setTotales.begin(); it!=setTotales.end(); ++it) {
        Leccion* current = *it;
        set<Ejercicio*> ejsleccion = current->obtenerEjerciciosLeccion();
        ejerciciosLecciones.insert(ejsleccion.begin(), ejsleccion.end());
    }
    int totales = ejerciciosLecciones.size();
    avance = (aprobados/ totales)*100;
    DTEstadisticaEstudiante estadistica= DTEstadisticaEstudiante(cursoIns->obtenerNombre(), avance);
    this->estadistica = estadistica;
    return estadistica; 
}

Inscripcion::~Inscripcion(){}

