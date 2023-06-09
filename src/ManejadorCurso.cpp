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

  void ManejadorCurso::eliminarCurso(string nombre){}
  set<string> ManejadorCurso::obtenerCursosNoAprobados(){}
  
  Curso* ManejadorCurso::seleccionarCurso(string nombre){
    map<string, Curso*>::iterator it;
    it=ColeccionDeCursos.find(nombre);
    return it->second;
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