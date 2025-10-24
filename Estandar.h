#ifndef ESTANDAR_H
#define ESTANDAR_H
#include"usuario.h"
#include<iostream>
#include <fstream>
#include <cstring>
using namespace std;

class estandar : public usuario {
private:
    int contador;//Para saber las cuantas canciones se reproducen
                                    
public:
    estandar(const char* nickname, const char* contraseña, const char* contrasena, const char* tipo);
                                    
    void repoducirCanciones(); //leer canciones.txt
    void mostrarPublicidad(); //leer publicidad.txt
    
};

#endif // ESTANDAR_H
