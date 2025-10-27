#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class album {
private:
    int id;                
    char* nombre;          
    char* artista;         
    int anio;              
    char* genero;          
    char* rutaPortada;     
    char* duracionTotal;   
    
public:
    
    album(); 
    album(int id, const char* nombre, const char* artista, int anio, const char* genero, const char* rutaPortada, const char* duracionTotal);
    album(const album& otro); 
    ~album(); 
    
    // getter
    int getId() const;
    const char* getNombre() const;
    const char* getArtista() const;
    int getAnio() const;
    const char* getGenero() const;
    const char* getRutaPortada() const;
    const char* getDuracionTotal() const;
    
    
    void cargarDesdeArchivo(ifstream& archivo); // Carga datos desde el archivo
    void mostrarInfo() const;                   // Muestra la información del álbum
};

#endif // ALBUM_H
