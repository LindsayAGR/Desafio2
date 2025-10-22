#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include <fstream>
#include <cstring>
class usuario
{
private:
    int idUsu;
    char* nickname;
    char* contraseña;
    char* tipo; //ya sea premium o estndar
    char* ciudad;
    char* pais;
public:
    //constructores
    usuario();
    usuarios(const char nick, const char* pass, const char* tip);
    usuarios(const usuario& TipU);
    ~usuarios();
    //getters
    const char* getnickname() const;
    const char* gatTipo() const;
    
    //metodos
    bool verificarTip( char nick, const char* pass) const;
    
    usuario* buscarUsu(const char* nick, const char* pass);
};

#endif // USUARIO_H

