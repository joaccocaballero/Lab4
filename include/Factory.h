
#include "IControladorUsuario.h"
#include "IControladorCurso.h"

class Factory{
    private: 
        IControladorUsuario * interfaceICtrlUsuario;
        IControladorCurso * interfaceICtrlCurso;
    public: 
        IControladorUsuario getIControladorUsuarios();
        IControladorCurso getIControladorCursos();
        ~Factory();
}