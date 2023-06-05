#include "Factory.h"

Factory::Factory() {
    interfaceICtrlUsuario = new IControladorUsuario();
    interfaceICtrlCurso = new IControladorCurso();
}

ControladorUsuario Factory::getIControladorUsuarios() {
    return ControladorUsuario.getInstancia();
}

ControladorCurso Factory::getIControladorCursos() {
    return ControladorCurso.getInstancia;
}

Factory::~Factory() {
    delete interfaceICtrlUsuario;
    delete interfaceICtrlCurso;
}