
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
        ControladorUsuario* ctrlUsuario;
        ControladorCurso* ctrlCurso;
        Factory();
    public: 
        static Factory * getInstancia();
        IControladorUsuario* getIControladorUsuario();
        IControladorCurso* getIControladorCurso();
        ~Factory();
};

#endif