
#ifndef FACTORY
#define FACTORY

#include "IControladorUsuario.h"
#include "IControladorCurso.h"

#include "ControladorUsuario.h"
#include "ControladorCurso.h"

class Factory{
    private: 
        IControladorUsuario * interfaceICtrlUsuario;
        IControladorCurso * interfaceICtrlCurso;
        Factory();
    public: 
        ControladorUsuario getIControladorUsuarios();
        ControladorCurso getIControladorCursos();
        ~Factory();
};

#endif