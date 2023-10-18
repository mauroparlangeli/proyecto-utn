///AUTOR: PARLANGELI MAURO
///LEGAJO: 27688

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

#include "fechas.h"
#include "funciones.h"
#include "deportes.h"
#include "jugadores.h"
#include "reportes.h"


    void menuJugadores(){
        int opc;
     while(true){
    system("cls");

    cout<<"                   MENU JUGADORES"<<endl;
    cout<<"----------------------------------------------------"<<endl;
    cout<<"1) AGREGAR JUGADOR"<<endl;
    cout<<"2) LISTAR JUGADOR POR DNI"<<endl;
    cout<<"3) LISTAR TODOS LOS JUGADORES"<<endl;
    cout<<"4) MODIFICAR FECHA DE INSCRIPCION"<<endl;
    cout<<"5) ELIMINAR REGISTRO DE JUGADOR"<<endl;
    cout<<"----------------------------------------------------"<<endl;
    cout<<"0) SALIR"<<endl;

    cout<<"INGRESE UNA OPCION:"<<endl;
    cin>>opc;

    system("cls");

    switch(opc)
    {
        case 1:cargarJugador();
        break;
        case 2:leerJugadorPorDNI();
        break;
        case 3:leerJugadores();
        break;
        case 4:modificarFecha();
        break;
        case 5:bajaLogicaJug();
        break;
        case 0: return ;
        break;
        default: cout<<"ERROR, OPCION INCORRECTA"<<endl<<endl;
        break;
    }
    system ("pause");
    }
 }


    void menuDeportes(){
        int opc;
     while(true){
    system("cls");

    cout<<"                   MENU DEPORTES"<<endl;
    cout<<"----------------------------------------------------"<<endl;
    cout<<"1) AGREGAR DEPORTE"<<endl;
    cout<<"2) LISTAR DEPORTE POR ID"<<endl;
    cout<<"3) LISTAR TODOS LOS DEPORTES"<<endl;
    cout<<"4) MODIFICAR ANIO DE ORIGEN"<<endl;
    cout<<"5) ELIMINAR REGISTRO"<<endl;
    cout<<"----------------------------------------------------"<<endl;
    cout<<"0) SALIR"<<endl;

    cout<<"INGRESE UNA OPCION:"<<endl;
    cin>>opc;

    system("cls");

    switch(opc)
    {
        case 1:cargarDeporte();
        break;
        case 2:leerDeportePorID();
        break;
        case 3:leerDeportes();
        break;
        case 4:modificarAnio();
        break;
        case 5:bajaLogicaDep();
        break;
        case 0: return ;
        break;
        default: cout<<"ERROR, OPCION INCORRECTA"<<endl<<endl;
        break;
    }
    system ("pause");
    }
 }


int main(){
int opc;

 while(true){
    system("cls");

    cout<<"                   MENU PRINCIPAL"<<endl;
    cout<<"----------------------------------------------------"<<endl;
    cout<<"1) MENU JUGADORES"<<endl;
    cout<<"2) MENU DEPORTES"<<endl;
    cout<<"4) CONFIGURACION"<<endl;
    cout<<"----------------------------------------------------"<<endl;
    cout<<"0) SALIR"<<endl;

    cout<<"INGRESE UNA OPCION:"<<endl;
    cin>>opc;

    system("cls");

    switch(opc)
    {
        case 1:menuJugadores();
        break;
        case 2:menuDeportes();
        break;
        case 4:menuConfiguracion();
        break;
        case 0: return 0;
        break;
        default: cout<<"ERROR, OPCION INCORRECTA"<<endl<<endl;
        break;
    }
    system ("pause");
    }

return 0;
system("pause");
}
