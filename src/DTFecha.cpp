#include "../include/DTFecha.h"

DTFecha::DTFecha(int Dia, int Mes, int Anio){
    this->Anio = Anio;
    this->Dia = Dia;
    this->Mes = Mes;
}
int DTFecha::getDia(){
    return this->Dia;
}
int DTFecha::getMes(){
    return this->Mes;
}
int DTFecha::getAnio(){
    return this->Anio;
}