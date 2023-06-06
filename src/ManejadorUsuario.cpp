#include "../include/ManejadorUsuario.h"
using namespace std;

Profesor ManejadorUsuario::obtenerProfesor(){
    Profesor profesor = ColeccionDeProfesores.find(nickname);
    if (profesor != ColeccionDeProfesores.end()) {
        return profesor;
    }
}