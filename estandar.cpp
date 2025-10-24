#include "estandar.h"

estandar::estandar(const char* nickname, const char* contrasena, const char* tipo)
    : usuario(nickname,contrasena,tipo) {
    contador=0;
    
}
//reproducir canciones
void estandar::repoducirCanciones(){
    ifstream archivo("canciones.txt");
    if(!archivo){
        cout <<"No se pudo abrir el archivo"<<endl;
        return;
    }
    
    char linea[200];
    archivo.getline(linea,200);//saltar
    
    while (archivo.getline(linea,200)){
        
        
        char* token = strtok(linea, "|");
        if  (!token) continue;
        char* id = token;
        
        token = strtok(NULL,"|");
        char* nombre = token;
        
        token = strtok(NULL,"|");
        char* artista = token;
        
        token = strok(NULL,"|");
        char* album = token;
        
        token = strtok(NULL, "|");
        char* genero = token;
        
        token = strtok(NULL, "|");
        char* duracion = token;
        
        token = strtok(NULL, "|");
        char* min = token;
        
        token = strtok(NULL, "|");
        char* rutabase = token;
        
        token = strtok(NULL, ";")
        char* reproducciones = token;
        
        contador++;
        
        if (contador% 2==0){
            mostrarPublicidad();
        }
        
        
