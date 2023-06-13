
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

void Estudiante::agregarInscripcion(Inscripcion*i){
  InscripcionesCursos.insert(i);
}



set<DTEstadisticaEstudiante> obtenerEstadisticasEstudiante(string Nickname){}

Estudiante ::~Estudiante() {}