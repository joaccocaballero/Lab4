#include <string>
#include <iostream>
#include "../include/ControladorCurso.h"
#include "../include/ControladorUsuario.h"
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

void ControladorCurso::ingresarInfoLeccion(string Tema, string Objetivo){
    this->TemaLeccion = Tema;
    this->ObjetivoLeccion = Objetivo;
}

set<string> ControladorCurso::obtenerCursosHabilitados(){
    ManejadorCurso * manejador = manejadorCurso->getManejadorC();
    return manejador->obtenerHabilitados();
}

set<string> ControladorCurso::obtenerCursosNoHabilitados(){
    ManejadorCurso * manejador = manejadorCurso->getManejadorC();
    set<string> col = manejador->obtenerCursosNoHabilitados();
    return col;
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

void ControladorCurso::seleccionarCurso(string nomCurso) {
    ManejadorCurso * manejador = manejadorCurso->getManejadorC();
    Curso *cursoSeleccionado = manejador->obtenerCurso(nomCurso);
    this->CursoSeleccionado = cursoSeleccionado;
}

void ControladorCurso::confirmarAltaCurso() {
    ManejadorCurso* manejador = manejadorCurso->getManejadorC();
    set<Curso*> cursosPrevios = manejador->obtenerCursosPrevios(CursosPrevios);
    set<Leccion*> col;
    Curso* c = new Curso(false, Nombre, Descripcion, Dificultad, cursosPrevios, IdiomaSeleccionado, col);
    // si hay lecciones agregarlas, supongo que llamo a caso de uso desde main si usuario quiere meterle

    manejador->agregarCurso(c);
    cout << "Curso creado correctamente!" << endl;
}

void ControladorCurso::confirmarAltaLeccion(){
    ManejadorCurso* manejador = manejadorCurso->getManejadorC();
    cout << "Llegué confalta!" << endl;
    set<Ejercicio*> col{};
    Leccion * l = new Leccion(TemaLeccion, ObjetivoLeccion, col);
    CursoSeleccionado->agregarLeccion(l);
    cout << "Lección creada correctamente!" << endl;
}

void ControladorCurso::asignarProfesor(string nickname) {
    ControladorUsuario *ctrlU = controladorUsuario->getInstancia();
    Profesor* profesor = ctrlU->obtenerProfesor(nickname);
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