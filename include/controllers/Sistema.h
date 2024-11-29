//
// Created by gabriel on 27/11/24.
//

#ifndef SISTEMA_H
#define SISTEMA_H

#include <fstream>

#include "../models/Vuelo.h"
#include "../models/Avion.h"
#include "../models/Usuario.h"

#include "ManejadorAvion.h"
#include "ManejadorVuelo.h"
#include "ManejadorUsuario.h"
#include "ManejadorReserva.h"

using namespace std;

class Sistema {
    private:
        int proximoIdVuelo;
        map<int, Vuelo*> vuelos;
        ManejadorAvion*   manejadorAvion;
        ManejadorUsuario* manejadorUsuario;
        ManejadorVuelo*   manejadorVuelo;
        ManejadorReserva* manejadorReserva;

    public:
        Sistema() {

            manejadorUsuario = new ManejadorUsuario();
            manejadorAvion   = new ManejadorAvion();
            manejadorVuelo   = new ManejadorVuelo();
            manejadorReserva = new ManejadorReserva();
        };


        void registrarUsuario(string nombre, string clave) {
            this->manejadorUsuario->registrarUsuario(nombre, clave);

            cout << "Usuario creado! A continuación debe iniciar sesión..." << endl << endl;
        }

        Usuario* iniciarSesion(string nombre, string clave) {
            return this->manejadorUsuario->iniciarSesion(nombre, clave);
        }

        void consultarVuelos() {
            Vuelo** vuelos = this->manejadorVuelo->getVuelos();

            for (int i = 1; i < 100; i++) {

                if (vuelos[i] == nullptr) continue;

                Vuelo* vuelo = vuelos[i];

                int idAvion = vuelo->getIdAvion();

                // Nota: la obtencion de datos es ineficiente, pero funcional

                Avion* avion = this->manejadorAvion->getAvionById(idAvion);

                bool disponible = vuelo->getPasajeros() < avion->getCapacidad();

                // Filtrar vuelos según disponibilidad

                if (!disponible) continue;

                cout << "Identificador : " << vuelo->getId() << endl;
                cout << "Origen : "   << vuelo->getOrigen() << endl;
                cout << "Destino : " << vuelo->getDestino() << endl;
                cout << "Precio : $" << vuelo->getPrecio() <<  endl;
                cout << "Ditancia :" << vuelo->getKilometros() << "km" << endl;
                cout << endl;
            }
        }

        void mostrarReservas(int idUsuario){
            this->manejadorReserva->mostrarReservasUsuario(idUsuario);
        }

        bool reservarVuelo(int idUsuario, int idVuelo) {

            Vuelo* vuelo = this->manejadorVuelo->getVuelo(idVuelo);

            if(vuelo == nullptr) return false;

            Avion* avion = this->manejadorAvion->getAvionById(vuelo->getIdAvion());

            int capacidad = avion->getCapacidad();

            if (capacidad <= vuelo->getPasajeros()) return false;

            int asiento = this->manejadorReserva->buscarAsientoDisponible(idVuelo, capacidad);

            cout << "Asiento : " << asiento << endl;

            this->manejadorReserva->crearReservacion(idUsuario, idVuelo, asiento);

            float kilometros = vuelo->getKilometros();

            this->manejadorUsuario->sumarKilometros(idUsuario, kilometros);

            return true;
        }
        bool cancelarReservacion(int idUsuario, int idReservacion) {

            Reservacion* reserva = this->manejadorReserva->buscarPorId(idReservacion);

            if (reserva == nullptr || reserva->getIdUsuario() != idUsuario) return false;

            this->manejadorReserva->eliminarReserva(idReservacion);

            return true;
        }
        void consultarKilometros(int idUsuario) {
            float kilometros = this->manejadorUsuario->consultarKilometrosPorId(idUsuario);
            cout << "Usted ha acumulado un total de " << kilometros << " kilometros!" << endl << endl;
        }
};



#endif //SISTEMA_H
