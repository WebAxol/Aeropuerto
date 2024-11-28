//
// Created by gabriel on 27/11/24.
//

#ifndef SISTEMA_H
#define SISTEMA_H

#include <fstream>
#include <sstream>
#include <map>

#include "../models/Vuelo.h"
#include "../models/Avion.h"
#include "../models/Usuario.h"
#include "../models/Reservacion.h"

#include "ManejadorAvion.h"
#include "ManejadorVuelo.h"
#include "ManejadorUsuario.h"


using namespace std;

class Sistema {
    private:
        const int proximoIdUsuario = 1;
        const int proximoIdVuelo = 1;
        map<int, Vuelo*> vuelos;
        map<int, Usuario*> usuarios;

        // Los datos se cargan de sus respectivos archivos .csv, y se modelan los objetos según sus clases
        // TODO: Separar logica relacionada con carga de datos de las funcionalidades principales

    public:
        Sistema() {
            map<int, Avion*> aviones = ManejadorAvion::cargarAviones();
            map<int, Vuelo*> vuelos  = ManejadorVuelo::cargarVuelos(aviones);
            this->vuelos = vuelos;
        };

        void consultarVuelos() {

            // Imprime un listado de los vuelos con sus atributos

            cout << "Vuelos" << endl << endl;

            for (auto it = vuelos.begin(); it != vuelos.end(); it++) {

                Vuelo* vuelo = it->second;

                cout << "Identificador : " << it->first << endl;
                cout << "Aerolinea : " << vuelo->getAerolinea() << endl;
                cout << "Origen : "   << vuelo->getOrigen() << endl;
                cout << "Destino : " << vuelo->getDestino() << endl;
                cout << endl;

            }
        };

        void reservar(int idUsuario, int idVuelo);
        void cancelarReservacion(int idUsuario, int idReservacion);
};



#endif //SISTEMA_H
