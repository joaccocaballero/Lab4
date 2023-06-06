#include "../include/DTFecha.h"

DTFecha::DTFecha(){}

DTFecha::DTFecha(int Dia, int Mes, int Anio){
    this->Anio = Anio;
    this->Dia = Dia;
    this->Mes = Mes;
}
int DTFecha::getDia(){
    return Dia;
}
int DTFecha::getMes(){
    return Mes;
}
int DTFecha::getAnio(){
    return Dia;
}