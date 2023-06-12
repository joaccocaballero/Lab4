#include "../include/DTInscripcion.h"

DTInscripcion::DTInscripcion(int id, DTFecha fecha, bool Aprobacion, Curso * CursoInscripcion, Estudiante * EstudianteInscrito){
    this->id = id;
    this->fecha = fecha;
    this->Aprobacion = Aprobacion;
    this->CursoInscripcion = CursoInscripcion;
    this->EstudianteInscrito = EstudianteInscrito;
}

int DTInscripcion::obtenerIdInscripcion(){
    return id;
}
DTFecha DTInscripcion::obtenerFecha(){
    return fecha;
}
bool DTInscripcion::obtenerAprobacion(){
    return Aprobacion;
}
Curso* DTInscripcion::obtenerCursoInscripcion(){
    return CursoInscripcion;
}
Estudiante* DTInscripcion::obtenerEstudianteInscripto(){
    return EstudianteInscrito;
}

Inscripcion::~Inscripcion(){}