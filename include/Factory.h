
#ifndef FACTORY
#define FACTORY

#include "IControladorUsuario.h"
#include "IControladorCurso.h"

#include "ControladorUsuario.h"
#include "ControladorCurso.h"

class Factory{
    private:
        static Factory * instancia;
        IControladorUsuario * interfaceICtrlUsuario;
        IControladorCurso * interfaceICtrlCurso;
        Factory();
    public: 
        static Factory * getInstancia();
        IControladorUsuario getIControladorUsuarios();
        IControladorCurso getIControladorCursos();
        ~Factory();
};

#endif