
#include "../include/DTCursoDisponible.h"

DTCursoDisponible::DTCursoDisponible(string nombre, string descripcion,
                                     string idioma, string profesor,
                                     int ctdLecciones, int ctdEjercicios,
                                     EnumDificultad dificultad){
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->idioma = idioma;
    this->profesor = profesor;
    this->ctdLecciones = ctdLecciones;
    this->ctdEjercicios = ctdEjercicios;
    this->dificultad = dificultad;
}

string DTCursoDisponible::getNombre(){
    return nombre;
}

string DTCursoDisponible::getDescripcion(){
    return descripcion;
} 

string DTCursoDisponible::getIdioma(){
    return idioma;
}

string DTCursoDisponible::getProfesor(){ 
    return profesor; 
}

int DTCursoDisponible::getLecciones(){ 
    return ctdLecciones; 
}

int DTCursoDisponible::getEjercicios() { 
    return ctdEjercicios; 
}

EnumDificultad DTCursoDisponible::getDificultad(){
    return dificultad;
}
