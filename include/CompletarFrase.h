#pragma once
#ifndef _COMPLETAREJERCICIO
#define _COMPLETAREJERCICIO
#include <string>
#include <set>

#include "Ejercicio.h"

using namespace std;

class CompletarFrase : public Ejercicio {
 private:
  string solucion;

 public:
  CompletarFrase(int id, string consigna, string descripcion,EnumEjercicios tipo, string sol);
  bool esCorrecto(string sol);
   ~CompletarFrase();
};

#endif