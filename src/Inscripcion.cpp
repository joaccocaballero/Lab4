#include "../include/Inscripcion.h"

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

Curso* Inscripcion::obtenerCurso(){
    return CursoInscripcion;
}

Inscripcion::~Inscripcion(){
    delete CursoInscripcion;
    delete EstudianteInscrito;
}

