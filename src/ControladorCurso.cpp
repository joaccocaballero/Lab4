#include <string>
#include "../include/ControladorCurso.h"
#include "../include/Idioma.h"
using namespace std;

ControladorCurso * ControladorCurso::instancia = NULL;

ControladorCurso::ControladorCurso(){}

ControladorCurso* ControladorCurso::getInstancia() {
  if (instancia == NULL) {
    instancia = new ControladorCurso();
  }
  return instancia;
}

void ControladorCurso::ingresarInfoCurso(string nombre, string Descripcion, EnumDificultad Dificultad){
    this->Nombre = nombre;
    this->Descripcion = Descripcion;
    this->Dificultad = Dificultad;
}

set<string> ControladorCurso::obtenerCursosHabilitados(){
    return manejadorCurso->obtenerHabilitados();
}

void ControladorCurso::ingresarCursosPrevios(set<string> nombresCursosPrevios){
    CursosPrevios = nombresCursosPrevios;
}

void ControladorCurso::seleccionarIdioma(string nomIdioma){
    Idioma *idiomaSeleccionado = manejadorIdioma->obtenerIdioma(nomIdioma);
    this->IdiomaSeleccionado = idiomaSeleccionado;
}

void ControladorCurso::confirmarEliminacion(string nombre){}

void ControladorCurso::confirmarAltaCurso() {
    set<Curso*> cursosPrevios = manejadorCurso->obtenerCursosPrevios(CursosPrevios);
    Curso* c = new Curso(false, Nombre, Descripcion, Dificultad, cursosPrevios, IdiomaSeleccionado);
    // si hay lecciones agregarlas, supongo que llamo a caso de uso desde main si usuario quiere meterle
    manejadorCurso->agregarCurso(c);
}

void ControladorCurso::asignarProfesor(string nickname) {
    Profesor* profesor = controladorUsuario->obtenerProfesor(nickname);
    ProfesorSeleccionado = profesor;
}

set<string> ControladorCurso::obtenerCursos(){
    set<string> cursosHabilitados;
    return cursosHabilitados;
}

set<string> ControladorCurso::obtenerCursosNoAprobados(string nombre){
    set<string> cursosHabilitados;
    return cursosHabilitados;
}

DTEjercicio ControladorCurso::seleccionarEjercicio(int id){}

bool ControladorCurso::validarEjercicio(){
    return true;
}

DTEstadisticaCurso ControladorCurso::obtenerEstadisticaCurso(string nombre){}

/*
ControladorCurso::~ControladorCurso(){
    delete instancia;
}*/