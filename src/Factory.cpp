#include "Factory.h"

Factory::Factory() {
    interfaceICtrlUsuario = new IControladorUsuario();
    interfaceICtrlCurso = new IControladorCurso();
}

IControladorUsuario Factory::getIControladorUsuarios() {
    return *interfaceICtrlUsuario;
}

IControladorCurso Factory::getIControladorCursos() {
    return *interfaceICtrlCurso;
}

Factory::~Factory() {
    delete interfaceICtrlUsuario;
    delete interfaceICtrlCurso;
}