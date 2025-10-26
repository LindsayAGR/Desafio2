#ifndef FECHA_H
#define FECHA_H

#include <iostream>
using namespace std;

class Fecha {
private:
    int dia;
    int mes;
    int year;
    
public:
    // Constructores
    Fecha();
    Fecha(int d, int m, int a);
    
    // Getters
    int getDia() const;
    int getMes() const;
    int getYear() const;
    
    // Setters
    void setDia(int d);
    void setMes(int m);
    void setYear(int a);
    
    // Mostrar la fecha
    void mostrarFecha() const;
};

#endif // FECHA_H
