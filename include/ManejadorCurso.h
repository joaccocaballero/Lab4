#include <string>
#include "Curso.h"
#include "Ejercicio.h"

class ManejadorCurso {
    private:
        static ManejadorCurso * instancia;
        ManejadorCurso();
    public:
        static ManejadorCurso * getInstancia();
        bool existeNickname(string nickname);
        void agregarCurso(Curso c);
        set<string> obtenerHabilitados();
        Idioma obtenerIdioma(string nomIdioma);
        set<string> obtenerCursos();
        void eliminarCurso(string nombre);
        set<string> obtenerCursosNoAprobados();
        Curso seleccionarCurso(string nombre);
        set<string> obtenerEjerciciosPendientesCurso(Curso c);
        DTEjercicio obtenerEjercicio(int id);
        bool respuestaEjercicio(string sol);
        DTEstadisticaCurso obtenerEstadisticaCurso(string nombre);
        
}