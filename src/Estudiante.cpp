
#include <set>
#include <string>
 
#include "../include/Estudiante.h"
#include "../include/Idioma.h"
#include "../include/DTFecha.h"

Estudiante::5Estudiante(string Nickname, string Contrasenia, string Nombre,
                       string Descripcion, string PaisResidencia,
                       DTFecha FechaNacimiento)
    : Usuario(Nickname, Contrasenia, Nombre, Descripcion) {
  this->PaisResidencia = PaisResidencia;
  this->FechaNacimiento = FechaNacimiento;
}

void obtenerInscripciones(){}

set<DTEstadisticaEstudiante> obtenerEstadisticasEstudiante(string Nickname){}

Estudiante ::~Estudiante() {}