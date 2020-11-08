#include <iostream>
#include <assert.h>
#include "seguridad.h"

using namespace std;

class MockSeguridad : public BaseSeguridad
{
public:
  string user, pass;

  void iniciar()
  {
    this->user = "";
    this->pass = "";
  }

  void setUser(string user)
  {
    this->user = user;
  }

  void setContra(string pass)
  {
    this->pass = pass;
  }

  string getUser()
  {
    return user;
  }
  string getContra()
  {
    return pass;
  }
};

void runTests();
void verificarSettersGetters();

int main(int argc, const char **argv)
{
  runTests();
  return 0;
}

void runTests()
{
  verificarSettersGetters();
}

void verificarSettersGetters()
{
  {
    MockSeguridad mock;

    mock.setUser(string("eduardo"));
    mock.setContra(string("123abc"));

    assert(mock.getUser() == "eduardo");
    assert(mock.getContra() == "123abc");

    std::cout << "Setters y Getters funcionando.\n";
  }
}
