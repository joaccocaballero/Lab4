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
  void ManejadorCurso::agregarCurso(Curso c){}
  set<string> ManejadorCurso::obtenerHabilitados(){}
  Idioma ManejadorCurso::obtenerIdioma(string nomIdioma){}
  set<string> ManejadorCurso::obtenerCursos(){}
  void ManejadorCurso::eliminarCurso(string nombre){}
  set<string> ManejadorCurso::obtenerCursosNoAprobados(){}
  Curso ManejadorCurso::seleccionarCurso(string nombre){}
  set<string> ManejadorCurso::obtenerEjerciciosPendientesCurso(Curso c){}
  DTEjercicio ManejadorCurso::obtenerEjercicio(int id){}
  bool ManejadorCurso::respuestaEjercicio(string sol){}
  DTEstadisticaCurso ManejadorCurso::obtenerEstadisticaCurso(string nombre){}