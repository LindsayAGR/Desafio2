#include "usuario.h"
#include "iostream"
using namespace std ;

//Constructor

usuario::usuario() {
    nickname = new char[2]; strcpy(nickname, "");
    contrasena = new char[2]; strcpy(contrasena, "");
    tipo = new char[2]; strcpy(tipo,"");
}
//contructor parmetros
usuario::usuario(const char* nickname, const char*  contrasena, const char* tipo) {
    nickname = new char[strlen(nickname)+1];
    strcpy(nickname, nickname);

    contrasena = new char [strlen(contrasena)+1];
    strcpy(contrasena, contrasena);

    tipo = new char[strlen(tipo)+1];
    strcpy(tipo,tipo);

}
//contructor copia
usuario::usuarios(const usuario& TipU){
    nickname = new char [strlen(TipU.nickname+1];
    strcpy(nickname, TipU.nickname);

    contrasena = new char[strlen(TipU.contrasena)+1];
    strcpy(contrasena,TipU.contrasena);

    tipo = new char [strlen(TipU.tipo)+1];
    strcpy(tipo,TipU.tipo);

}
//destrctor
usuario::~usuarios(){
    delete[]nickname;
    delete[]contrasena;
    delete[]tipo;

}
//geters
const char* usuario::getnickname() const {return nickname;}
const char* usuario::getTipo() const {return tipo; }
//verificar validez
bool usuario::buscarUsu(const char* nickname, const char* contrasena){
    ifstream archivo("Usuarios.txt");
    
    if (!archivo.is_open()){
        cout<<"No se pudo abrir el archivo"<<endl;
        return nullptr;
    }
}



char linea[200];//maximo 199 caracteres
archivo.getline(linea, 200); // Saltar la primer linea

while (archivo.getline(linea, 200)) {
    // Lindsay|123alli|estandar;

    char* token = strtok(linea, "|");
    if (!token) continue;
    char* TipUnickname = token;

    token = strtok(nullptr, "|");
    if (!token) continue;
    char* TipUcontrasena = token;

    token = strtok(nullptr, ";");
    if (!token) continue;
    char* TipUTipo = token;

    if (strcmp(TipUnickname, nickname) == 0 && strcmp(TipUcontrasena, contrasena) == 0) {
        archivo.close();
        return new Usuario(TipUnickname TipUcontrasena, TipUTipo);
    }
}

archivo.close();
return nullptr; // No se encontró el usuario
}


