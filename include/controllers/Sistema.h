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

using namespace std;

class Sistema {
    private:
        const int proximoIdUsuario = 1;
        const int proximoIdVuelo = 1;
        map<int, Vuelo*> vuelos;
        map<int, Usuario*> usuarios;

        // Los datos se cargan de sus respectivos archivos .csv, y se modelan los objetos según sus clases
        // TODO: Separar logica relacionada con carga de datos de las funcionalidades principales

        map<int, Avion*> cargarAviones() {

            map<int, Avion*> objAviones;

            string linea;

            ifstream aviones("./data/aviones.csv");

            if(!aviones.is_open()) {
                cerr << "Error al abrir el archivo aviones.csv" << endl;
            }

            while (getline( aviones, linea)) {
                stringstream ss(linea);

                int id;
                ss >> id;

                string aerolinea;
                ss >> aerolinea;

                string modelo;
                ss >> modelo;

                objAviones[id] = new Avion(id, aerolinea, modelo);
            }
             aviones.close();

             return objAviones;
        };

        void cargarVuelos() {

             // Cada instancia de "Vuelo" requiere de un a instancia de "Avion"
             // Primero se instancian los objetos de tipo Avion, los cuales se agregados posteriormente
             map<int, Avion*> aviones = cargarAviones();

             string linea;

             ifstream vuelos("./data/vuelos.csv");

             if(!vuelos.is_open()) {
                 cerr << "Error al abrir el archivo vuelos.csv" << endl;
             }

             while (getline( vuelos, linea)) {
                 stringstream ss(linea);

                 int id;
                 ss >> id;

                 int idAvion;
                 ss >> idAvion;

                 string origen;
                 ss >> origen;

                 string destino;
                 ss >> destino;

                 // Se relaciona al vuelo con su avion correspondiente
                 // Varios vuelos pueden tener un mismo avion asociado
                 Avion* avion = aviones[idAvion];

                 if (avion == NULL) {
                     cerr << "Atencion: el avion con identificacion " << idAvion << " no existe" << endl;
                 }
                 else this->vuelos[id] = new Vuelo(origen,destino,avion);
             }

             vuelos.close();
        };



        void cargarUsuarios() {

            string linea;

            ifstream usuarios("./data/usuarios.csv");

            if(!usuarios.is_open()) {
                cerr << "Error al abrir el archivo usuarios.csv" << endl;
            }

            while (getline( usuarios, linea)) {
                stringstream ss(linea);

                int id;
                ss >> id;

                string nombre;
                ss >> nombre;

                string clave;
                ss >> clave;

                this->usuarios[id] = new Usuario(nombre, clave);
            }

            usuarios.close();
        };

    void cargarReservaciones() {

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
            Vuelo* vuelo     = this->vuelos[idVuelo];
            // El objeto reserva compone a un usuario
            Usuario* usuario = this->usuarios[id];

            if (vuelo == NULL || usuario == NULL) {
                cerr << "Atención: la reservación número" << id << " es inválida" << endl;
                return;
            }

            Reservacion* reservacion = new Reservacion(vuelo, asiento);
            usuario->agregarReservacion(id, reservacion);
        }

        reservas.close();
    };

    public:
        Sistema() {
            this->cargarVuelos();
            this->cargarUsuarios();
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
