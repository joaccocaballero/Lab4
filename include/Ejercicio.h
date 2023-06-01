#include <string>

using namespace std;

enum EnumEjercicios {Traducir, CompletarFrase};

class Ejercicio {
    public:
        int id;
        string consigna;
        EnumEjercicios tipo;
        bool aprobacion;
    private:
        Ejercicio(int id, string consigna, EnumEjercicios tipo, bool aprobacion);
        string getNombre();
        EnumEjercicio obtenerTipo();
        virtual bool esCorrecto();
        virtual ~Ejercicio();
}