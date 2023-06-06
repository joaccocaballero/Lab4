#include <string>
#include "../include/ControladorCurso.h"
using namespace std;

ControladorCurso::ControladorCurso(){
    if (instancia == NULL){
        instancia = new ControladorCurso();
    }
    return instancia; 
}

void ControladorCurso::altaProfesor() {}

bool ControladorCurso::confirmarAltaEstudiante(){}

bool ControladorCurso::confirmarAltaProfesor(){}

void ControladorCurso::ingresarInfoCurso(string nombre, string Descripcion, EnumDificultad Dificultad){
    this->Nombre = nombre;
    this->Descripcion = Descripcion;
    this->Dificultad = dificultad;
}

void ControladorCurso::asignarProfesor(string nickname){}

set<string> ControladorCurso::obtenerCursosHabilitados(){
    return manejadorCurso->obtenerHabilitados();
}

void ControladorCurso::ingresarCursosPrevios(set<string> nombresCursosPrevios){
    CursosPrevios = nombreCursosPrevios;
}

void ControladorCurso::seleccionarIdioma(string nomIdioma){
    Idioma idiomaSeleccionado = controladorUsuario->manejadorIdioma->obtenerIdioma(nomIdioma);
    this->IdiomaSeleccionado = idiomaSeleccionado;
}

void ControladorCurso::confirmarEliminacion(string nombre){}

void ControladorCurso::confirmarAltaCurso() {
    set<Curso*> cursosPrevios = manejadorCurso->obtenerCursosPrevios(CursosPrevios);
    Curso* c = new Curso(false, Nombre, Descripcion, Dificultad, IdiomaSeleccionado, cursosPrevios);
    // si hay lecciones agregarlas, supongo que llamo a caso de uso desde main si usuario quiere meterle
    manejadorCurso->agregarCurso(c);
}

void ControladorCurso::asignarProfesor(string nickname) {
    Profesor profesor = ControladorUsuario.obtenerProfesor(nickname);
    ProfesorSeleccionado = profesor;
}

set<string> ControladorCurso::obtenerCursos(){
    set<string> cursosHabilitados;
    return cursosHabilitados;
}

Profesor ControladorCurso::obtenerProfesor(){
    return ProfesorSeleccionado;
}

set<string> ControladorCurso::obtenerCursosNoAprobados(string nombre){
    set<string> cursosHabilitados;
    return cursosHabilitados;
}

DTEjercicio ControladorCurso::seleccionarEjercicio(){}
bool ControladorCurso::validarEjercicio(){
    return true;
}

DTEstadisticaCurso ControladorCurso::obtenerEstadisticaCurso(string nombre){}

ControladorCurso::~ControladorCurso(){}