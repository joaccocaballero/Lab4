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
  Curso * c = ColeccionDeCursos[nombre];
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

void ManejadorCurso::eliminarCurso(string nombre){
  //Eliminar del conjunto Cursos Previos, el curso que voy a eliminar
  map<string, Curso*>::iterator it1;
  Curso * CursoAEliminar = obtenerCurso(nombre);
  for(auto it1=ColeccionDeCursos.begin(); it1 != ColeccionDeCursos.end(); ++it1){
    Curso* current = it1->second;
    if(current->esPrevio(CursoAEliminar)){
      current->eliminarCursoPrevio(CursoAEliminar);
    }
  }

  map<string, Curso*>::iterator it2 = ColeccionDeCursos.find(nombre);
  Curso* aEliminar = ColeccionDeCursos[nombre];
  delete aEliminar;
  ColeccionDeCursos.erase(it2);
    
}

set<string> ManejadorCurso::obtenerCursosNoAprobados(){}

Curso* ManejadorCurso::obtenerCurso(string nombre){
  map<string, Curso*>::iterator it;
  it=ColeccionDeCursos.find(nombre);
  if (it != ColeccionDeCursos.end()) {
    return it->second;
  } else {
    return nullptr;
  }
}

set<string> ManejadorCurso::obtenerEjerciciosPendientesCurso(Curso c){}

set<DTCursoDisponible> ManejadorCurso::obtenerCursosDisponibles(set<Curso*> cursosYaInscriptos, set<Curso*> cursosAprobados) {
  set<DTCursoDisponible> cursosDisponibles;
  map<string, Curso*>::iterator it;
  for (it = ColeccionDeCursos.begin(); it!=ColeccionDeCursos.end(); ++it){
      Curso* current = it->second;
      bool cumplePrevias = true;
      //Chequeo si el curso tiene previas, si no tiene no entro.
      if(!current->obtenerPrevias().empty()){
        //Recorro conjunto de previas y chequeo si están cada previa pertenece a conjunto de aprobados
        for (const auto puntero : current->obtenerPrevias()) {
          if (cursosAprobados.find(puntero) == cursosAprobados.end()) {
            cumplePrevias = false; //previa no pertenece
            break;
          }
        }
      }
      if (!cumplePrevias) { //las previas no se cumplen
        continue;
      }
      else{
        bool estaInscripto = cursosYaInscriptos.find(it->second) != cursosYaInscriptos.end();
        if(current->obtenerHabilitacion() && !estaInscripto) { //Chequeo si el curso está habilitado y no estoy inscrito
          string idioma = current->getIdioma()->obtenerNombre();
          int ctdEjercicios = cantidadEjercicios(current->obtenerLecciones());
          int ctdLecciones = current->obtenerLecciones().size();
          DTCursoDisponible toPush = DTCursoDisponible(current->obtenerNombre(), current->obtenerDescripcion(),idioma, 
          current->obtenerNombreProf(), ctdLecciones, ctdEjercicios, current->obtenerDificultad());
          cursosDisponibles.insert(toPush); 
        }
      }
  }
  return cursosDisponibles;
}

int ManejadorCurso::cantidadEjercicios(set<Leccion*> leccs) {
  //itero y sumo ejercicios.length a variable
  int res = 0;
  set<Leccion*>::iterator it;
  for (it = leccs.begin(); it!=leccs.end(); ++it){
    Leccion*current = *it;
    res = res + current->obtenerEjerciciosLeccion().size();
  }
  return res;
}

set<Curso*> ManejadorCurso::obtenerCursosPrevios(set<string> nombrePrevios){
  set<Curso*> cursosPrevios;
  map<string, Curso*>::iterator it;
  if(!nombrePrevios.empty()){
    for (it = ColeccionDeCursos.begin(); it != ColeccionDeCursos.end(); ++it) {
      if (nombrePrevios.count(it->first) == 1) {
        cursosPrevios.insert(it->second);
      }
    }
  }
  return cursosPrevios;
}

DTEjercicio ManejadorCurso::obtenerEjercicio(int id){}
bool ManejadorCurso::respuestaEjercicio(string sol){}
DTEstadisticaCurso ManejadorCurso::obtenerEstadisticaCurso(string nombre){}