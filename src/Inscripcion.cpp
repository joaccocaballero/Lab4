#include "../include/Inscripcion.h"
#include <string>
#include <iostream>
using namespace std;

Inscripcion::Inscripcion(DTFecha fecha, Curso* curso, Estudiante* estudiante) {
    this->CursoInscripcion = curso;
    this->EstudianteInscrito = estudiante;
    this->Fecha = fecha;
    this->Aprobacion= false;
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

