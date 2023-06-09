#include <string>
#include "../include/ControladorCurso.h"
#include "../include/ManejadorCurso.h"
#include "../include/ManejadorIdioma.h"
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
    ManejadorCurso * manejador = manejadorCurso->getManejadorC();
    return manejador->obtenerHabilitados();
}

void ControladorCurso::ingresarCursosPrevios(set<string> nombresCursosPrevios){
    CursosPrevios = nombresCursosPrevios;
}

void ControladorCurso::seleccionarIdioma(string nomIdioma){
    ManejadorIdioma * manejador = manejadorIdioma->getManejadorI();
    Idioma *idiomaSeleccionado = manejador->obtenerIdioma(nomIdioma);
    this->IdiomaSeleccionado = idiomaSeleccionado;
}

void ControladorCurso::confirmarEliminacion(string nombre){}

void ControladorCurso::seleccionarCurso(string nombre) {}

void ControladorCurso::confirmarAltaCurso() {
    ManejadorCurso* manejador = manejadorCurso->getManejadorC();
    set<Curso*> cursosPrevios = manejador->obtenerCursosPrevios(CursosPrevios);
    Curso* c = new Curso(false, Nombre, Descripcion, Dificultad, cursosPrevios, IdiomaSeleccionado);
    // si hay lecciones agregarlas, supongo que llamo a caso de uso desde main si usuario quiere meterle
    manejador->agregarCurso(c);
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

DTEjercicio ControladorCurso::seleccionarEjercicio(int id){

}

bool ControladorCurso::validarEjercicio(){
    return true;
}

DTEstadisticaCurso ControladorCurso::obtenerEstadisticaCurso(string nombre){

}

set<string> ControladorCurso::obtenerEjerciciosPendientes(){}


ControladorCurso::~ControladorCurso(){
    delete instancia;
}