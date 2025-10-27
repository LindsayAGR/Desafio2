#include "publicidad.h"

publicidad::publicidad() {
    tipo = new char[2];
    strcpy(tipo,"");
    mensaje = new char[2];
    strcpy(mensaje, "");

}


publicidad::publicidad(const char *tip, const char *men){
    tipo = new char[strlen(tip)+1];
    strcpy(tipo,tip);
    mensaje = new char[strlen(men)+1];
    strcpy(mensaje, men);

}

publicidad::publicidad(const publicidad& otra){
    tipo = new char[strlen(otra.tipo)+1];
    strcpy(tipo, otra.tipo);
    mensaje = new char[strlen(otra.mensaje)+1];
        strcpy(mensaje,otra.mensaje);

}
publicidad::~publicidad(){
    delete[] tipo;
    delete[] mensaje;
}

//getter
const char* publicidad::getTipo() const {
    return tipo;
}

const char* publicidad::getMensaje() const {
    return mensaje;
}

void publicidad::mostrarPublicidad() const {
    cout<<"\n[" << tipo << "]" << mensaje << endl;
}

//cargar todas las punlicidades

publicidad* publicidad::cargarpublicidades(int& publi) {
    ifstream archivo("publicidad.txt");
    if (!archivo) {
        cout << "No se pudo abrir archivo" << endl;
        publi = 0;
        return nullptr;
    }

    char linea[300];
    publi= 0;

    // Contamos cuántas líneas válidas hay
    while (archivo.getline(linea, 300)) {
        if (strlen(linea) > 0)
            publi++;
    }

    archivo.clear();
    archivo.open("Publicidad.txt")

        // Creamos el arreglo dinámico
    publicidad* lista = new publicidad[publi];
    int i = 0;

    while (archivo.getline(linea, 300)) {
        if (strlen(linea) == 0) continue;

        char* token = strtok(linea, "|");
        if (!token) continue;
        char tip[10];
        strcpy(tip, token);

        token = strtok(NULL, ";");
        if (!token) continue;
        char men[250];
        strcpy(men, token);

        lista[i] = Publicidad(tip, men);
        i++;
    }

    archivo.close();
    return lista;
}
