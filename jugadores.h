#ifndef CLS_H_INCLUDED
#define CLS_H_INCLUDED

///DECLARACION DE LA CLASE JUGADOR


class Jugadores{
private:
    int dni, claustro, deporte, numeroEquipo;
    char nombre[30], apellido[30], email[30], telefono[30];
    Fecha fechaInscripcion;
    float matricula;
    bool estado;
public:

///COMPRUEBA QUE EL DNI NO SE REPITA
    bool dniRepetido(int dni){
    FILE* pJug;
    pJug = fopen("jugadores.dat", "rb");
    if (pJug == NULL) {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        return false;
    }

    Jugadores obj;
    bool dniRepetido = false;

    while (fread(&obj, sizeof(obj), 1, pJug)) {
        if (obj.getDNI() == dni) {
            dniRepetido = true;
            break;
        }
    }

    fclose(pJug);

    return dniRepetido;
}

///COMPRUEBA QUE EL ID DE DEPORTE SEA VALIDO
    bool IDValido(int id){
Deportes obj;
    FILE *pDep;
    bool IDValido=false;
        pDep=fopen("deportes.dat", "rb");
        if(pDep==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
            return IDValido;
        }
        while(fread(&obj, sizeof obj, 1, pDep)==1){
            if(obj.getID()==id){
                IDValido=true;
            }
        }
        fclose(pDep);
        return IDValido;
}



    void Cargar(){
        cout<<"DNI: ";
        cin>>dni;
        while (dniRepetido(dni)==true) {
        cout << "El DNI ingresado ya existe. Por favor, ingrese otro DNI: ";
        cin >> dni;
        }
        cout<<"NOMBRE: ";
        cargarcadena(nombre, 29);
        cout<<"APELLIDO: ";
        cargarcadena(apellido, 29);
        cout<<"EMAIL: ";
        cargarcadena(email, 29);
        cout<<"TELEFONO: ";
        cargarcadena(telefono, 29);
        cout<<"CLAUSTRO: ";
        cin>>claustro;
        setClaustro(claustro);
        cout<<"DEPORTE: ";
        cin>>deporte;
        if(IDValido(deporte)==true){
         setDeporte(deporte);
        }
        else{while(IDValido(deporte)==false){cout<<"EL ID INGRESADO NO ES VALIDO, INGRESE UN NUEVO VALOR: "<<endl;
        cin>>deporte;
        }
        }
        cout<<"NUMERO DE EQUIPO: ";
        cin>>numeroEquipo;
        cout<<"FECHA DE INSCRIPCION: ";
        fechaInscripcion.Cargar();
        while (!FechaValida(fechaInscripcion.getDia(), fechaInscripcion.getMes(), fechaInscripcion.getAnio())) {
        cout << "La fecha de inscripción no es válida. Ingrese una fecha válida." << endl;
        fechaInscripcion.Cargar();
        }
        cout<<"MATRICULA: ";
        cin>>matricula;
        setMatricula(matricula);
        setEstado(true);
    }

    void Mostrar(){
        if(estado==true){
        cout<<"DNI: "<<dni<<endl;
        cout<<"NOMBRE: "<<nombre<<endl;
        cout<<"APELLIDO: "<<apellido<<endl;
        cout<<"EMAIL: "<<email<<endl;
        cout<<"TELEFONO: "<<telefono<<endl;
        cout<<"CLAUSTRO: "<<claustro<<endl;
        cout<<"DEPORTE: "<<deporte<<endl;
        cout<<"NUMERO DE EQUIPO: "<<numeroEquipo<<endl;
        cout<<"FECHA DE INSCRIPCION: ";
        fechaInscripcion.Mostrar();
        cout<<"MATRICULA: "<<matricula<<endl;
        cout<<"ESTADO: "<<estado<<endl;}
        else{cout<<"EL REGISTRO NO EXISTE O HA SIDO DE BAJA."<<endl;}

    }

    int getDNI(){return dni;}
    char* getNombre(){return nombre;}
    char* getApellido(){return apellido;}
    char getEmail(){return *email;}
    char getTelefono(){return *telefono;}
    int getClaustro(){return claustro;}
    int getDeporte(){return deporte;}
    int getNumEquipo(){return numeroEquipo;}
    Fecha getFechaInscripcion(){return fechaInscripcion;}
    int getAnio(){ return fechaInscripcion.getAnio();}
    int getMes(){ return fechaInscripcion.getMes();}
    int getDia(){ return fechaInscripcion.getDia();}
    float getMatricula(){return matricula;}
    bool getEstado(){return estado;}

    void setDNI(int d){dni=d;}
    void setNombre(const char n[30]){strcpy(nombre,n);}
    void setApellido(const char a[30]){strcpy(apellido,a);}
    void setEmail(const char e[30]){strcpy(email,e);}
    void setTelefono(const char t[30]){strcpy(telefono,t);}

    void setClaustro(int c){
    while(c<0||c>4){
       cout<<"EL VALOR INGRESADO NO ES COMPATIBLE, INGRESE UN NUEVO VALOR: "<<endl;
       cin>>c;
    }claustro=c;}

    void setDeporte(int d){
        deporte=d;
    }

    void setNumEquipo(int n){numeroEquipo=n;}
    void setFecha(Fecha fecha){fechaInscripcion=fecha;}
    void setMatricula(float m){
    while(m<0){
       cout<<"EL VALOR INGRESADO NO ES COMPATIBLE,INGRESE UN NUEVO VALOR: "<<endl;
       cin>>m;
    }
    ;matricula=m;
    }

    void setEstado(bool e){estado=e;}

};


///CARGA REGISTROS INDIVIDUALMENTE
void cargarJugador(){
Jugadores obj;
    FILE *pJug;
        pJug=fopen("jugadores.dat", "ab");
        if(pJug==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
            return;
        }
        obj.Cargar();
        fwrite(&obj, sizeof obj, 1, pJug);
        fclose(pJug);
}

///LEE EL REGISTRO DE UN JUGADOR EN BASE AL DNI INGRESADO
void leerJugadorPorDNI(){
Jugadores obj;
int dni;
    FILE *pJug;
        pJug=fopen("jugadores.dat", "rb");
        if(pJug==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
            return;
        }
        cout<<"INGRESE EL DNI DEL JUGADOR A BUSCAR: "<<endl;
        cin>>dni;
        while(fread(&obj, sizeof obj, 1, pJug)==1){
                if(obj.getDNI()==dni){
            obj.Mostrar();
                }
            cout<<endl;
        }

        fclose(pJug);
}

///BUSCA UN JUGADOR EN BASE A SU DNI Y DEVUELVE EL REGISTRO
Jugadores leerJugador(int pos){
    Jugadores obj;
    if(pos<0){
    obj.setDNI(-3);
    }
    FILE *pJug;
     pJug=fopen("jugadores.dat", "rb");
     if(pJug==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
            obj.setDNI(-2);
            return obj;
        }
    fseek(pJug, sizeof obj * pos, 0);
    int aux=fread(&obj, sizeof obj, 1, pJug);
    if(aux==0){
        obj.setDNI(-1);
    }
    return obj;
    fclose(pJug);
}

int contarRegistrosJugador(){
Jugadores obj;
    FILE *pJug;
        pJug=fopen("jugadores.dat", "rb");
                if(pJug==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
            return -1;
                }
            fseek(pJug, 0, SEEK_END);
            int tam=ftell(pJug);
            if (tam == -1) {
                cout << "Error al obtener el tamaño del archivo" << endl;
                return -1;
            }
            fclose(pJug);
            return tam/sizeof(Jugadores);
        }

///LEE TODOS LOS REGISTROS DE JUGADORES
void leerJugadores(){
Jugadores obj;
    FILE *pJug;
        pJug=fopen("jugadores.dat", "rb");
        if(pJug==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
            return ;
        }
        while(fread(&obj, sizeof obj, 1, pJug)==1){
            obj.Mostrar();
            cout<<endl;
        }

        fclose(pJug);
}

///BUSCA UN JUGADOR EN BASE A SU DNI Y DEVUELVE SU POSICION
int buscarJugadorPorDNI(int dni){
        Jugadores obj;
        int pos=0;
        FILE *pJug;
        pJug=fopen("jugadores.dat", "rb");
        if(pJug==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
            return -1;
        }
        while(fread(&obj, sizeof obj, 1, pJug)==1){
        if(obj.getDNI()==dni){
            fclose(pJug);
            return pos;
        }
        pos++;
        }
        fclose(pJug);
        return -1;
}

///MODIFICA UN REGISTRO DE JUGADOR
bool modificarJugador(Jugadores obj, int pos){
        FILE *pJug;
        pJug=fopen("jugadores.dat", "rb+");
        fseek(pJug, sizeof obj * pos, 0);
        bool aux=fwrite(&obj, sizeof obj, 1, pJug);
        fclose(pJug);
        return aux;
}

///MODIFICA LA FECHA DE INSCRIPCION DE UN REGISTRO
bool modificarFecha(){
    Jugadores obj;
    Fecha obj2;
       int dni;
       cout<<"INGRESE EL DNI DEL REGISTRO A MODIFICAR: ";
       cin>>dni;
        int pos=buscarJugadorPorDNI(dni);
        if(pos==-1){
            cout<<"NO EXISTE UN JUGADOR CON ESE DNI"<<endl;
            return false;
        }
        if(pos==-2){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
            return false;
        }
        obj=leerJugador(pos);
        obj2.Cargar();
        obj.setFecha(obj2);
        bool aux=modificarJugador(obj, pos);
        return aux;
}

///DA DE BAJA LOGICA UN REGISTRO
bool bajaLogicaJug(){
    Jugadores obj;
       int dni;
       cout<<"INGRESE EL DNI DEL REGISTRO A BORRAR: ";
       cin>>dni;
        int pos=buscarJugadorPorDNI(dni);
        if(pos==-1){
            cout<<"NO EXISTE UN JUGADOR CON ESE DNI"<<endl;
            return false;
        }
        if(pos==-2){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
            return false;
        }
        obj=leerJugador(pos);
        if(obj.getEstado()==false){
            cout<<"EL JUGADOR YA ESTA DADO DE BAJA"<<endl;
            return false;
        }
        obj.setEstado(false);
        bool aux=modificarJugador(obj, pos);
        return aux;
}



#endif // CLS_H_INCLUDED
