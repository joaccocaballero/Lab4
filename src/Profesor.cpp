
#include <set>
#include <string>

#include "../include/Idioma.h"
#include "../include/Profesor.h"
#include "../include/Usuario.h"

using namespace std;

Profesor::Profesor(string Nickname, string Contrasenia, string Nombre,
                   string Descripcion, string Instituto,
                   set<Idioma*> Especializaciones)
    : Usuario(Nickname, Contrasenia, Nombre, Descripcion) {
  this->Instituto = Instituto;
  this->Especializaciones = Especializaciones;
}

void Profesor::AgregarEspecializacion(Idioma idioma){}
string Profesor::obtenerInstituto(){
  return Instituto;
}

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