#include "../include/Inscripcion.h"

Inscripcion::Inscripcion(int id, DTFecha fecha, bool Aprobacion, Curso * CursoInscripcion, Estudiante * EstudianteInscrito){
    this->id = id;
    this->fecha = fecha;
    this->Aprobacion = Aprobacion;
    this->CursoInscripcion = CursoInscripcion;
    this->EstudianteInscrito = EstudianteInscrito;
}

int Inscripcion::obtenerIdInscripcion(){
    return id;
}
DTFecha Inscripcion::obtenerFecha(){
    return fecha;
}
bool Inscripcion::obtenerAprobacion(){
    return Aprobacion;
}
Curso* Inscripcion::obtenerCursoInscripcion(){
    return CursoInscripcion;
}
Estudiante* Inscripcion::obtenerEstudianteInscripto(){
    return EstudianteInscrito;
}

Inscripcion::~Inscripcion(){}