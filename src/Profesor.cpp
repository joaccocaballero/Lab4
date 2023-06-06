#include "../include/Profesor.h"
#include "../include/Idioma.h"
#include <set>
#include <string>
using namespace std;

Profesor::Profesor(string Nickname, string Contrasenia, string Nombre, string Descripcion, string Instituto, set<Idioma*> Especializaciones)
    : Usuario(Nickname, Contrasenia, Nombre, Descripcion), Instituto(Instituto), Especializaciones(Especializaciones) {
}

void AgregarEspecializacion(Idioma idioma){}

set<string> Profesor::consultarIdiomasProfesor(){
    set<string> nombreIdiomas;
    set<Idioma*> col = Especializaciones;
    for(set<Idioma*>::iterator it = col.begin(); it!=col.end(); ++it){
        Idioma *current = *it;
        nombreIdiomas.insert(current->obtenerNombre());
    }
    return nombreIdiomas;
}

set<DTEstadisticaProfesor> Profesor::obtenerEstadisticaProfesor(string Nickname){}

Profesor ::~Profesor() {}