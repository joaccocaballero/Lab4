#include "../include/Profesor.h"
#include "../include/Idioma.h"
#include <set>
#include <string>

Profesor::Profesor(string Nickname, string Contrasenia, string Nombre, string Descripcion, string Instituto, set<Idioma*> Especializaciones)
    : Usuario(Nickname, Contrasenia, Nombre, Descripcion), Instituto(Instituto), Especializaciones(Especializaciones) {
}

void AgregarEspecializacion(Idioma idioma){}

set<string> consultarIdiomasProfesor(){}

set<DTEstadisticaProfesor> obtenerEstadisticaProfesor(string Nickname){}

Profesor ::~Profesor() {}