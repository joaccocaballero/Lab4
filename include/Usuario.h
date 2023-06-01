
#include <set>
#include <string>

#include "DTNotificacion.h"
using namespace std;

class Usuario {
    private: 
        string Nickname;
        string Contrasenia;
        string Nombre;
        string Descripcion;
    public:
        Usuario(string Nickname, string Contrasenia, string Nombre, string Descripcion);
        string obtenerNickname();
        void Notificar(DTNotificacion Notificacion);
        set<DTNotificacion> obtenerNotificaciones(string Nickname);
        virtual ~Usuario();
}