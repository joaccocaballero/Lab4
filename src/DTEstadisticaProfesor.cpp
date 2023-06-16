#include "../include/DTEstadisticaProfesor.h"
#include <string>

using namespace std;

DTEstadisticaProfesor::DTEstadisticaProfesor(string Curso, int Promedio){
    this->Curso = Curso;
    this->Promedio = Promedio;
}
string DTEstadisticaProfesor::getNombreCurso(){
    return Curso;
}

int DTEstadisticaProfesor::getPromedio(){
    return Promedio;
}
