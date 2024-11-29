//
// Created by gabriel on 27/11/24.
//

#ifndef MANEJADORRESERVA_H
#define MANEJADORRESERVA_H

#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "../models/Reservacion.h"
#include "../models/Usuario.h"
#include "../models/Vuelo.h"


class ManejadorReserva {
    private:
          Reservacion* reservas[100];
          int proximoIdReserva = 0;

          void cargarReservaciones() {

            string linea;

            ifstream reservas("./data/reservaciones.csv");

            if(!reservas.is_open()) {
                cerr << "Error al abrir el archivo reservas.csv" << endl;
            }

            while (getline( reservas, linea)) {
                stringstream ss(linea);

                int id, idUsuario, idVuelo, asiento;
                ss >> id >> idUsuario >> idVuelo >> asiento;

                Reservacion* reservacion = new Reservacion(
                    id,
                    idUsuario,
                    idVuelo,
                    asiento
                );

                this->reservas[id] = reservacion;
                proximoIdReserva = max(proximoIdReserva, id + 1);
            }

            reservas.close();
        };

        void guardarReservas(){

            ofstream reservas("./data/reservaciones.csv");

            for (int i = 0; i < this->proximoIdReserva; i++) {

                Reservacion* reserva = this->reservas[i];

                if (reserva == nullptr) continue;
                if (reserva->getId() <= 0 || reserva->getId() > 100) continue;

                cout << reserva->getId() << endl;

                reservas << reserva->getId() << " ";
                reservas << reserva->getIdUsuario() << " ";
                reservas << reserva->getIdVuelo() << " ";
                reservas << reserva->getNumeroAsiento() << " ";
                reservas << "\n";
            }

            reservas.close();
        };
    public:
        ManejadorReserva() {
          this->cargarReservaciones();
        }

        void crearReservacion(int idUsuario, int idVuelo, int asiento) {

          int idReserva = ++proximoIdReserva;

          Reservacion* reserva = new Reservacion(
              idReserva,
              idUsuario,
              idVuelo,
              asiento
          );

            this->reservas[idReserva] = reserva;

            // TODO : Arreglar metodo guardarReservas();
            //guardarReservas();

            cout << "Reservacion creada: " << idReserva << endl;
        };

        bool buscarAsientoDisponible(int idVuelo, int capacidad) {

            int asientos[capacidad];

              // Busca una reservación cuyo vuelo y número de asiento coincidan

              for(auto reserva : this->reservas) {

                if(reserva == nullptr) continue;

                if (reserva->getIdVuelo() == idVuelo) {
                    int ocupado = reserva->getNumeroAsiento();
                    asientos[ocupado] = 1;
                }
              }
                for (int i = 0; i < capacidad; i++) {
                    if (asientos[i] == 1) continue;
                    else return i;
                }
              // Nadia ha reservado, asi que esta disponible
              return -1;
        };

        Reservacion* buscarPorId(int id) {
            return reservas[id];
        };

        void mostrarReservasUsuario(int idUsuario){

            for( auto reserva : reservas) {
                  if(reserva == nullptr) continue;

                  // Filtrar reservas del usuario dado

                  if(reserva->getIdUsuario() != idUsuario) continue;

                  cout << "Identificador: " << reserva->getId() << endl;
                  cout << "Numero de vuelo: " << reserva->getIdVuelo() << endl;
                  cout << "Numero de asiento: " << reserva->getNumeroAsiento() << endl;
                  cout << endl;
            }
        }

        void eliminarReserva(int id) {
            reservas[id] = nullptr;

            //guardarReservas();
        }


};



#endif //MANEJADORRESERVA_H
