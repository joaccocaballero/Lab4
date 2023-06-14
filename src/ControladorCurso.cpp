#include <string>
#include <iostream>
#include "../include/ControladorCurso.h"
#include "../include/ControladorUsuario.h"
#include "../include/ManejadorCurso.h"
#include "../include/ManejadorIdioma.h"
#include "../include/Idioma.h"
#include "../include/Ejercicio.h"
#include "../include/CompletarFrase.h"
#include "../include/Traducir.h"
#include "../include/Inscripcion.h"

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

void ControladorCurso::ingresarInfoEjercicio(string Descripcion){
    this->DescripcionEjercicio = Descripcion;
}

void ControladorCurso::agregarDatosCompletar(string frase, string solucion){
    this->frase = frase;
    this->solucion = solucion;
}

void ControladorCurso::agregarDatosTraducir(string frase, string solucion) {
    this->frase = frase;
    this->solucion = solucion;
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

bool ControladorCurso::confirmarHabilitacion(string nombre){
    ManejadorCurso* manejador = manejadorCurso->getManejadorC();
    bool fueHabilitado =  manejador->confirmarHabilitacion(nombre);
    return fueHabilitado;
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
    ManejadorCurso* manejador = manejadorCurso->getManejadorC();
    Curso *cursoSeleccionado = manejador->obtenerCurso(nomCurso);
    CursoSeleccionado = cursoSeleccionado;
}

void ControladorCurso::seleccionarLeccion(string nomLeccion){
    Leccion* leccionSeleccionada = CursoSeleccionado->obtenerLeccion(nomLeccion);
    LeccionSeleccionada = leccionSeleccionada;
}

void ControladorCurso::confirmarAltaCurso() {
    ManejadorCurso* manejador = manejadorCurso->getManejadorC();
    set<Curso*> cursosPrevios = manejador->obtenerCursosPrevios(CursosPrevios);
    set<Leccion*> col;
    set<Inscripcion*> colIns;
    Curso* c = new Curso(false, Nombre, Descripcion, Dificultad, cursosPrevios, IdiomaSeleccionado, col, NicknameProfesor, colIns);
    // si hay lecciones agregarlas, supongo que llamo a caso de uso desde main si usuario quiere meterle

    manejador->agregarCurso(c);
    cout << "Curso creado correctamente!" << endl;
}

void ControladorCurso::confirmarAltaLeccion(){
    ManejadorCurso* manejador = manejadorCurso->getManejadorC();
    set<Ejercicio*> col;
    Leccion * l = new Leccion(TemaLeccion, ObjetivoLeccion, col);
    CursoSeleccionado->agregarLeccion(l);
    cout << "Lección creada correctamente!" << endl;
}

void ControladorCurso::confirmarAltaEjercicio(EnumEjercicios tipo){
    if(tipo == CompletarPalabras){
        set<Ejercicio*> col = LeccionSeleccionada-> obtenerEjerciciosLeccion();
        int idEjercicio = col.size() + 1;
        CompletarFrase * c = new CompletarFrase(idEjercicio, frase, DescripcionEjercicio, tipo, solucion);
        LeccionSeleccionada->agregarEjercicio(c);
        cout << "Ejercicio creado correctamente!" << endl;
    }
    else if (tipo == TraducirFrase){
        set<Ejercicio*> col = LeccionSeleccionada->obtenerEjerciciosLeccion();
        int idEjercicio = col.size() + 1;
        Traducir * t = new Traducir(idEjercicio, frase, DescripcionEjercicio, tipo, solucion);
        LeccionSeleccionada->agregarEjercicio(t);
        cout << "Ejercicio creado correctamente!" << endl;
    }

}

void ControladorCurso::asignarProfesor(string nickname) {
    ControladorUsuario *ctrlU = controladorUsuario->getInstancia();
    Profesor* profesor = ctrlU->obtenerProfesor(nickname);
    NicknameProfesor = nickname;
    ProfesorSeleccionado = profesor;
}

set<string> ControladorCurso::obtenerCursos(){
    ManejadorCurso* manejador = manejadorCurso->getManejadorC();
    return manejador->obtenerCursos();
}

set<string> ControladorCurso::obtenerCursosNoAprobados(string nombre){
    set<string> cursosHabilitados;
    return cursosHabilitados;
}

set<string> ControladorCurso::obtenerLecciones(){
    set<string> retorno;
    set<Leccion*> col =  CursoSeleccionado->obtenerLecciones();
    set<Leccion*>::iterator it;
    for(it=col.begin(); it!=col.end(); ++it){
        Leccion* current = *it;
        retorno.insert(current->obtenerTema());
    }
    return retorno;
}

DTCurso ControladorCurso::obtenerInfoCurso(string nombre){
    ManejadorCurso* manejador = manejadorCurso->getManejadorC();
    Curso * c = manejador->obtenerCurso(nombre);
    DTCurso retorno = DTCurso(c->obtenerNombre(), c->obtenerDescripcion(),c->obtenerDificultad(),
    c->getIdioma()->obtenerNombre(), c->obtenerNombreProf(),c->obtenerHabilitacion(), c->obtenerSetDTLeccion(),
    c->obtenerSetDTInscripcion());

    return retorno;
}
set<DTCursoDisponible> ControladorCurso::obtenerCursosDisponibles(string nickname) {
    // traigo inscripciones del estudiante, paso nombre de curso a set, y armo set de cursos que no esten en ese set y esten habilitados
    ControladorUsuario *ctrlU = controladorUsuario->getInstancia();
    ManejadorCurso *maneC = manejadorCurso->getManejadorC();
    set<Inscripcion*> inscripciones = ctrlU->obtenerInscripcionesEstudiante(nickname);
    set<Curso*> cursosYaInscriptos;
    set<Curso*> cursosAprobados;
    set<Inscripcion*>::iterator it;
    for(it=inscripciones.begin(); it!=inscripciones.end(); ++it){
        Inscripcion* current = *it;
        cursosYaInscriptos.insert(current->obtenerCurso());
        if (current->obtenerAprobacion() == true) {
            cursosAprobados.insert(current->obtenerCurso());
        }
    }
    return maneC->obtenerCursosDisponibles(cursosYaInscriptos, cursosAprobados);
}

bool ControladorCurso::confirmarInscripcion(string nickname, string nombreCurso) {
    ControladorUsuario *ctrlU = controladorUsuario->getInstancia();
    ManejadorCurso *manejador = manejadorCurso->getManejadorC();
    Estudiante* e = ctrlU->obtenerEstudiante(nickname);
    Curso* c = manejador->obtenerCurso(nombreCurso);
    DTFecha aCambiar = DTFecha(1,1,1);
    Inscripcion* inscripcion = new Inscripcion(aCambiar, c, e);
    c->agregarInscripcion(inscripcion);
    return ctrlU->confirmarAltaInscripcion(e, inscripcion);
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