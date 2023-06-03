
#include <set>
#include <string>
 
#include "../include/Estudiante.h"
#include "../include/Idioma.h"
#include "../include/DTFecha.h"

Estudiante ::Estudiante(string PaisResidencia, DTFecha FechaNacimiento){
  this->PaisResidencia = PaisResidencia;
  this->FechaNacimiento = FechaNacimiento;
}

void obtenerInscripciones(){}

set<DTEstadisticaEstudiante> obtenerEstadisticasEstudiante(string Nickname){}

Estudiante ::~Estudiante() {}