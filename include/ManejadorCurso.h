#pragma once
#ifndef _MANEJADORCURSO
#define _MANEJADORCURSO

#include <string>
#include <map>
#include "Curso.h"
#include "Idioma.h"
#include "Ejercicio.h"
#include "Leccion.h"
#include "DTCursoDisponible.h"
#include "DTEstadisticaProfesor.h"

using namespace std;

class ManejadorCurso {
 private:
  static ManejadorCurso* instancia;
  map<string, Curso*> ColeccionDeCursos;
  set<DTEstadisticaProfesor> EstadisticasProfesor;
  ManejadorCurso();

 public:
  static ManejadorCurso* getManejadorC();
  bool existeNickname(string nickname);
  void agregarCurso(Curso *c);
  set<string> obtenerHabilitados();
  Idioma* obtenerIdioma(string nomIdioma);
  set<string> obtenerCursos();
  void eliminarCurso(string nombre);
  set<string> obtenerCursosNoAprobados();
  Curso* obtenerCurso(string nombre);
  set<string> obtenerEjerciciosPendientesCurso(Curso c);
  DTEjercicio obtenerEjercicio(int id);
  bool respuestaEjercicio(string sol);
  set<Curso*> obtenerCursosPrevios(set<string> cursosPrevios);
  set<string> obtenerCursosNoHabilitados();
  DTEstadisticaCurso obtenerEstadisticaCurso(string nombre);
  int cantidadEjercicios(set<Leccion*> lecs);
  set<DTEstadisticaProfesor> obtenerEstadisticasProfesor(
    string Nickname);
  set<DTCursoDisponible> obtenerCursosDisponibles(set<Curso*> cursos, set<Curso*> cursosAprobados);
  bool confirmarHabilitacion(string nombre);
};

#endif