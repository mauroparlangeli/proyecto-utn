#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

///FUNCIONES GLOBALES

void cargarcadena (char *pal, int tam){
int i;
fflush(stdin);
for(i=0;i<tam;i++){
    pal[i]=cin.get();
    if (pal[i]=='\n') break;
}
pal[i]='\0';
fflush(stdin);
}


///COMPRUEBA QUE LA FECHA SEA VALIDA
bool FechaValida(int dia1, int mes1, int anio1){
time_t tiempoActual = time(nullptr);
tm* fechaActual = localtime(&tiempoActual);

    if(fechaActual->tm_year + 1900 > anio1){
        return true;
    }else if(fechaActual->tm_year + 1900 == anio1){
        if(fechaActual->tm_mon + 1 > mes1){
            return true;
        }else if(fechaActual->tm_mon + 1 == mes1){
            if(fechaActual->tm_mday >= dia1){
                return true;
            }
        }
    }
    return false;
}




#endif // FUNCIONES_H_INCLUDED
