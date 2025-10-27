#include "artista.h"

// Constructor vacío
artista::artista() {
    id = new char[10]; strcpy(id, "");
    nombre = new char[50]; strcpy(nombre, "");
    pais = new char[30];strcpy(pais, "");
   
    edad = 0;
    seguidores = 0;
    posicion = 0;
}

// Constructor con parámetros
artista::artista(const char* id_, const char* nombre_, int edad_, const char* pais_, int seguidores_, int posicion_) {
    id = new char[strlen(id_) + 1];
    strcpy(id, id_);

    nombre = new char[strlen(nombre_) + 1];
    strcpy(nombre, nombre_);

    pais = new char[strlen(pais_) + 1];
    strcpy(pais, pais_);

    edad = edad_;
    seguidores = seguidores_;
    posicion = posicion_;
}

// Constructor de copia (para copiar bien los punteros)
artista::artista(const artista& otro) {
    id = new char[strlen(otro.id) + 1];
    strcpy(id, otro.id);

    nombre = new char[strlen(otro.nombre) + 1];
    strcpy(nombre, otro.nombre);

    pais = new char[strlen(otro.pais) + 1];
    strcpy(pais, otro.pais);

    edad = otro.edad;
    seguidores = otro.seguidores;
    posicion = otro.posicion;
}

// Destructor (libera la memoria de los punteros)
artista::~artista() {
    delete[] id;
    delete[] nombre;
    delete[] pais;
}

// getter
const char* artista::getId() const { return id; }
const char* artista::getNombre() const { return nombre; }
int artista::getEdad() const { return edad; }
const char* artista::getPais() const { return pais; }
int artista::getSeguidores() const { return seguidores; }
int artista::getPosicion() const { return posicion; }



// Carga un artista desde el archivo 
void artista::cargarDesdeArchivo(ifstream& archivo) {
    char linea[200];

    if (archivo.getline(linea, 200)) {

        char* token = strtok(linea, "|");
        if (!token) return;
        strcpy(id, token);

        token = strtok(NULL, "|");
        strcpy(nombre, token);

        token = strtok(NULL, "|");
        edad = atoi(token);

        token = strtok(NULL, "|");
        strcpy(pais, token);

        token = strtok(NULL, "|");
        seguidores = atoi(token);

        token = strtok(NULL, ";");
        posicion = atoi(token);
    }
}

// Muestra en pantalla los datos del artista
void artista::mostrarInfo() const {
    cout << "\n--------------------------------------\n";
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << " años" << endl;
    cout << "País: " << pais << endl;
    cout << "Seguidores: " << seguidores << endl;
    cout << "Posición global: " << posicion << endl;
    cout << "--------------------------------------\n";
}
