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

DTEstadisticaEstudiante Inscripcion::crearEstadisticaEstudiante(){
    int avance = 0;
    string Curso = "";
    set<Ejercicio*> setAprobados = this->obtenerEjerciciosAprobados(this->CursoInscripcion);
    int aprobados = setAprobados.size();
    Curso* cursoIns = this->obtenerCurso();
    set<Leccion*> setTotales = cursoIns->obtenerLecciones();
    set<Ejercicio*> ejerciciosLecciones;
    for (Leccion* leccion : setTotales) {
        set<Ejercicio*> ejsleccion = leccion->obtenerEjerciciosLeccion();
        ejerciciosLecciones.insert(ejsLeccion.begin(), ejerciciosLeccion.end());
    }
    int totales = ejerciciosLecciones.size();
    avance = (aprobados/ totales)*100;
    DTEstadisticaCurso estadistica= DTEstadisticaCurso(cursoIns->obtenerNombre(), avance);
    this->estadistica = estadistica;
    return estadistica; 
}

Inscripcion::~Inscripcion(){}

