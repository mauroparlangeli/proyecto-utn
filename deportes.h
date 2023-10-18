#ifndef DEPORTES_H_INCLUDED
#define DEPORTES_H_INCLUDED

///DECLARACION DE LA CLASE DEPORTE
class Deportes{
private:
    int id, tipoDeporte, anioOrigen;
    char nombre[30];
    bool estado;

public:
    int getID(){return id;}
    char getNombre(){return *nombre;}
    int getTipo(){return tipoDeporte;}
    int getAnio(){return anioOrigen;}
    bool getEstado(){return estado;}
    void setID(int i){id=i;}
    void setNombre(const char n[30]){strcpy(nombre,n);}
    void setTipo(int t){
    while(t<1||t>21){
        cout<<"EL VALOR INGRESADO NO ES VALIDO, INGRESE UN NUEVO VALOR: ";
        cin>>t;
    }
    tipoDeporte=t;
    }
    void setAnio(int a){
        while(a<1800||a>2023){
        cout<<"EL VALOR INGRESADO NO ES VALIDO, INGRESE UN NUEVO VALOR: ";
        cin>>a;
    }
    anioOrigen=a;
    }
    void setEstado(bool e){estado=e;}

    ///BUSCA EL ID DEL DEPORTE ANTERIOR Y ASIGNA EL SIGUIENTE ID AL PROXIMO REGISTRO
    int BuscarID() {
    Deportes obj;
    int id = 0;
    FILE *pDep;
    pDep = fopen("deportes.dat", "rb");
    if (pDep == NULL) {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        return id;
    }
    while (fread(&obj, sizeof obj, 1, pDep) == 1) {
        if (obj.getID() > id && obj.getID()<10) {
            id = obj.getID();
        }
    }
    fclose(pDep);
    return id + 1;
}

    void Cargar(){
    id=BuscarID();
    cout<<"NOMBRE DEL DEPORTE: ";
    cargarcadena(nombre,29);
    cout<<"TIPO DE DEPORTE: ";
    cin>>tipoDeporte;
    setTipo(tipoDeporte);
    cout<<"ANIO DE ORIGEN: ";
    cin>>anioOrigen;
    setAnio(anioOrigen);
    setEstado(true);
    }

    void Mostrar(){
    if(estado==true){
        cout<<"ID DEL DEPORTE: "<<id<<endl;
        cout<<"NOMBRE DEL DEPORTE: "<<nombre<<endl;
        cout<<"TIPO DE DEPORTE: "<<tipoDeporte<<endl;
        cout<<"ANIO DE ORIGEN: "<<anioOrigen<<endl;
        cout<<"ESTADO: "<<estado<<endl;
    }
    else{cout<<"EL REGISTRO NO EXISTE O HA SIDO DE BAJA."<<endl;}
    }

};

///CARGA REGISTROS INDIVIDUALMENTE
void cargarDeporte(){
Deportes obj;
    FILE *pDep;
        pDep=fopen("deportes.dat", "ab");
        if(pDep==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
            return;
        }
        obj.Cargar();
        fwrite(&obj, sizeof obj, 1, pDep);
        fclose(pDep);
}

///LEE TODOS LOS REGISTROS DE DEPORTES
void leerDeportes(){
Deportes obj;
    FILE *pDep;
        pDep=fopen("deportes.dat", "rb");
        if(pDep==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
            return;
        }
        while(fread(&obj, sizeof obj, 1, pDep)==1){
            obj.Mostrar();
            cout<<endl;
        };
        fclose(pDep);
}

///BUSCA UN DEPORTE EN BASE A SU ID Y DEVUELVE EL REGISTRO
Deportes leerDeporte(int pos){
    Deportes obj;
    if(pos<0){
    obj.setID(-3);
    }
    FILE *pDep;
     pDep=fopen("deportes.dat", "rb");
     if(pDep==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
            obj.setID(-2);
            return obj;
        }
    fseek(pDep, sizeof obj * pos, 0);
    int aux=fread(&obj, sizeof obj, 1, pDep);
    if(aux==0){
        obj.setID(-1);
    }
    return obj;
    fclose(pDep);
}

///BUSCA Y LEE EL REGISTRO CON EL MISMO ID QUE EL INGRESADO
void leerDeportePorID(){
Deportes obj;
int id;
    FILE *pDep;
        pDep=fopen("deportes.dat", "rb");
        if(pDep==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
            return;
        }
        cout<<"INGRESE UN ID: ";
        cin>>id;
        while(fread(&obj, sizeof obj, 1, pDep)==1){
                if(obj.getID()==id){
                    obj.Mostrar();
                }
        };
        fclose(pDep);
}

int contarRegistrosDeporte(){
    FILE *pDep;
        pDep=fopen("deportes.dat", "rb");
                if(pDep==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
            return -1;
                }
            fseek(pDep, 0, SEEK_END);
            int tam=ftell(pDep);
            fclose(pDep);
            if (tam == -1) {
                cout << "Error al obtener el tamaño del archivo" << endl;
                return -1;
            }
            return tam/sizeof(Deportes);
        }


///BUSCA UN DEPORTE EN BASE A SU ID Y DEVUELVE SU POSICION
int buscarDeportePorID(int id){
        Deportes obj;
        int pos=0;
        FILE *pDep;
        pDep=fopen("deportes.dat", "rb");
        if(pDep==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
            return -1;
        }
        while(fread(&obj, sizeof obj, 1, pDep)==1){
        if(obj.getID()==id){
            fclose(pDep);
            return pos;
        }
        pos++;
        }
        fclose(pDep);
        return -1;
}

///MODIFICA UN REGISTRO DE DEPORTE
bool modificarDeporte(Deportes obj, int pos){
        FILE *pDep;
        pDep=fopen("deportes.dat", "rb+");
        fseek(pDep, sizeof obj * pos, 0);
        bool aux=fwrite(&obj, sizeof obj, 1, pDep);
        fclose(pDep);
        return aux;
}

///MODIFICA EL ANIO DE ORIGEN DE UN DEPORTE
bool modificarAnio(){
    Deportes obj;
    int anio2;
       int id;
       cout<<"INGRESE EL ID DEL REGISTRO A MODIFICAR: ";
       cin>>id;
        int pos=buscarDeportePorID(id);
        if(pos==-1){
            cout<<"NO EXISTE UN JUGADOR CON ESE DNI"<<endl;
            return false;
        }
        if(pos==-2){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
            return false;
        }
        cout<<"INGRESE EL NUEVO ANIO DE ORIGEN: ";
        cin>>anio2;
        cout<<endl;

        obj=leerDeporte(pos);
        obj.setAnio(anio2);
        bool aux=modificarDeporte(obj, pos);
        return aux;
}

///DA DE BAJA UN REGISTRO DE DEPORTE
bool bajaLogicaDep(){
    Deportes obj;
       int id;
       cout<<"INGRESE EL ID DEL REGISTRO A BORRAR: ";
       cin>>id;
        int pos=buscarDeportePorID(id);
        if(pos==-1){
            cout<<"NO EXISTE UN JUGADOR CON ESE DNI"<<endl;
            return false;
        }
        if(pos==-2){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
            return false;
        }
        obj=leerDeporte(pos);
        if(obj.getEstado()==false){
            cout<<"EL JUGADOR YA ESTA DADO DE BAJA"<<endl;
            return false;
        }
        obj.setEstado(false);
        bool aux=modificarDeporte(obj, pos);
        return aux;
}


#endif // DEPORTES_H_INCLUDED
