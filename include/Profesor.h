
#include <set>
#include <string>

#include "Idioma.h"
#include "DTEstadisticaProfesor.h"

using namespace std;

class Profesor: public Usuario {
    private:
        string Instituto;
    public:
        void AgregarEspecializacion(Idioma idioma);
        set<string> consultarIdiomasProfesor();
        set<DTEstadisticaProfesor> obtenerEstadisticaProfesor(string Nickname);
}