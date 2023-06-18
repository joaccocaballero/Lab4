#include "../include/DTEstadisticaProfesor.h"
#include <string>

DTEstadisticaProfesor::DTEstadisticaProfesor(){
    this->curso = "curso";
    this->Promedio = 0;
}
DTEstadisticaProfesor::DTEstadisticaProfesor(string curso, int Promedio){
    this->curso = curso;
    this->Promedio = Promedio;
}
string DTEstadisticaProfesor::getNombreCurso(){
    return curso;
}

int DTEstadisticaProfesor::getPromedio(){
    return Promedio;
}
