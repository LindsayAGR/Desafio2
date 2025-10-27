#include "cancion.h"

cancion::cancion() {
    id = 0;
    nomCan = new char[50]; strcpy(nomCan, "");
    artista = new char[50]; strcpy(artista, "");
    album = new char[50]; strcpy(album, "");
    genero = new char[30]; strcpy(genero, "");
    duracion = 0;
}
cancion::cancion(int id, const char *nomCan, const char *artista, const char *album, const char *genero, int duracion){
    id = id;
    
    nomCan = new char[strlen(nomCan)+1];
    strcpy(nomCan,nomCan);
    
    artista = new char[strlen(artista)+1];
    strcpy(artista,artista);
        
    album = new char[strlen(album) + 1];
    strcpy(album, album);

    genero = new char[strlen(genero) + 1];
    strcpy(genero, genero);
    
    duracion = duracion;
}
//constructor copia
cancion::cancion(const cancion& otra) {
    id = otra.id;
    nomCan = new char[strlen(otra.nomCan) + 1];
    strcpy(nomCan, otra.nomCan);
    
    artista = new char[strlen(otra.artista) + 1];
    strcpy(artista, otra.artista);
    
    album = new char[strlen(otra.album) + 1];
    strcpy(album, otra.album);
    
    genero = new char[strlen(otra.genero) + 1];
    strcpy(genero, otra.genero);
    
    duracion = otra.duracion;
}
//destructor
cancion::~cancion() {
    delete[] nomCan;
    delete[] artista;
    delete[] album;
    delete[] genero;
}
//getter
int cancion::getId() const { return id; }
const char* cancion::getNombre() const { return nomCan; }
const char* cancion::getArtista() const { return artista; }
const char* cancion::getAlbum() const { return album; }
const char* cancion::getGenero() const { return genero; }
int cancion::getDuracion() const { return duracion; }


void cancion::cargarDesdeArchivo(ifstream &archivo){
    char linea[200];
    
    if(archivo.get(linea,200))
        
        char* token = strtok(linea, "|");
        if (!token) return;
        id = atoi(token);
    
        token = strtok(NULL, "|");
        strcpy(nomCan, token);
    
        token = strtok(NULL, "|");
        strcpy(artista, token);
    
        token = strtok(NULL, "|");
        strcpy(album, token);
    
        token = strtok(NULL, "|");
        strcpy(genero, token);
    
        token = strtok(NULL, ";");
        duracion = atoi(token);
    }
}
//mostrar info
void cancion::mostrarInfo() const {
    cout << "\n--------------------------------------\n";
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nomCan << endl;
    cout << "Artista: " << artista << endl;
    cout << "Álbum: " << album << endl;
    cout << "Género: " << genero << endl;
    cout << "Duración: " << duracion << " min" << endl;
    
}

void cancion::cargarDesdeArchivo(ifstream &archivo){
    char linea[200];
    
    if(archivo.get(linea,200))
        
        char* token = strtok(linea, "|");
        if (!token) return;
        id = atoi(token);
    
        token = strtok(NULL, "|");
        strcpy(nomCan, token);
    
        token = strtok(NULL, "|");
        strcpy(artista, token);
    
        token = strtok(NULL, "|");
        strcpy(album, token);
    
        token = strtok(NULL, "|");
        strcpy(genero, token);
    
        token = strtok(NULL, ";");
        duracion = atoi(token);
    }
}
//mostrar info
void cancion::mostrarInfo() const {
    cout << "\n--------------------------------------\n";
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nomCan << endl;
    cout << "Artista: " << artista << endl;
    cout << "Álbum: " << album << endl;
    cout << "Género: " << genero << endl;
    cout << "Duración: " << duracion << " min" << endl;
    
}




