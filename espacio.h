#ifndef ESPACIO_H_INCLUDED
#define ESPACIO_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <conio.h>
#include <iostream>
#include <fstream>

using namespace std;

class Espacio
{

private:
    string nombre, tipo, lote, identificador, marca, modelo;
    string cantidad, costo, precio;

public:

    //sets
    void setNombre(string);
    void setTipo(string);
    void setDia(string);
    void setMes(string);
    void setLote(string);
    void setIden(string);
    void setMarca(string);
    void setModelo(string);
    void setCantidad(string);
    void setYear(string);
    void setCosto(string);
    void setPrecio(string);

    //gets
    string getNombre();
    string getTipo();
    string getDia();
    string getMes();
    string getLote();
    string getIden();
    string getMarca();
    string getModelo();
    string getCantidad();
    string getYear();
    string getCosto();
    string getPrecio();


};



#endif // ESPACIO_H_INCLUDED
