#ifndef IOBSERVER
#define IOBSERVER

#include <string>
#include <DTNotificacion.h>
using namespace std;

class IObserver {
  virtual void Notificar(DTNotificacion Notificacion) = 0;
  virtual ~IObserver(){};
};

#endif