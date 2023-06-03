#include <string>
#include "../include/DTEjercicio.h"

using namespace std;

DTEjercicio::DTEjercicio(string NombreEjercicio){
    this->NombreEjercicio = NombreEjercicio;
}
string DTEjercicio::getNombreEjercicio(){
    return NombreEjercicio;
}