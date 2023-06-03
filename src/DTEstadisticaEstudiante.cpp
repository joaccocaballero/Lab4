#include <string>
#include "../include/DTEstadisticaEstudiante.h"

using namespace std;

DTEstadisticaEstudiante::DTEstadisticaEstudiante(string Curso, integer avance){
    this->Avance = avance;
    this->Curso = Curso;
}
string DTEstadisticaEstudiante::getNombreCurso(){
    return this->Curso;
}
integer DTEstadisticaEstudiante::getAvance(){
    return this->Avance;
}