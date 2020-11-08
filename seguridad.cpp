#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "seguridad.h"

using namespace std;

void Seguridad::iniciar()
{
}

//setters -----------------------------------------------------------------

void Seguridad::setUser(string U)
{
    sujeto = U;
}

void Seguridad::setContra(string C)
{
    clave = C;
}

//GETTERS ----------------------------------------------

string Seguridad::getUser()
{
    return sujeto;
}

string Seguridad::getContra()
{
    return clave;
}
