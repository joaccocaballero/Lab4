
#include "IControladorUsuario.h"
#include "IControladorCurso.h"

class Factory{
    private: 
    public: 
        IControladorUsuario getIControladorUsuarios();
        IControladorCurso getIControladorCursos();
        ~Factory();
}