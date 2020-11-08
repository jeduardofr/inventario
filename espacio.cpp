#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <conio.h>
#include <iostream>
#include <fstream>

#include "espacio.h"

using namespace std;

//setters
void Espacio::setNombre(string N)
{
    nombre=N;
}
void Espacio::setTipo(string T)
{
    tipo=T;
}

void Espacio::setLote(string L)
{
    lote=L;
}
void Espacio::setIden(string ID)
{
    identificador=ID;
}
void Espacio::setMarca(string MK)
{
    marca=MK;
}
void Espacio::setModelo(string MD)
{
    modelo=MD;
}
void Espacio::setCantidad(string C)
{
    cantidad=C;
}

void Espacio::setCosto(string C)
{
    costo=C;
}
void Espacio::setPrecio(string P)
{
    precio=P;
}

//getters
string Espacio::getNombre()
{
    return nombre;
}
string Espacio::getTipo()
{
    return tipo;
}
string Espacio::getLote()
{
    return lote;
}
string Espacio::getIden()
{
    return identificador;
}
string Espacio::getMarca()
{
    return marca;
}
string Espacio::getModelo()
{
    return modelo;
}
string Espacio::getCantidad()
{
    return cantidad;
}
string Espacio::getCosto()
{
    return costo;
}
string Espacio::getPrecio()
{
    return precio;
}

