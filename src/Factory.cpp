#include "Factory.h"
 
#include "IControladorCurso.h"
#include "IControladorUsuario.h"
#include "ControladorCurso.h"
#include "ControladorUsuario.h"

Factory * Factory::instancia = NULL;

Factory::Factory(){}

Factory * Factory::getInstancia(){
    if(instancia == NULL){
        instancia = new Factory();
    }
    return instancia;
}

IControladorUsuario* Factory::getIControladorUsuario() {
    return ctrlUsuario->getInstancia();
}   

IControladorCurso* Factory::getIControladorCurso() {
    return ctrlCurso->getInstancia();
}

Factory::~Factory() {
    delete interfaceICtrlUsuario;
    delete interfaceICtrlCurso;
}