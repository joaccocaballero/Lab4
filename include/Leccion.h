#include <string>
namespace std;

class Leccion {
    public:
        string tema;
        string objetivo;
        bool aprobacion;
    private:
        Leccion(string tema, string objetivo, bool aprobacion);
        set<Ejercicios> obtenerEjercicios();
        set<string> obtenerEjerciciosPendientes();
        DTEjercicio obtenerEjerciciosLeccion(int id, l Leccion);
        ~Leccion()
}