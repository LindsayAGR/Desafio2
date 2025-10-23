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
