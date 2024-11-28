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
    public:
    static void cargarReservaciones(map<int,Usuario*> usuarios, map<int,Vuelo*> vuelos) {

        string linea;

        ifstream reservas("./data/reservas.csv");

        if(!reservas.is_open()) {
            cerr << "Error al abrir el archivo reservas.csv" << endl;
        }

        while (getline( reservas, linea)) {
            stringstream ss(linea);

            int id;
            ss >> id;

            int idVuelo;
            ss >> idVuelo;

            int idUsuario;
            ss >> idUsuario;

            int asiento;
            ss >> asiento;

            // El vuelo se agrega al objeto reserva
            Vuelo* vuelo = vuelos[idVuelo];
            // El objeto reserva compone a un usuario
            Usuario* usuario = usuarios[id];

            if (vuelo == NULL || usuario == NULL) {
                cerr << "Atención: la reservación número" << id << " es inválida" << endl;
                return;
            }

            Reservacion* reservacion = new Reservacion(vuelo, asiento);
            usuario->agregarReservacion(id, reservacion);
        }

        reservas.close();
    };
};



#endif //MANEJADORRESERVA_H
