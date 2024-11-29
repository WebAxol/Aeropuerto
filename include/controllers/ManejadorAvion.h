//
// Created by gabriel on 27/11/24.
//

#ifndef MANEJADORAVION_H
#define MANEJADORAVION_H

#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "../models/Avion.h"

using namespace std;

class ManejadorAvion {
    private:
        map<int, Avion*> aviones;

    void cargarAviones() {

        string linea;

        // Advertencia: la resolución de rutas difiere según el sistema y la configuración del mismo

        ifstream aviones("./data/aviones.csv");

        if(!aviones.is_open()) {
            cerr << "Error al abrir el archivo aviones.csv" << endl;
        }

        while (getline( aviones, linea)) {
            stringstream ss(linea);

            int id, capacidad;
            ss >> id;

            string aerolinea, modelo;
            ss >> aerolinea >> modelo;
            ss >> capacidad;

            this->aviones[id] = new Avion(id, aerolinea, modelo, capacidad);
        }
        aviones.close();
    };

    public:
        ManejadorAvion() {
            this->cargarAviones();
        };

    map<int, Avion*> getAviones() {
        return this->aviones;
    }


};


#endif //MANEJADORAVION_H
