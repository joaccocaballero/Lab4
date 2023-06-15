
#include <set>
#include <string>
 
#include "../include/Estudiante.h"
#include "../include/Idioma.h"
#include "../include/DTFecha.h"

Estudiante::Estudiante(string Nickname, string Contrasenia, string Nombre,
                       string Descripcion, string PaisResidencia,
                       DTFecha FechaNacimiento)
    : Usuario(Nickname, Contrasenia, Nombre, Descripcion) {
  this->PaisResidencia = PaisResidencia;
  this->FechaNacimiento = FechaNacimiento;
}

string Estudiante::obtenerPais(){
  return PaisResidencia;
}

set<Inscripcion*> Estudiante::obtenerInscripciones(){
  return InscripcionesCursos;
}

Inscripcion* Estudiante::obtenerInscripcionCurso(string nombreCurso){
  Inscripcion* retorno = NULL;
  for (Inscripcion* i : InscripcionesCursos) {
    if (i->obtenerCurso()->obtenerNombre() == nombreCurso) {
      // El objeto con el atributo buscado fue encontrado
      retorno = i;
      break;
    }
  }
  return retorno;
}

void Estudiante::agregarInscripcion(Inscripcion*i){
  InscripcionesCursos.insert(i);
}



set<DTEstadisticaEstudiante> obtenerEstadisticasEstudiante(string Nickname){}

Estudiante ::~Estudiante() {}