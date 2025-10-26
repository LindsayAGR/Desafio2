#include "premium.h"
#include <<iostream>>
#include <cstring>
#include <cstdlib>
#include <ctime> 
using namespace std;

premium::premium(const char* nickname, const char* contrasena, const char* tipo)
    : usuario(nickname,contrasena,tipo)
{
    favoritos = new char[2]; strcpy(favortos, "");
    siguiendo = new char[2]; strcpy(siguiendo, "");
    
    cout<<"\n Ingrese la fecha de suscripcion de "<<nickname<<":"<<endl;
    fechaSuscrip.pedirFecha();
   
}


premium::~premium()
{
    delete[] favoritos;
    delete[] siguiendo;
}

//agregar a favoritos cancion
void premium::AgregarFavoritos(int idCan){
    ofstream archivo("favoritos.txt", ios::app);//crea archivo porque no existe
    if (!archivo){
        cout<<"No se pudo abrir o crear. "
        return;
    }
    archivo << idCan <<";"<<endl;
    archivo.close();

    cout<<"Canción con ID " << idCan << " agregada a favoritos." << endl;

}
//eliminar de favoritos
void premium::EliminarFavoritos(int idCan){
    ifstream entrada("favoritos.txt");
    if(!entrada){
        ofstream crear("favoritos.txt");    
        crear.close()
        cout<<"no exixtia, se ha creado vacío."<<endl;
        return;
    }
    ofstream temp("temporal.txt");
    if (!temp){
        cout<<"no se pudo crear el archivo temporal"<<endl;
        return;
    }
    
    char linea[20];
    bool eliminado = false;
    while(entrada.getline(linea,20)){
        int id = atoi(linea);
        if (id =idCan){
            temp<<linea<<endl;
        } else{
            eliminado = true;
        }
    }
    entrada.close();
    temp.close();
    
    remove("favoritos.txt");
    rename("temp.txt", "favoritos.txt");
    
    if (eliminado)
        cout << "Canción con ID " << idCan << " eliminada de favoritos." << endl;
    else
        cout << "La canción no estaba en favoritos." << endl;
}
    //seguir otra lista o usuario
void premium::SeguirLista(const char* usuarioSeguido) {
    delete[] siguiendo;
    siguiendo = new char[strlen(usuarioSeguido) + 1];
    strcpy(siguiendo, usuarioSeguido);
    cout << "Ahora estás siguiendo a: " << siguiendo << endl;
}
//Reproducir canciones normales 
void premium::ReproducirCan(bool OrdenAleatorio) {
    ifstream archivo("canciones.txt");
    if (!archivo) {
        cout << "No se pudo abrir canciones.txt" << endl;
        return;
    }
    
    cout << "\n Reproduciendo canciones Premium ";
    if (OrdenAleatorio)
        cout << "en modo ALEATORIO\n";
    else
        cout << "en ORDEN normal\n";
    
    char linea[200];
    archivo.getline(linea, 200); // saltar encabezado
    
    while (archivo.getline(linea, 200)) {
        
        char* token = strtok(linea, "|");
        int id = atoi(token);
        token = strtok(NULL, "|");
        char* nombre = token;
        token = strtok(NULL, "|");
        char* artista = token;
        token = strtok(NULL, "|");
        char* album = token;
        token = strtok(NULL, "|");
        char* rutaPortada = token;
        token = strtok(NULL, "|");
        char* rutaAudio = token;
        token = strtok(NULL, ";");
        char* duracion = token;
        
        cout <<"\n-----------------------------------\n";
        cout << "Cantante: " << artista << endl;
        cout << "Álbum: " << album << endl;
        cout << "Ruta a la portada: " << rutaPortada << endl;
        cout << "Título: " << nombre << endl;
        cout << "Ruta del audio: " << rutaAudio << endl;
        cout << "Duración: " << duracion << endl;
    }
    
    archivo.close();
}
//reproduccir favoritas
void premium::ReproducirFavoritos(bool OrdenAleatorio) {
    ifstream fav("favoritos.txt");
    if (!fav) {
        cout << "No tienes canciones favoritas aún." << endl;
        return;
    }
    
    int ids[100]; // guarda los ids favoritos
    int total = 0;
    char linea[20];
    
    while (fav.getline(linea, 20)) {
        ids[total++] = atoi(linea);
    }
    fav.close();
    
    ifstream canciones("canciones.txt");
    if (!canciones) {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }
    cout << "\n Reproduciendo tus canciones favoritas ";
    if (OrdenAleatorio)
        cout << "(modo ALEATORIO)" << endl;
    else
        cout << "(modo NORMAL)" << endl;

    char datos[200];
    canciones.getline(datos, 200); // saltar encabezado

    while (canciones.getline(datos, 200)) {
        char* token = strtok(datos, "|");
        int id = atoi(token);
        token = strtok(NULL, "|");
        char* nombre = token;
        token = strtok(NULL, "|");
        char* artista = token;
        token = strtok(NULL, "|");
        char* album = token;
        token = strtok(NULL, "|");
        char* rutaPortada = token;
        token = strtok(NULL, "|");
        char* rutaAudio = token;
        token = strtok(NULL, ";");
        char* duracion = token;

        // verificar si el id está en los favoritos
        for (int i = 0; i < total; i++) {
            if (ids[i] == id) {
                cout << "\n----------------------------------" << endl;
                cout << "Cantante: " << artista << endl;
                cout << "Álbum: " << album << endl;
                cout << "Ruta a la portada: " << rutaPortada << endl;
                cout << "Título: " << nombre << endl;
                cout << "Ruta del audio: " << rutaAudio << endl;
                cout << "Duración: " << duracion << endl;
                break;
            }
        }
    }

    canciones.close();
}

void premium::mostrarFechasuscrip() const{
    cout<<"fecha de suscriocion: ";
    fechaSuscrip.mostrarFecha();
    cout <<endl;
}

//  Getters
const char* premium::getSiguiendo() const { return siguiendo; }
const char* premium::getFavoritos() const { return favoritos; }

