#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <conio.h>
#include <iostream>
#include <fstream>
#include "lista.h"
#include "Seguridad.h"
#include <sstream>

#define t 1000
#define k 5

using namespace std;
//prototipos
void configuracionInicial();
void menuPrincipal();
void menuUsuario(string);
void comprobar();
void cargar(string,string,string);



int main()
{
    Lista l;

    l.inicializa();

    comprobar();

    system("cls");
    cout<<"PROGRAMA FINALIZADO"<<endl;



    return 0;
}


void comprobar()
{
    ifstream arch;
    string usr,pass,nombre,empresa,resto;
    string usuario,contra;

    arch.open("parametros.txt", ios::in);//Leemoa el archivo en modo arch
    if(arch.fail())
    {
        configuracionInicial();

        return;
    }
    else
    {
        while (!arch.eof())  //Guarda y muestra las cadenas hasta el final del archivo
        {
            getline(arch,empresa,'|');
            getline(arch,usr,'|');
            getline(arch,pass,'|');
            getline(arch,nombre,'|');
            getline(arch,resto,'\n');



        }
        arch.close();
    }
    cargar(usr,pass,nombre);
}

void configuracionInicial()
{
    string user, pass, nombre, apellido, empresa;

    system("cls");
    //PRESENTACION
    cout<<"ASISTENTE DE CONFIGURACION INICIAL"<<endl;
    cout<<"------------------------------------------------------"<<endl;
    cout<<"HOLA nos da gusto saludarte.\nBienvenido a OIPIDE, este corto asistentete ayudara\na configurar parametros basicos de este programa.\nSolo debes asegurarte de ingresar los datos que se requieren."<<endl;
    cout<<"\n --------";
    cout<<"\n| AVISO  |";
    cout<<"\n --------"<<endl;
    cout<<"\nOIPIDE es un software enfocado al sector PYME,\npor lo que este asistente tiene que ser configurado\npor el INGENIERO/TECNICO/PERSONA encargado del departamento de SISTEMAS/SOFTWARE"<<endl;
    cout<<"\nCuando estes listo, solo presiona  [<-]ENTER  en tu teclado"<<endl;
    getch();

    //PAGINA 1
    system("cls");
    cout<<"DATOS DE USUARIO"<<endl;
    cout<<"--- 1 -------------------------------"<<endl;
    cout<<"\nA continuacion debes de introducir tu primer nombre y primer apellido."<<endl;
    cout<<"\nNOMBRE > ";
    cin>>nombre;
    cout<<"\nAPELLIDO > ";
    cin>>apellido;
    cout<<"\nBien "<< nombre << ", Esto define el nombre de tu cuenta\n\nPara continuar pulsa  [<-]ENTER"<<endl;
    getch();

    //PAGINA 2
    system("cls");
    cout<<"EMPRESARIAL"<<endl;
    cout<<"---------- 2 ------------------------"<<endl;
    cout<<"\nBueno "<<nombre<<", ahora introduce el nombre de tu empresa"<<endl;
    cout<<"\nNOMBRE > ";
    cin>>empresa;
    cout<<"\nContinuemos, pulsa  [<-]ENTER"<<endl;
    getch();


    //PAGINA 3
    system("cls");
    cout<<"CUENTA DE USUARIO"<<endl;
    cout<<"----------------- 3 ------------------"<<endl;
    cout<<"\n"<<nombre<<", A continuacion debes de introducir un nombre de usuario,\nya sea creado por ti, o asignado por tu empresa."<<endl;
    cout<<"\nUSUARIO > ";
    cin>>user;
    cout<<"\nPara continuar pulsa [<-]ENTER"<<endl;
    getch();


    //PAGINA 4
    system("cls");
    cout<<"SEGURIDAD"<<endl;
    cout<<"------------------------ 4 -----------"<<endl;
    cout<<"\nAhora debes de introducir una contraseña segura.\nRecuerda que sea facil de recordar para ti"<<endl;
    cout<<"\nCONTRASENA > ";
    cin>>pass;
    cout<<"\nOk, continuemos "<<nombre<<", pulsa [<-]ENTER"<<endl;
    getch();

    //PAGINA 5
    system("cls");
    cout<<"LEGAL"<<endl;
    cout<<"------------------------------- 5 ----"<<endl;
    cout<<"\nYa casi terminamos "<<nombre<<", Solo lee lo siguiente.\nEs el contrato de licencia\n"<<endl;
    cout<<"\nCONTRATO DE LICENCIA\n\nLorem ipsum dolor sit amet, consectetur adipiscing elit.\nNulla sit amet risus ut massa maximus iaculis.\nEtiam sed tincidunt augue, eget tempor ligula.\nVivamus volutpat porta massa ac tincidunt. Maecenas ac ex sodales, scelerisque risus ut,\nbibendum sapien. Vestibulum ante ipsum primis in faucibus orci\nluctus et ultrices posuere cubilia curae"<<endl;
    cout<<"\nAL HACER ENTER,ACEPTAS LOS TERMINOS DEL CONTRATO DE LICENCIA\n"<<endl;
    getch();
    system("cls");
    cout<<"\nFelicitaciones "<<nombre<<", Haz finalizado la configuracion basica,\n\nSolo pulsa [<-]ENTER para empezar a usar el programa"<<endl;
    getch();


//ARCHIVO ADMIN:TXT
    stringstream ss;     //condensador de flujo
    ss << empresa  <<"|"<< user <<"|"<<pass  <<"|"<<nombre  <<"|"<<apellido ;

    ofstream archivo("parametros.txt", ios::app | ios::out);
    archivo << ss.str() << endl;
    archivo.close();

    cargar(user,pass,nombre);


}

void cargar(string user,string pass,string name)
{
    string stA,stB;
    int tentos=0,pos=0,bul;
    char opc;
    bool band;



    Lista l;
    Seguridad s[k];



    do
    {
        system("cls");
        cout<<"INICIO\t\t\tv 0.01b"<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"Bienvenido"<<endl;
        cout<<"Por favor, elige una opcion,\nluego inicia sesion con tu usuario"<<endl;
        cout<<"1 Administrador\n2 Usuario\n3 Salir del programa\n-> ";
        cin>>opc;



        //comparaciones
        switch(opc)
        {
        case '1':
            system("cls");
            cout<<"INICIA SESION"<<endl;
            cout<<"-----------------------------------"<<endl;;
            cout<<"INTRODUCE TUS DATOS "<<endl;
            cout<<"\nUSUARIO > ";
            cin>>stA;
            cout<<"CONTRASENA > ";
            cin>>stB;
            if(stA==user and stB==pass)
            {
                menuUsuario(name);
                break;
            }
            else
                cout<<"\n--------------------------------------"<<endl;
            cout<<"ERROR | Esta cuenta es invalida, o aun no existe"<<endl;
            cout<<"----------------------------------------\n"<<endl;
            cout<<"\n\n\nPresiona  [<-]ENTER  para continuar"<<endl;
            getch();
            break;

        case '2':

            system("cls");
            cout<<"INICIA SESION"<<endl;
            cout<<"-----------------------------------"<<endl;;
            cout<<"INTRODUCE TUS DATOS "<<endl;
            cout<<"\nUSUARIO > ";
            cin>>stA;
            cout<<"CONTRASENA > ";
            cin>>stB;


            bul=l.secLeer();
            pos=l.SecBuscar(stA);
            band=l.comparar(stA,stB);

            if(pos==-1)
            {
                cout<<"\n--------------------------------------"<<endl;
                cout<<"ERROR | Esta cuenta es invalida, o aun no existe"<<endl;
                cout<<"----------------------------------------\n"<<endl;
                cout<<"\n\n\nPresiona  [<-]ENTER  para continuar"<<endl;
                getch();

                break;
            }

            if(band)
            {
                menuPrincipal();
                break;
            }
            break;

        case '3':
            //salir
            break;

        default:
            cout<<"\n--------------------------------------"<<endl;
            cout<<"ERROR | Introduce una opcion correcta"<<endl;
            cout<<"----------------------------------------\n"<<endl;
            cout<<"\n\n\nPresiona  [<-]ENTER  para continuar"<<endl;
            getch();


            /*if(a==user and b==pass)
            {
                menuUsuario(name);
            }
            else
            {
                pos=l.SecBuscar(a);
                if(pos==-1)
                {
                    cout<<"No existe ese usuario"<<endl;
                    return;
                }
                else if(pos!=-1 and a==S.getUser() and b==S.getContra())
                    menuPrincipal();
                return;
            */
        }
    }
    while(opc!='3');
}



void menuUsuario(string name)
{
    string aux,contra;
    int band, bul;
    Lista l;

    char opc;
    do
    {
        system("cls");
        cout<<"ADMINISTRAR USUARIOS"<<endl;
        cout<<"----------------------------------------"<<endl;
        cout<<"Bienvenido "<<name<<"\nAqui esta el menu admin\nSelecciona la accion"<<endl;
        cout<<"\n1. Registrar un usuario\n2. Buscar un usuario\n3. Eliminar usuario\n4. Regresar\nOPCION >";
        cin>>opc;


        switch(opc)
        {
        case '1':
            system("cls");
            l.SecCrearU();
            break;

        case '2':
            system("cls");
            bul=l.secLeer();
            cout <<bul;
            if(bul==1)
            {
                cout<<"BUSCAR"<<endl;
                cout<<"-------------------------"<<endl;
                cout<<"Ingresa el nombre de usuario que quieres buscar > ";
                cin>>aux;
                band=l.SecBuscar(aux);
                l.secMostrar(band);
                getch();
                break;
            }
            else
                break;

        case '3':
            system("cls");
            //l.SecBorrarU();
            break;

        case '4':
            //salir
            break;
        default:
            system("cls");
            cout<<"\n----------------------------------------"<<endl;
            cout<<"ERROR | Introduce una opcion valida"<<endl;
            cout<<"----------------------------------------\n"<<endl;
            cout<<"\n\n\nPresiona  [<-]ENTER  para continuar"<<endl;
            getch();
            break;

        }
    }
    while(opc!='4');

}


void menuPrincipal()
{
    string cadena ;
    char opc, aux,sino;
    Lista l;

    do
    {
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"----------------------------------"<<endl;
        cout<<"Bienvenido, selecciona una opcion"<<endl;
        cout<<"1. Registrar productos"<<endl;
        cout<<"2. Buscar un producto en el registro"<<endl;
        cout<<"3. eliminar un producto"<<endl;
        cout<<"4. vaciar todo"<<endl;
        cout<<"5. Mostrar todo el registro"<<endl;
        cout<<"6. Salir"<<endl;
        cout<<"Seleccion > ";
        cin>>opc;

        switch(opc)
        {
        case '1':
            system("cls");
            l.insertar();
            break;

        case '2':
            system("cls");
            l.leer();
            cout<<"BUSCAR"<<endl;
            cout<<"----------------------------------"<<endl;
            cout<<"Introduce el identificador del producto que vas a buscar"<<endl;
            cout<<"> ";
            cin>>cadena;

            aux=l.busqueda(cadena);
            l.recuperar(aux);
            break;

        case '3':
            system("cls");
            cout<<"ELIMINAR"<<endl;
            cout<<"--------------------------"<<endl;
            cout<<"\nPROXIMAMENTE"<<endl;
            // l.eliminar();
            break;

        case '4':
            system("cls");
            cout<<"VACIAR"<<endl;
            cout<<"----------------------------------"<<endl;
            cout<<"PROXIMAMENTE"<<endl;
            /*cin>>sino;

            switch(sino)
            {
            case 's':
            case 'S':
                l.eliminarTodo();
                break;
            case 'n':
            case'N':
                break;
            default:
                system("cls");
                cout<<"----------------------------------"<<endl;
                cout<<" ERROR | Opcion incorrecta        "<<endl;
                cout<<"----------------------------------"<<endl;
                cout<<"\n\n\nPresiona  [<-]ENTER  para continuar"<<endl;
                getch();*/
                break;


        case '5':
            system("cls");
            l.leer();
            cout<<"MOSTRAR TODO"<<endl;
            l.imprimir_lista();
            break;

        case '6':
            break;

        default:
            system("cls");
            cout<<"----------------------------------"<<endl;
            cout<<" ERROR | Opcion incorrecta        "<<endl;
            cout<<"----------------------------------"<<endl;
            cout<<"\n\n\nPresiona  [<-]ENTER  para continuar"<<endl;
            getch();
            break;
        }

    }
    while(opc!='6');


}
