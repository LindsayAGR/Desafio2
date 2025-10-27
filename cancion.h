#ifndef CANCION_H
#define CANCION_H

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class cancion {
private:
    int id;
    char* nomCan;
    char* artista;
    char* album;
    char* genero;
    int duracion;

public:

    cancion();
    cancion(int id, const char* nomCan, const char* artista, const char* album, const char* genero, int duracion);
    cancion(const cancion& otra); // constructor de copia
    ~cancion(); // destructor

    // getter
    int getId() const;
    const char* getNombre() const;
    const char* getArtista() const;
    const char* getAlbum() const;
    const char* getGenero() const;
    int getDuracion() const;


    void cargarDesdeArchivo(ifstream& archivo);
    void mostrarInfo() const;
};

#endif // CANCION_H
