#include <string>
#include "../include/DTNotificacion.h"

DTNotificacion::DTNotificacion(string NombreCurso, string NombreIdioma){
    this->NombreCurso = NombreCurso;
    this->NombreIdioma = NombreIdioma;
}
string DTNotificacion::getNombreCurso(){
    return this->NombreCurso;
}
string DTNotificacion::getNombreIdioma(){
    return this->NombreIdioma;
}
