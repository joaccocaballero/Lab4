#ifndef IOBSERVER
#define IOBSERVER

#include <string>
#include <DTNotificacion.h>
using namespace std;

class IObserver {
  public:
  virtual void Notificar(DTNotificacion Notificacion) = 0;
  virtual ~IObserver() = 0;
};

#endif