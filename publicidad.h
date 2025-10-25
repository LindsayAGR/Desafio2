#ifndef PUBLICIDAD_H
#define PUBLICIDAD_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace  std;

class publicidad{
private:
    char* tipo;
    char* mensaje;

public:
    publicidad();
    publicidad(const char* tip, const char* men);
    publicidad(const publicidad& publi);
    ~publicidad();

//getters
    const char* getTipo() const;
    const char* getMensaje() const;

    void mostrarPublicidad() const;

    static publicidad* cargarPublicidades(int& publi);


};

#endif // PUBLICIDAD_H
