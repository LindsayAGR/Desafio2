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
         cout <<"\n-----------------------------------\n";
        cout<<"Cantante: "<<artista<<endl;
        cout<<"Album: " <<album <<endl;
        cout<<"Ruta del archivo de audio: "<<rutabase<<endl;
        cout<<"Duracion: "<<duracion<<endl;
        cout<<"\nOpciones: "<<endl;
        cout << "1. Reproducir" << endl;
        cout << "2. Detener" << endl;
    }
    archivo.close();
        
    }
//Mostrar publicidad
    void estandar::mostrarPublicidad(){
        ifstream archivo("Publicidad.txt")
        if(!archivo){
           cout<<"No se pudo abrir el archivo"<<endl;
            return;
        }
        
        char linea[200];
        
        // lee una línea del archivo (la siguiente publicidad)
        if (archivo.getline(linea, 200)) {
            // Categoría|Mensaje;
            char* categoria = strtok(linea, "|");
            char* mensaje = strtok(NULL, ";");
            
            cout << "\n--- PUBLICIDAD ---" << endl;
            cout << "Mensaje publicitario: " << mensaje << endl;
            cout << "Categoría: " << categoria << endl;
            cout << "------------------" << endl;
        }
        
        archivo.close();
    }
}       
        
