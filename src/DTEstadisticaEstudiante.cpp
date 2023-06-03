#include <string>
#include "../include/DTEstadisticaEstudiante.h"

using namespace std;

DTEstadisticaEstudiante::DTEstadisticaEstudiante(string Curso, int avance){
    this->Avance = avance;
    this->Curso = Curso;
}
string DTEstadisticaEstudiante::getNombreCurso(){
    return this->Curso;
}
int DTEstadisticaEstudiante::getAvance(){
    return this->Avance;
}