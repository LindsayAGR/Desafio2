#ifndef PREMIUM_H
#define PREMIUM_H

#include "usuario.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class premium : public usuario {
private:
    char* favoritos;
    char* siguiendo;
public:
    premium(const char* nickname, const char* contrasena, const char* tipo);
    ~premium();
    
    void AgregarFavoritos(int idCan);
    void EliminarFavoritos(int idCan);
    void SeguirLista(const char* usuario);
    void ReproducirCan(bool OrdenAleatorio);
    void ReproducirFavoritos(bool OrdenAleatorio);
    
    const char* getSiguiendo() const;
    const char* getFavoritos() const;
};

#endif // PREMIUM_H
