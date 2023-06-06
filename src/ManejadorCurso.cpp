#include <string>
#include <map>
#include "../include/ManejadorCurso.h"

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
    ColeccionDeCursos.insert(make_pair(c->obtenerNombre(), c))
  }
  
  set<string> ManejadorCurso::obtenerHabilitados(){
    set<string> cursosHabilitados;
    map<string, Curso*>::iterator it;
    for (it = ColeccionDeCursos.begin(); it!=dict.end(); ++it){
      if (it.second.habilitacion == true) {
        cursosHabilitados.insert(it->first);
      }
    }
    return cursosHabilitados;
  }
  Idioma ManejadorCurso::obtenerIdioma(string nomIdioma){
  }
  set<string> ManejadorCurso::obtenerCursos(){}
  void ManejadorCurso::eliminarCurso(string nombre){}
  set<string> ManejadorCurso::obtenerCursosNoAprobados(){}
  Curso ManejadorCurso::seleccionarCurso(string nombre){}
  set<string> ManejadorCurso::obtenerEjerciciosPendientesCurso(Curso c){}
  
  set<Curso*> ManejadorCurso::obtenerCursosPrevios(set<string> nombrePrevios){
    set<Curso*> cursosPrevios;
    map<string, Curso*>::iterator it;
    for (it = ColeccionDeCursos.begin(); it!=dict.end(); ++it){
      if (nombrePrevios.count(it.first)) {
        cursosPrevios.insert(it->second);
      }
    }
    return cursosPrevios;
  }

  DTEjercicio ManejadorCurso::obtenerEjercicio(int id){}
  bool ManejadorCurso::respuestaEjercicio(string sol){}
  DTEstadisticaCurso ManejadorCurso::obtenerEstadisticaCurso(string nombre){}