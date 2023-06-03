#include <string>
#include <map>
#include "Curso.h"
#include "Idioma.h"
#include "Ejercicio.h"

using namespace std;

class ManejadorCurso {
 private:
  static ManejadorCurso* instancia;
  map<string, Curso*> ColeccionDeCursos;
  ManejadorCurso();

 public:
  static ManejadorCurso* getInstancia();
  bool existeNickname(string nickname);
  void agregarCurso(Curso c);
  set<string> obtenerHabilitados();
  Idioma obtenerIdioma(string nomIdioma);
  set<string> obtenerCursos();
  void eliminarCurso(string nombre);
  set<string> obtenerCursosNoAprobados();
  Curso seleccionarCurso(string nombre);
  set<string> obtenerEjerciciosPendientesCurso(Curso c);
  DTEjercicio obtenerEjercicio(int id);
  bool respuestaEjercicio(string sol);
  DTEstadisticaCurso obtenerEstadisticaCurso(string nombre);
};