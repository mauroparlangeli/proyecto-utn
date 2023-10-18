#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

///SECCION CONFIGURACION

///FUNCIONES PARA COPIAR LOS ARCHIVOS A BKP

void copiaJugadores() {
    Jugadores obj;
    FILE* pJug;
    FILE* pJug2;
    pJug = fopen("jugadores.dat", "rb");
    pJug2 = fopen("jugadores.bkp", "wb");
    if (pJug == NULL || pJug2 == NULL) {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        return;
    }
    while (fread(&obj, sizeof(obj), 1, pJug) == 1) {
            fwrite(&obj, sizeof(obj), 1, pJug2);
    }
    fclose(pJug);
    fclose(pJug2);
}

void copiaDeportes() {
    Deportes obj;
    FILE* pDep;
    FILE* pDep2;
    pDep = fopen("deportes.dat", "rb");
    pDep2 = fopen("deportes.bkp", "wb");
    if (pDep == NULL || pDep2 == NULL) {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        return;
    }
    while (fread(&obj, sizeof(obj), 1, pDep) == 1) {
            fwrite(&obj, sizeof(obj), 1, pDep2);
    }
    fclose(pDep);
    fclose(pDep2);
}

///FUNCIONES PARA COPIAR LOS ARCHIVOS BKP A LOS ORIGINALES

void restaurarJugadores() {
    Jugadores obj;
    FILE* pJug;
    FILE* pJug2;
    pJug = fopen("jugadores.dat", "wb");
    pJug2 = fopen("jugadores.bkp", "rb");
    if (pJug == NULL || pJug2 == NULL) {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        return;
    }
    while (fread(&obj, sizeof(obj), 1, pJug2) == 1) {
            fwrite(&obj, sizeof(obj), 1, pJug);
    }
    fclose(pJug);
    fclose(pJug2);
}

void restaurarDeportes() {
    Deportes obj;
    FILE* pDep;
    FILE* pDep2;
    pDep = fopen("deportes.dat", "wb");
    pDep2 = fopen("deportes.bkp", "rb");
    if (pDep == NULL || pDep2 == NULL) {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        return;
    }
    while (fread(&obj, sizeof(obj), 1, pDep2) == 1) {
            fwrite(&obj, sizeof(obj), 1, pDep);
    }
    fclose(pDep);
    fclose(pDep2);
}

///FUNCIONES PARA CARGAR Y ESTABLECER LOS DATOS DE INICIO DE CADA ARCHIVO

void cargarJugadorInicio(){
Jugadores obj;
    FILE *pDep;
        pDep=fopen("iniciojugadores.dat", "ab");
        if(pDep==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
            return;
        }
        obj.Cargar();
        fwrite(&obj, sizeof obj, 1, pDep);
        fclose(pDep);
}


void cargarDeporteInicio(){
Deportes obj;
    FILE *pDep;
        pDep=fopen("iniciodeportes.dat", "ab");
        if(pDep==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
            return;
        }
        obj.Cargar();
        fwrite(&obj, sizeof obj, 1, pDep);
        fclose(pDep);
}


void DatosInicioJugadores(){
    Jugadores obj;
    FILE* pJug;
    FILE* pJug2;
    pJug = fopen("jugadores.dat", "wb");
    pJug2 = fopen("iniciojugadores.dat", "rb");
    if (pJug == NULL || pJug2 == NULL) {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        return;
    }
    while (fread(&obj, sizeof(obj), 1, pJug2) == 1) {
            fwrite(&obj, sizeof(obj), 1, pJug);
    }
    fclose(pJug);
    fclose(pJug2);
}

void DatosInicioDeportes(){
    Deportes obj;
    FILE* pDep;
    FILE* pDep2;
    pDep = fopen("deportes.dat", "wb");
    pDep2 = fopen("iniciodeportes.dat", "rb");
    if (pDep == NULL || pDep2 == NULL) {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        return;
    }
    while (fread(&obj, sizeof(obj), 1, pDep2) == 1) {
            fwrite(&obj, sizeof(obj), 1, pDep);
    }
    fclose(pDep);
    fclose(pDep2);
}

void EstablecerDatosInicio(){
    DatosInicioJugadores();
    DatosInicioDeportes();
}



///SECCION REPORTES

///CLASES PARA LA RESOLUCION DE PUNTOS
class jugadorEquipoMayor15{
private:
    int dni;
    char nombre[30], apellido[30];
    Fecha fechaInscripcion;

public:
    jugadoresEquipoMayor15(int d = 0, const char n[30] = "NN", const char a[30] = "NA", Fecha fecha = Fecha()) {
        dni = d;
        strcpy(nombre, n);
        strcpy(apellido, a);
        fechaInscripcion = fecha;
    }


    void setDni(int d){dni = d;}
    void setNombre(const char* n){strcpy(nombre,n);}
    void setApellido(const char* a){strcpy(apellido,a);}
    void setFechaInscripcion(Fecha fecha){fechaInscripcion = fecha;}

    void mostrar(){
    cout<<"DNI: "<<dni<<endl;
    cout<<"NOMBRE: "<<nombre<<endl;
    cout<<"APELLIDO: "<<apellido<<endl;
    cout<<"FECHA DE INSCRIPCION: ";
    fechaInscripcion.Mostrar();
    cout<<endl;
    }

};





///MENU DE CONFIGURACION

    void menuConfiguracion(){
        int opc;
     while(true){
    system("cls");

    cout<<"                   MENU DE CONFIGURACION"<<endl;
    cout<<"----------------------------------------------------"<<endl;
    cout<<"1) COPIA DE SEGURIDAD DEL ARCHIVO DE JUGADORES"<<endl;
    cout<<"2) COPIA DE SEGURIDAD DEL ARCHIVO DE DEPORTES"<<endl;
    cout<<"3) RESTAURAR EL ARCHIVO DE JUGADORES"<<endl;
    cout<<"4) RESTAURAR EL ARCHIVO DE DEPORTES"<<endl;
    cout<<"5) ESTABLECER DATOS DE INICIO"<<endl;
    cout<<"----------------------------------------------------"<<endl;
    cout<<"0) SALIR"<<endl;

    cout<<"INGRESE UNA OPCION:"<<endl;
    cin>>opc;

    system("cls");

    switch(opc)
    {
        case 1:copiaJugadores();
        break;
        case 2:copiaDeportes();
        break;
        case 3:restaurarJugadores();
        break;
        case 4:restaurarDeportes();
        break;
        case 5:EstablecerDatosInicio();
        break;
        case 0: return ;
        break;
        default: cout<<"ERROR, OPCION INCORRECTA"<<endl<<endl;
        break;
    }
    system ("pause");
    }
 }


#endif // REPORTES_H_INCLUDED
