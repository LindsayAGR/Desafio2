#include <iostream>
#include <fstream>
#include <cstring>
#include "usuario.h"
#include "premium.h"
#include "estandar.h"
#include "cancion.h"
#include "album.h"
#include "artista.h"
#include "publicidad.h"
#include "fecha.h"
using namespace std;

int main() {
    char nick[50];
    char pass[50];
    char opcion = 's';

    cout << "=============================================================\n";
    cout << "      >> BIENVENIDO A VIVE LA MUSICA CON UDEATUNES <<\n";
    cout << "=============================================================\n";
    cout << "             Tu musica, tu estilo, tu mundo sonoro.            \n";
    cout << "-------------------------------------------------------------\n";
    cout << "Presiona ENTER para continuar...";
    cin.get();
    cout << "\n\n";

    while (opcion == 's' || opcion == 'S') {
        cout << "Ingrese su nickname: ";
        cin >> nick;
        cout << "Ingrese su contrasena: ";
        cin >> pass;

        usuario u;
        usuario* encontrado = u.buscarUsu(nick, pass);

        if (encontrado != NULL) {
            cout << "\nBienvenido " << (*encontrado).getnickname() << endl;
            cout << "Tipo de cuenta: " << (*encontrado).getTipo() << endl;

            // Si el usuario es PREMIUM
            if (strcmp((*encontrado).getTipo(), "premium") == 0 ||
                strcmp((*encontrado).getTipo(), "Premium") == 0) {

                premium p((*encontrado).getnickname(), pass, (*encontrado).getTipo());
                cout << "\nEres usuario PREMIUM.\n";
                p.mostrarFechasuscrip();

                int opcPremium = 0;
                while (opcPremium != 6) {
                    cout << "\n===== MENU PREMIUM =====\n";
                    cout << "1. Reproducir canciones\n";
                    cout << "2. Reproducir favoritas\n";
                    cout << "3. Agregar a favoritos\n";
                    cout << "4. Eliminar de favoritos\n";
                    cout << "5. Ver albumes\n";
                    cout << "6. Cerrar sesion\n";
                    cout << "Seleccione una opcion: ";
                    cin >> opcPremium;

                    if (opcPremium == 1) {
                        p.ReproducirCan(false);
                    }
                    else if (opcPremium == 2) {
                        p.ReproducirFavoritos(false);
                    }
                    else if (opcPremium == 3) {
                        int idFav;
                        cout << "Ingrese ID de cancion a agregar: ";
                        cin >> idFav;
                        p.AgregarFavoritos(idFav);
                    }
                    else if (opcPremium == 4) {
                        int idEliminar;
                        cout << "Ingrese ID de cancion a eliminar: ";
                        cin >> idEliminar;
                        p.EliminarFavoritos(idEliminar);
                    }
                    else if (opcPremium == 5) {
                        ifstream archivoAlbum("album.txt");
                        if (!archivoAlbum) {
                            cout << "No se pudo abrir el archivo de albumes.\n";
                        } else {
                            album a;
                            cout << "\n=== LISTA DE ALBUMES ===\n";
                            while (!archivoAlbum.eof()) {
                                a.cargarDesdeArchivo(archivoAlbum);
                                a.mostrarInfo();
                            }
                            archivoAlbum.close();
                        }
                    }
                    else if (opcPremium == 6) {
                        cout << "Cerrando sesion Premium...\n";
                    }
                    else {
                        cout << "Opcion invalida.\n";
                    }
                }
            }

            // Si el usuario es ESTANDAR
            else if (strcmp((*encontrado).getTipo(), "estandar") == 0 ||
                     strcmp((*encontrado).getTipo(), "Estandar") == 0) {

                estandar e((*encontrado).getnickname(), pass, (*encontrado).getTipo());
                cout << "\nEres usuario ESTANDAR.\n";

                int opcEstandar = 0;
                while (opcEstandar != 5) {
                    cout << "\n===== MENU ESTANDAR =====\n";
                    cout << "1. Reproducir canciones\n";
                    cout << "2. Mostrar publicidad\n";
                    cout << "3. Ver artistas\n";
                    cout << "4. Ver albumes\n";
                    cout << "5. Cerrar sesion\n";
                    cout << "Seleccione una opcion: ";
                    cin >> opcEstandar;

                    if (opcEstandar == 1) {
                        e.repoducirCanciones();
                    }
                    else if (opcEstandar == 2) {
                        e.mostrarPublicidad();
                    }
                    else if (opcEstandar == 3) {
                        ifstream archivoArt("artistas.txt");
                        if (!archivoArt) {
                            cout << "No se pudo abrir el archivo de artistas.\n";
                        } else {
                            artista art;
                            cout << "\n=== LISTA DE ARTISTAS ===\n";
                            while (!archivoArt.eof()) {
                                art.cargarDesdeArchivo(archivoArt);
                                art.mostrarInfo();
                            }
                            archivoArt.close();
                        }
                    }
                    else if (opcEstandar == 4) {
                        ifstream archivoAlbum("album.txt");
                        if (!archivoAlbum) {
                            cout << "No se pudo abrir el archivo de albumes.\n";
                        } else {
                            album a;
                            cout << "\n=== LISTA DE ALBUMES ===\n";
                            while (!archivoAlbum.eof()) {
                                a.cargarDesdeArchivo(archivoAlbum);
                                a.mostrarInfo();
                            }
                            archivoAlbum.close();
                        }
                    }
                    else if (opcEstandar == 5) {
                        cout << "Cerrando sesion Estandar...\n";
                    }
                    else {
                        cout << "Opcion invalida.\n";
                    }
                }
            }

            cout << "\n¿Desea cerrar el programa o iniciar otra sesion? (s/n): ";
            cin >> opcion;
        }
        else {
            cout << "\nUsuario o contrasena incorrectos.\n";
            cout << "¿Desea intentar nuevamente? (s/n): ";
            cin >> opcion;
        }
    }

    cout << "\nGracias por usar UDEATUNES.\n";
    cout << "Fin del programa.\n";
    return 0;
}
