#pragma once
#ifndef _DTFECHA
#define _DTFECHA

class DTFecha{
    private:
        int Dia;
        int Mes;
        int Anio;
    public:
        DTFecha(int Dia, int Mes, int Anio);
        int getDia();
        int getMes();
        int getAnio();
};

#endif