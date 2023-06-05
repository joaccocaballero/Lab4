#ifndef MANEJADORUSUARIO
#define MANEJADORUSUARIO

#include <string>
#include <set>
#include <map>
#include "Usuario.h"
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
        void agregarUsuario(Usuario *usuario);
        set<string> obtenerNicknamesProfesores();
        Profesor obtenerProfesor();
        set<string> obtenerIdiomasProfesor();
        set<string> obtenerEstudiantes();
        set<DTEstadisticaEstudiante> obtenerEstadisticasEstudiantes(string Nickname);
        set<string> obtenerProfesores();
        set<DTEstadisticaProfesor> obtenerEstadisticasProfesor(string Nickname);
        set<DTNotificacion> obtenerNotificaciones(string Nickname);
};

#endif