
#include <string>
using namespace std;

class DTEstadisticaProfesor{
    private:
        string Curso;
        integer Avance;
        integer Promedio;
    public:
        DTEstadisticaProfesor(string Curso, string Avance, string Promedio);
        string getNombreCurso();
        integer getAvance();
        integer getPromedio();

}