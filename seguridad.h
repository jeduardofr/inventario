#ifndef SEGURIDAD_H_INCLUDED
#define SEGURIDAD_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <conio.h>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class BaseSeguridad
{
  virtual void iniciar() = 0;
  virtual void setUser(string) = 0;
  virtual void setContra(string) = 0;
  virtual string getUser() = 0;
  virtual string getContra() = 0;
};

class Seguridad : public BaseSeguridad
{
private:
public:
  string sujeto, clave;

  void iniciar();

  //sets

  void setUser(string);
  void setContra(string);
  //gets

  string getUser();
  string getContra();

  //metodos
};

#endif // SEGURIDAD_H_INCLUDED
