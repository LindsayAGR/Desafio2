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
    siguiendo = new char[2]; strcpy(siguiendo, "")
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
    
    
    
}
