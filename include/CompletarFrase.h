#include <string>

#include "Ejercicio.h"
#include <string>
#include <set>
using namespace std;
enum EnumEjercicios { Traducir, CompletarFrase };

class CompletarFrase : public Ejercicio {
 public:
  set<string> solucion;

 private:
  CompletarFrase(int id, string consigna, EnumEjercicios tipo, bool aprobacion, set<string> solucion);
  bool esCorrecto(set<string> sol);
   ~CompletarFrase();
}