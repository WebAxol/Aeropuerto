#include <iostream>
#include "./include/controllers/Sistema.h"
#include <fstream>
#include <variant>

using namespace std;
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {

    Sistema sys;

    bool exit = false;
    int idUsuario = -1;
    string nombre;

    cout << "Bienvenido!" << endl;

    while (!exit) {

        int opcion;

        if (idUsuario == -1) {
            cout << "No ha iniciado sesión, elija una opción" << endl;
            cout << "1 : Ya tengo cuenta" << endl;
            cout << "2 : Soy nuevo" << endl;
            cin >> opcion;

            if (opcion == 1) {

                string nombre, clave;
                cout << "Ingrese el nombre: ";
                cin >> nombre;
                cout << "Ingrese la clave: ";
                cin >> clave;

                int res = sys.iniciarSesion(nombre,clave);

                if (res == -1) continue; // Inicio de sesión fallido

                cout << "Sesión iniciada con éxito" << "\n" << endl;
                idUsuario = res;
            }

            else if (opcion == 2) {

                string nombre, clave;

                cout << "Ingrese el nombre: ";
                cin >> nombre;
                cout << "Ingrese una clave: ";
                cin >> clave;

                int res = sys.registrarUsuario(nombre,clave);

                if (res == -1) continue; // Registro fallido

                idUsuario = res;
            }
            else {
                cout << "Opción invalida, intente nuevamente" << endl;
            }
        }
        else {
            cout << "Hola usuario, que desea realizar?" << endl;
            cout << "1 : Consultar mis reservaciones"   << endl;
            cout << "2 : Consultar vuelos disponibles"  << endl;
            cout << "3 : Reservar un vuelo"             << endl;
            cout << "4 : Cancelar una reservacion"      << endl;
            cin >> opcion;

            switch (opcion) {
                case 1:
                    break;
                case 2:
                    cout<<"Lista de vuelos disponibles:"<<"\n"<<endl;
                    sys.consultarVuelos();
                    break;
            }

        }

    }

    sys.consultarVuelos();
    sys.registrarUsuario("Rutia","Gato");
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.