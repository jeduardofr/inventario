#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <conio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include "espacio.h"
#include "seguridad.h"

#define N 1000

#define K 5

using namespace std;

class Lista
{
private:
    Espacio space[N];
    Seguridad sec[K];

    int ultimo=0;
    int SecCont=0;

public:
    //LISTA DE INVENTARIO
    void inicializa();
    int vacia();
    int llena();

    void imprimir_lista();
    void eliminar(int);
    int busqueda(string);
    void recuperar(int);
    void eliminarTodo();

    void insertar();

    void leer();

    string checar(string);

    string llavePrimaria(string, int);

    //LISTA DE USUARIOS

    void SecCrearU();
    void SecBorrarU(int);
    int SecBuscar(string);
    void secMostrar(int);
    int secLeer();

    bool comparar(string,string);

friend class Seguridad;


};


#endif // LISTA_H_INCLUDED
