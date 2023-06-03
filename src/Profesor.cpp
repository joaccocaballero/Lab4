#include "../include/Profesor.h"
#include "../include/Idioma.h"
#include <set>
#include <string>

Profesor :: Profesor(string Instituto, set<Idioma*> Especializaciones){
    this->Instituto = Instituto;
    this->Especializaciones = Especializaciones;
}

void AgregarEspecializacion(Idioma idioma){}

set<string> consultarIdiomasProfesor(){}

set<DTEstadisticaProfesor> obtenerEstadisticaProfesor(string Nickname){}

Profesor ::~Profesor() {}