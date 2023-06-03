#ifndef USUARIO
#define USUARIO
#include <set>
#include <string>
#include "DTNotificacion.h"
using namespace std;

class Usuario : public IObserver {
        string Nickname;
        string Contrasenia;
        string Nombre;
        string Descripcion;
        set<DTNotificacion> Notificaciones;
    public:
        Usuario(string Nickname, string Contrasenia, string Nombre, string Descripcion);
        string obtenerNickname();
        void Notificar(DTNotificacion Notificacion);
        set<DTNotificacion> obtenerNotificaciones(string Nickname);
        virtual ~Usuario();
};

#endif