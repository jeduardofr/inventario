#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "lista.h"

using namespace std;


void Lista::inicializa()
{
    ultimo=0;
    SecCont=0;
}
int Lista::vacia()
{
    if(ultimo==0)
        return 1;
    return 0;
}
int Lista::llena()
{
    if(ultimo==N)
        return 1;
    return 0;
}


string Lista::checar(string busca)
{

    for (int i=0; i <ultimo; i++)
    {
        if(busca==space[i].getNombre() )

            return space[i].getIden();
    }


    return "a" ;
}

string Lista::llavePrimaria(string d, int opc)
{

    string Folio,aux,aux2, str;

    int aleatorio = 101+rand()%(200-101);
    if (opc ==0)
    {
        str = to_string(aleatorio);
        aux = d.substr(0,3);
        Folio = aux + '-' + str;
        return Folio;
    }
    if (opc==1)
    {
        str = to_string(aleatorio);
        aux = d.substr(0,4);
        Folio =  str+aux;
        return Folio;
    }

}



void Lista::insertar()
{
    string nombre, tipo, lote, identificador, marca, modelo;
    string cantidad, costo, precio, aux;


    if(llena())
    {
        system("cls");
        cout<<"\n---------------------------"<<endl;
        cout<<"ERROR | La lista esta llena"<<endl;
        cout<<"---------------------------\n"<<endl;
        cout<<"\n\n\nPresiona  [<-]ENTER  para continuar"<<endl;
        getch();
        return;
    }


    system("cls");
    cout<<"\nInserte los elementos a continuacion"<<endl;
    cout<<"espacios usados: "<<ultimo<<" de 1000"<<endl;
    cout<<"----------------------------------------"<<endl;

    cout<<"\nINTRODUCE EL NOMBRE DEL PRODUCTO > ";
    cin>>nombre;
    space[ultimo].setNombre(nombre);

    cout<<"\nINTRODUCE LA MARCA DEL PRODUCTO > ";
    cin>>marca;
    space[ultimo].setMarca(marca);

    cout<<"\nINTRODUCE EL MODELO > ";
    cin>>modelo;
    space[ultimo].setModelo(modelo);

    cout<<"\nINTRODUCE EL TIPO DE PRODUCTO > ";
    cin>>tipo;
    space[ultimo].setTipo(tipo);

    cout<<"\nINTRODUCE LA CANTIDAD ALMACENADA > ";
    cin>>cantidad;
    space[ultimo].setCantidad(cantidad);

    cout<<"\nINTRODUCE EL PRECIO UNITARIO > $";
    cin>>precio;
    space[ultimo].setPrecio(precio);

    cout<<"\nINTRODUCE EL COSTO POR VOLUMEN > $";
    cin>>costo;
    space[ultimo].setCosto(costo) ;

    aux=checar(nombre);
    if (aux == "a")
    {
        identificador = llavePrimaria(nombre, 0);
    }
    else
    {
        identificador=aux;
    }
    lote=llavePrimaria(marca, 1);
    space[ultimo].setIden(identificador);
    space[ultimo].setLote(lote);
    cout<<endl;
    cout<<"------------------------------------------------------------------------------------------"<<endl;
    cout<<"Se asigno "<<identificador<<" como ID del producto, y "<<lote<<" como el lote del producto"<<endl;
    cout<<"------------------------------------------------------------------------------------------"<<endl;
    ultimo++;


//para archivo

    stringstream ss;     //condensador de flujo
    ss  << nombre << "," << marca << "," << modelo << "," << tipo << ","<<identificador<<","<<lote<<","<< cantidad << ","<<precio<<","<<costo;

    ofstream archivo("Registros.txt", ios::app | ios::out);
    archivo << ss.str() << endl;
    archivo.close();
    cout<<"\n\n\nPresiona  [<-]ENTER  para continuar"<<endl;
    getch();

}

void Lista::imprimir_lista()
{
    int i=0;
    if(vacia())
    {
        system("cls");
        cout<<"\n---------------------------"<<endl;
        cout<<"ERROR | La lista esta vacia"<<endl;
        cout<<"---------------------------\n"<<endl;
        return;
    }
    for( i; i<ultimo; i++)
    {
        cout<<"\n---------------------------------------------"<<endl;
        cout<<" | NOMBRE DEL PRODUCTO > "<<space[i].getNombre()<<endl;
        cout<<i<<"| MARCA > "<<space[i].getMarca() <<endl;
        cout<<" | MODELO > "<<space[i].getModelo() <<endl;
        cout<<" | TIPO DE PRODUCTO > "<<space[i].getTipo() <<endl;
        cout<<" | IDENTIFICADOR > "<<space[i].getIden() <<endl;
        cout<<" | LOTE > $"<<space[i].getLote() <<endl;
        cout<<" | CANTIDAD > "<<space[i].getCantidad() <<endl;
        cout<<" | COSTO POR VOLUMEN > $"<< space[i].getCosto() <<endl;
        cout<<" | PRECIO UNITARIO > $"<<space[i].getPrecio() <<endl;

    }
    if(i==ultimo)
        cout<<"---------------------------------------------\n"<<endl;
        cout<<"\n\n\nPresiona  [<-]ENTER  para continuar"<<endl;
        getch();
}

void Lista::eliminar(int pos)
{
    if(vacia())
    {
        cout<<"\n---------------------------"<<endl;
        cout<<"ERROR | La lista esta vacia"<<endl;
        cout<<"---------------------------\n"<<endl;
        return;
    }
    if( pos<0 || pos>ultimo)
    {
        cout<<"\n---------------------------"<<endl;
        cout<<"ERROR | Dato invalido"<<endl;
        cout<<"---------------------------\n"<<endl;

        return;
    }
    for(int i=pos; i<ultimo; i++)
        space[i]=space[i+1];
    ultimo--;
    cout<<"\n---------------------------"<<endl;
    cout<<"AVISO | Dato eliminado"<<endl;
    cout<<"---------------------------\n"<<endl;
    cout<<"\n\n\nPresiona  [<-]ENTER  para continuar"<<endl;
    getch();
}





int Lista::busqueda(string buscar)
{
    if(vacia())
    {
        system("cls");
        cout<<"\n---------------------------"<<endl;
        cout<<"ERROR | No hay nada en la lista"<<endl;
        cout<<"---------------------------\n"<<endl;
        cout<<"\n\n\nPresiona  [<-]ENTER  para continuar"<<endl;

        getch();
        return-1;
    }
    for (int i=0; i <=ultimo; i++)
        if(buscar==space[i].getIden())
            return i;
    return -1;
}

void Lista::eliminarTodo()
{
    ofstream archivo("Registros.txt", ios::app | ios::trunc);
        //archivo << ss.str() << endl;
    archivo.close();
    archivo.clear();

    ultimo=0;


}

void Lista::recuperar(int rec)
{
    if( rec>=0 && rec<ultimo)
    {

        cout<<"\n---------------------------------------------"<<endl;
        cout<<" | NOMBRE DEL PRODUCTO > "<<space[rec].getNombre()<<endl;
        cout<<rec<<"| MARCA > "<<space[rec].getMarca() <<endl;
        cout<<" | MODELO > "<<space[rec].getModelo() <<endl;
        cout<<" | TIPO DE PRODUCTO > "<<space[rec].getTipo() <<endl;
        cout<<" | IDENTIFICADOR > "<<space[rec].getIden() <<endl;
        cout<<" | LOTE > $"<<space[rec].getLote() <<endl;
        cout<<" | CANTIDAD > "<<space[rec].getCantidad() <<endl;
        cout<<" | COSTO POR VOLUMEN > $"<< space[rec].getCosto() <<endl;
        cout<<" | PRECIO UNITARIO > $"<<space[rec].getPrecio() <<endl;
        cout<<"-------------------------------------\n"<<endl;
        cout<<"\n\n\nPresiona  [<-]ENTER  para continuar"<<endl;
        getch();
    }
    else
    {
        system("cls");
        cout<<"\n--------------------------------------"<<endl;
        cout<<"ERROR | Esta posicion es invalida, o aun no existe"<<endl;
        cout<<"----------------------------------------\n"<<endl;
        cout<<"\n\n\nPresiona  [<-]ENTER  para continuar"<<endl;
        getch();
    }
}

void Lista::leer()
{
    int i=0;
    string name, brand, model, type, id, lot, cant, cost, price;
    ifstream lectura;

    lectura.open("Registros.txt", ios::in);//Leemoa el archivo en modo lectura
    if(lectura.fail())
    {
        system("cls");
        cout<<"\n----------------------------------------"<<endl;
        cout<<"ERROR | Esta posicion es invalida, o aun no existe"<<endl;
        cout<<"----------------------------------------\n"<<endl;
        cout<<"\n\n\nPresiona  [<-]ENTER  para continuar"<<endl;
        getch();
        return;
    }
    while (!lectura.eof())  //Guarda y muestra las cadenas hasta el final del archivo
    {
        getline(lectura,name,',');
        getline(lectura,brand,',');
        getline(lectura,model,',');
        getline(lectura,type,',');
        getline(lectura,id,',');
        getline(lectura,lot,',');
        getline(lectura,cant,',');
        getline(lectura,cost,',');
        getline(lectura,price,'\n');


        space[i].setNombre(name);
        space[i].setMarca(brand);
        space[i].setModelo(model);
        space[i].setTipo(type);
        space[i].setIden(id);
        space[i].setLote(lot);
        space[i].setCantidad(cant);
        space[i].setCosto(cost);
        space[i].setPrecio(price);



        i++; //contador
    }
    lectura.close(); //cerramos el archivo, para abrir el otro

    ultimo = i;
}





//METODOS -----------------------------------------------------
void Lista::SecCrearU()
{
    string usuario, contra;

    cout<<SecCont;
    system("cls");
    cout<<"\nREGISTRO DE USUARIOS"<<endl;
    cout<<"\nInserte la información en los campos"<<endl;
    cout<<SecCont<<" de usuarios"<<endl;
    cout<<"----------------------------------------"<<endl;

    cout<<"\nINTRODUCE EL NOMBRE DE USUARIO > ";
    cin>>usuario;

    cout<<"\nINTRODUCE LA CONTRASENA > ";
    cin>>contra;

    sec[SecCont].sujeto;
    sec[SecCont].clave;

    stringstream SEC;     //condensador de flujo
    SEC  << usuario << "|" << contra;

    ofstream archivo("USR.txt", ios::app | ios::out);
    archivo << SEC.str() << endl;
    archivo.close();
    SecCont++;
}

void Lista::SecBorrarU(int bye)
{
    if (SecCont<=-1 or SecCont>=K)
    {
        for(int i=bye; i<ultimo; i++)
            sec[i]=sec[i+1];
        SecCont--;
    }
    else
        cout<< "ERROR"<<endl;
}

int Lista::SecBuscar(string aux)
{
    for (int i=0; i <= SecCont; i++)
    {
        if(aux==sec[i].sujeto)
            return i;
    }
    return -1;

}

void Lista::secMostrar(int pos)
{

    if( pos>=0 and pos<SecCont)
    {

        cout<<"\n----------------------------------"<<endl;
        cout<<" | USUARIO > "<<sec[pos].getUser() <<endl;
        cout<<pos<<"| CONTRASEÑA > "<<sec[pos].getContra() <<endl;
        cout<<"-------------------------------------\n"<<endl;
        cout<<"\n\n\nPresiona  [<-]ENTER  para continuar"<<endl;
    }
    else
    {
        system("cls");
        cout<<"\n--------------------------------------"<<endl;
        cout<<"ERROR | No hay elemento"<<endl;
        cout<<"----------------------------------------\n"<<endl;
    }




}



int Lista::secLeer()
{

    int i=0;
    string name, pass;

    ifstream lectura;

    lectura.open("USR.txt", ios::in);//Leemoa el archivo en modo lectura
    if(lectura.fail())
    {
        cout<<"\n----------------------------------------"<<endl;
        cout<<"ERROR | Esta posicion es invalida, o aun no existe"<<endl;
        cout<<"----------------------------------------\n"<<endl;
        cout<<"\n\n\nPresiona  [<-]ENTER  para continuar"<<endl;
        getch();
        return -1;
    }
    while (!lectura.eof())  //Guarda y muestra las cadenas hasta el final del archivo
    {
        getline(lectura,name,'|');
        getline(lectura,pass,'\n');
        sec[i].setUser(name);
        sec[i].setContra(pass);

        i++; //contador
    }
    lectura.close(); //cerramos el archivo, para abrir el otro

    SecCont = i;

    return 1;

}

    bool Lista::comparar(string A,string B){

    for (int i; i<=SecCont;i++){
        if(sec[i].sujeto==A  and  sec[i].clave==B)
            return true;


    }
    return false;
}

