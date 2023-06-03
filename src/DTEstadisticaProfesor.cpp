#include "../include/DTEstadisticaProfesor.h"
#include <string>

using namespace std;

DTEstadisticaProfesor::DTEstadisticaProfesor(string Curso, int Avance, int Promedio){
    this->Curso = Curso;
    this->Avance = Avance;
    this->Promedio = Promedio;
}
string DTEstadisticaProfesor::getNombreCurso(){
    return Curso;
}
int DTEstadisticaProfesor::getAvance(){
    return Avance;
}
int DTEstadisticaProfesor::getPromedio(){
    return Promedio;
}
