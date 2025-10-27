#include "album.h"


album::album() {
    id = 0;
    nombre = new char[50]; strcpy(nombre, "");
    artista = new char[50]; strcpy(artista, "");
    genero = new char[50]; strcpy(genero, "");
    rutaPortada = new char[150]; strcpy(rutaPortada, "");
    duracionTotal = new char[10]; strcpy(duracionTotal, "");
    anio = 0;
}


album::album(int id, const char* nombre, const char* artista, int anio, const char* genero, const char* rutaPortada, const char* duracionTotal) {
    id = id;

    nombre = new char[strlen(nombre) + 1];
    strcpy(nombre, nombre);

    artista = new char[strlen(artista) + 1];
    strcpy(artista, artista);

    genero = new char[strlen(genero) + 1];
    strcpy(genero, genero);

    rutaPortada = new char[strlen(rutaPortada) + 1];
    strcpy(rutaPortada, rutaPortada);

    duracionTotal = new char[strlen(duracionTotal) + 1];
    strcpy(duracionTotal, duracionTotal);

    anio = anio;
}

// Constructor de copia

album::album(const album& otro) {
    id = otro.id;

    nombre = new char[strlen(otro.nombre) + 1];
    strcpy(nombre, otro.nombre);

    artista = new char[strlen(otro.artista) + 1];
    strcpy(artista, otro.artista);

    genero = new char[strlen(otro.genero) + 1];
    strcpy(genero, otro.genero);

    rutaPortada = new char[strlen(otro.rutaPortada) + 1];
    strcpy(rutaPortada, otro.rutaPortada);

    duracionTotal = new char[strlen(otro.duracionTotal) + 1];
    strcpy(duracionTotal, otro.duracionTotal);

    anio = otro.anio;
}


album::~album() {
    delete[] nombre;
    delete[] artista;
    delete[] genero;
    delete[] rutaPortada;
    delete[] duracionTotal;
}
//getter
int album::getId() const { return id; }
const char* album::getNombre() const { return nombre; }
const char* album::getArtista() const { return artista; }
int album::getAnio() const { return anio; }
const char* album::getGenero() const { return genero; }
const char* album::getRutaPortada() const { return rutaPortada; }
const char* album::getDuracionTotal() const { return duracionTotal; }


// Cargar datos desde archivo

void album::cargarDesdeArchivo(ifstream& archivo) {
    char linea[300];

    if (archivo.getline(linea, 300)) {
        char* token = strtok(linea, "|");
        if (!token) return;
        id = atoi(token);

        token = strtok(NULL, "|");
        strcpy(nombre, token);

        token = strtok(NULL, "|");
        strcpy(artista, token);

        token = strtok(NULL, "|");
        anio = atoi(token);

        token = strtok(NULL, "|");
        strcpy(genero, token);

        token = strtok(NULL, "|");
        strcpy(rutaPortada, token);

        token = strtok(NULL, ";");
        strcpy(duracionTotal, token);
    }
}

// Mostrar información del álbum
void album::mostrarInfo() const {
    cout << "\n--------------------------------------\n";
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Artista: " << artista << endl;
    cout << "Año: " << anio << endl;
    cout << "Género: " << genero << endl;
    cout << "Ruta de portada: " << rutaPortada << endl;
    cout << "Duración total: " << duracionTotal << endl;
}

