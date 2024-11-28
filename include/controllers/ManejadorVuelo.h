//
// Created by gabriel on 27/11/24.
//

#ifndef MANEJADORVUELO_H
#define MANEJADORVUELO_H
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "../models/Vuelo.h"

class ManejadorVuelo{
  public:

     static map<int, Vuelo*> cargarVuelos( map<int, Avion*> aviones ) {

      string linea;

       map<int, Vuelo*> objVuelos;

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
        else objVuelos[id] = new Vuelo(origen,destino,avion);
      }

      vuelos.close();

      return objVuelos;
   };
};

#endif //MANEJADORVUELO_H
