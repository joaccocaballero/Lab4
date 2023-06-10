#ifndef MANEJADORUSUARIO
#define MANEJADORUSUARIO

#include <string>
#include <set>
#include <map>
#include "Usuario.h"
#include "DTUsuario.h"
#include "DTEstudiante.h"
#include "DTProfesor.h"
#include "Estudiante.h"
#include "Profesor.h"
#include "DTEstadisticaEstudiante.h"
#include "DTEstadisticaProfesor.h"
#include "DTNotificacion.h"

using namespace std;

class ManejadorUsuario {
    private:
        static ManejadorUsuario * manejadorU;
        map<string, Estudiante*> ColeccionDeEstudiantes;
        map<string, Profesor*> ColeccionDeProfesores;
        ManejadorUsuario();
    public:
        static ManejadorUsuario * getManejadorU();
        bool existeNickname(string Nickname);
        //void agregarUsuario(Usuario *Usuario);
        void agregarEstudiante(Estudiante* estudiante, string nickname);
        void agregarProfesor(Profesor *profesor, string nickname);
        set<string> obtenerNicknamesProfesores();
        set<string> obtenerNicknamesEstudiantes();
        Profesor* obtenerProfesor(string nickname);
        DTEstudiante obtenerDTEstudiante(string nickname);
        DTProfesor obtenerDTProfesor(string nickname);
        set<string> obtenerIdiomasProfesor(string nickname);
        set<string> obtenerEstudiantes();
        bool esEstudiante(string nickname);
        set<DTEstadisticaEstudiante> obtenerEstadisticasEstudiantes(string Nickname);
        set<string> obtenerProfesores();
        set<DTEstadisticaProfesor> obtenerEstadisticasProfesor(string Nickname);
        set<DTNotificacion> obtenerNotificaciones(string Nickname);
};

#endif