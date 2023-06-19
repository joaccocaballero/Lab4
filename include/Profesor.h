#ifndef PROFESOR
#define PROFESOR

#include <set>
#include <string>

#include "Idioma.h"
#include "DTEstadisticaProfesor.h"

using namespace std;

class Idioma;

class Profesor: public Usuario {
    private:
        string Instituto;
        set<Idioma*> Especializaciones;
    public:
        Profesor(string Nickname, string Contrasenia, string Nombre, string Descripcion, string Instituto, set<Idioma*> Especializaciones);
        void AgregarEspecializacion(Idioma idioma);
        string obtenerInstituto();
        set<string> consultarIdiomasProfesor();
        ~Profesor();
};

#endif