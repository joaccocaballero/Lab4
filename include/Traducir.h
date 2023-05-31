#include <string>
#include "Ejercicio.h"
namespace std

class Traducir: public Ejercicio {
    public: 
        string solucion;
    private:
        Traducir(int id, string consigna, EnumEjercicios tipo, bool aprobacion, string solucion);
        virtual bool esCorrecto(string sol);
        virtual ~Traducir();
        
}