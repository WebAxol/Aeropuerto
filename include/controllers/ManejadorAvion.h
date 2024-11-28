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
public:
    static map<int, Avion*> cargarAviones() {

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
};


#endif //MANEJADORAVION_H
