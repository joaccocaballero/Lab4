#include <string>
#include <set>
#include "Usuario.h"
#include "DTEstadisticaEstudiante.h"
#include "DTEstadisticaProfesor.h"
#include "DTNotificacion.h"


class ManejadorUsuario {
    private:
        static ManejadorUsuario * manejadorU;
        ManejadorUsuario();
    public:
        static ManejadorUsuario * getManejadorU();
        bool existeNickname(string Nickname)
        void agregarUsuario(Usuario usuario)
        set<string> obtenerNicknamesProfesores();
        Usuario obtenerProfesor();
        set<string> obtenerIdiomasProfesor();
        set<string> obtenerEstudiantes();
        set<DTEstadisticaEstudiante> obtenerEstadisticasEstudiantes(string Nickname);
        set<string> obtenerProfesores();
        set<DTEstadisticaProfesor> obtenerEstadisticasProfesor(string Nickname);
        set<DTNotificacion> obtenerNotificaciones(string Nickname);



}