#ifndef USUARIO
#define USUARIO
#include <vector>
#include <string>
#include "DTNotificacion.h"
#include "IObserver.h"

using namespace std;

class Usuario : public IObserver {
        string Nickname;
        string Contrasenia;
        string Nombre;
        string Descripcion;
        vector<DTNotificacion> Notificaciones;
    public:
        Usuario(string Nickname, string Contrasenia, string Nombre, string Descripcion);
        string obtenerNickname();
        void Notificar(DTNotificacion Notificacion);
        vector<DTNotificacion> obtenerNotificaciones(string Nickname);
        virtual ~Usuario();
};

#endif