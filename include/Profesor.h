
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
        void AgregarEspecializacion(Idioma idioma);
        set<string> consultarIdiomasProfesor();
        set<DTEstadisticaProfesor> obtenerEstadisticaProfesor(string Nickname);
        ~Profesor();
};