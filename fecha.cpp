#include "fecha.h"

Fecha::Fecha() {
    dia = 1;
    mes = 1;
    year = 1000;
}

Fecha::Fecha(int d, int m, int a){
    dia = d;
    mes = m;
    year = a;
}

void Fecha::pedirFecha(){
    cout<<"Dia: ";
    cin>> dia;
    cout<< "mes: ";
    cin>> mes;
    cout<"Año: ";
    cin>> year;   
}
void Fecha::mostrarFecha() const{
    cout<<dia<<"/"<<mes<<"/"<<year;
}
