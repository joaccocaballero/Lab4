#include <string>
#include <map>
#include "../include/ManejadorCurso.h"
#include <iostream>

ManejadorCurso* ManejadorCurso::instancia = NULL;

ManejadorCurso::ManejadorCurso(){}

ManejadorCurso* ManejadorCurso::getManejadorC(){
  if (instancia==NULL)
  {
      instancia = new ManejadorCurso();
  }
  return instancia;
}

bool ManejadorCurso::existeNickname(string nickname){}

void ManejadorCurso::agregarCurso(Curso *c){
  ColeccionDeCursos.insert(make_pair(c->obtenerNombre(), c));
}
set<string> ManejadorCurso::obtenerHabilitados(){
  set<string> cursosHabilitados;
  map<string, Curso*>::iterator it;
  for (it = ColeccionDeCursos.begin(); it!=ColeccionDeCursos.end(); ++it){
    if (it->second->obtenerHabilitacion() == true) {
      cursosHabilitados.insert(it->first);
    }
  }
  return cursosHabilitados;
}

set<string> ManejadorCurso::obtenerCursosNoHabilitados(){
  set<string> cursosNoHabilitados;
  map<string, Curso*>::iterator it;
  for (it = ColeccionDeCursos.begin(); it != ColeccionDeCursos.end(); ++it) {
    if (it->second->obtenerHabilitacion() == false) {
      cursosNoHabilitados.insert(it->first);
    }
  }
  return cursosNoHabilitados;
}

Idioma* ManejadorCurso::obtenerIdioma(string nomIdioma){}

set<string> ManejadorCurso::obtenerCursos(){
  set<string> retorno;
  map<string, Curso*>::iterator it;
  for (it = ColeccionDeCursos.begin(); it != ColeccionDeCursos.end();
      ++it) {
      retorno.insert(it->first);
  }
  return retorno;
}

bool ManejadorCurso::confirmarHabilitacion(string nombre){
  bool confirmado = false;
  Curso * c =ColeccionDeCursos[nombre];
  if (c != NULL) {
    set<Leccion*> setLec= c->obtenerLecciones();
    set<Leccion*>::iterator it2;
    for(it2= setLec.begin();it2 != setLec.end(); ++it2){
      Leccion *current = *it2;
      set<Ejercicio*> setEj = current->obtenerEjerciciosLeccion();
      if(!setLec.empty() || !setEj.empty()){
        //ninguno esta vacio
        c->setHabilitacion(true);
        confirmado = true;
      }else{
        confirmado = false;
      }
    }
    return confirmado;
  } else {
    cout << "Curso no encontrado" << endl;
    return confirmado;
  }
}

void ManejadorCurso::eliminarCurso(string nombre){}
set<string> ManejadorCurso::obtenerCursosNoAprobados(){}

Curso* ManejadorCurso::obtenerCurso(string nombre){
  map<string, Curso*>::iterator it;
  cout << nombre << endl;
  it=ColeccionDeCursos.find(nombre);
  if (it != ColeccionDeCursos.end()) {
    return it->second;
  } else {
    return nullptr;
  }
}

set<string> ManejadorCurso::obtenerEjerciciosPendientesCurso(Curso c){}

set<Curso*> ManejadorCurso::obtenerCursosPrevios(set<string> nombrePrevios){
  set<Curso*> cursosPrevios;
  map<string, Curso*>::iterator it;
  for (it = ColeccionDeCursos.begin(); it!=ColeccionDeCursos.end(); ++it){
    if (nombrePrevios.count(it->first) == 1) {
      cursosPrevios.insert(it->second);
    }
  }
  return cursosPrevios;
}

DTEjercicio ManejadorCurso::obtenerEjercicio(int id){}
bool ManejadorCurso::respuestaEjercicio(string sol){}
DTEstadisticaCurso ManejadorCurso::obtenerEstadisticaCurso(string nombre){}