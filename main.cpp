#include <iostream>
#include "./include/controllers/Sistema.h"
#include <fstream>
#include "./include/models/Usuario.h"

using namespace std;
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {

    Sistema sys;

    bool exit = false;
    int idUsuario = -1;
    int kilometros = -1;

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

                Usuario* res = sys.iniciarSesion(nombre,clave);

                if (res == nullptr) continue; // Inicio de sesión fallido

                cout << "Sesión iniciada con éxito" << "\n" << endl;

                idUsuario = res->getId();
                kilometros = res->getKilometros();
            }

            else if (opcion == 2) {

                string nombre, clave;

                cout << "Ingrese el nombre: ";
                cin >> nombre;
                cout << "Ingrese una clave: ";
                cin >> clave;

                sys.registrarUsuario(nombre,clave);
            }
            else {
                cout << "Opción invalida, intente nuevamente" << endl;
            }
        }
        else {

            cout << "Hola, que desea realizar?"         << endl;
            cout << "1 : Cosultar mis reservaciones"    << endl;
            cout << "2 : Consultar vuelos disponibles"  << endl;
            cout << "3 : Reservar un vuelo"             << endl;
            cout << "4 : Cancelar una reservacion"      << endl;
            cout << "5 : Consultar kilometros totales"  << endl;
            cin >> opcion;

            switch (opcion) {
                case 1:
                    cout<<"Sus reservaciones:"<<"\n"<<endl;
                sys.mostrarReservas(idUsuario);
                break;
                case 2:
                    cout<<"Lista de vuelos disponibles:"<<"\n"<<endl;
                sys.consultarVuelos();
                break;
                case 3:
                    int idVuelo;
                cout<<"Escriba el identificador del vuelo que quiere reservar:"<<endl;
                cin >> idVuelo;
                sys.reservarVuelo(idUsuario,idVuelo);
                break;
                case 4:
                    cout<<"Número de reserva que desea cancelar: ";
                int idReserva;
                cin >> idReserva;
                if (! sys.cancelarReservacion(idUsuario,idReserva)) cout << "Error al cancelar reserva"<<endl;
                else cout<<"Reserva cancelada con éxito"<<endl;
                cout<<"xx"<<endl;
                    break;
                case 5:
                    sys.consultarKilometros(idUsuario);

            }
        }

    }
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.