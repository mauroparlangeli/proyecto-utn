#ifndef FECHAS_H_INCLUDED
#define FECHAS_H_INCLUDED

///DECLARACION DE LA CLASE FECHA

///CAMBIAR PARA SOLO VALIDAR FECHAS IGUALES O ANTERIORES A LA ACTUAL
class Fecha{
private:
    int dia, mes, anio;
public:
    Fecha(){
    dia=01;
    mes=01;
    anio=2000;
    }

    void Cargar(){
    cout<<"DIA: ";
    cin>>dia;
    cout<<endl;
    cout<<"MES: ";
    cin>>mes;
    cout<<endl;
    cout<<"ANIO: ";
    cin>>anio;
    cout<<endl;
    }

    void Mostrar(){
        cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
    }

    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}
    void setDia(int d){
    if(d>=1&&d<=31)dia=d;
    }

    void setMes(int m){
    if(m>=1&&m<=12)mes=m;
    }

    void setAnio(int a){
    anio=a;
    }


};


#endif // FECHAS_H_INCLUDED
