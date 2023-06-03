#pragma once
#ifndef _COMPLETAREJERCICIO
#define _COMPLETAREJERCICIO
#include <string>
#include <set>

#include "Ejercicio.h"

using namespace std;

class CompletarFrase : public Ejercicio {
 public:
  set<string> solucion;

 private:
  CompletarFrase(int id, string consigna, EnumEjercicios tipo, bool aprobacion, set<string> solucion);
  bool esCorrecto(set<string> sol);
   ~CompletarFrase();
};

#endif