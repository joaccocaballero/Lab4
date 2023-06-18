#include <string>
#include "../include/DTEstadisticaEstudiante.h"

using namespace std;
DTEstadisticaEstudiante::DTEstadisticaEstudiante(){
    this->Avance = 0;
    this->curso = "";
}
DTEstadisticaEstudiante::DTEstadisticaEstudiante(string curso, int avance){
    this->Avance = avance;
    this->curso = curso;
}
string DTEstadisticaEstudiante::getNombreCurso(){
    return curso;
}
int DTEstadisticaEstudiante::getAvance(){
    return Avance;
}