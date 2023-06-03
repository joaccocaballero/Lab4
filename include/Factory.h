
#ifndef FACTORY
#define FACTORY

#include "IControladorUsuario.h"
#include "IControladorCurso.h"

class Factory{
    private: 
        IControladorUsuario * interfaceICtrlUsuario;
        IControladorCurso * interfaceICtrlCurso;
        Factory();
    public: 
        IControladorUsuario getIControladorUsuarios();
        IControladorCurso getIControladorCursos();
        ~Factory();
};

#endif