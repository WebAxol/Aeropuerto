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

  private:
    Vuelo* vuelos[100];
    int proximoIdVuelo = 0;

  void cargarVuelos() {

    string linea;

    ifstream vuelos("./data/vuelos.csv");

    if(!vuelos.is_open()) {
      cerr << "Error al abrir el archivo vuelos.csv" << endl;
    }

    while (getline( vuelos, linea)) {
      stringstream ss(linea);

      int id, idAvion, pasajeros;
      ss >> id >> idAvion;

      string origen;
      ss >> origen;

      string destino;
      ss >> destino;

      float precio, kilometros;
      ss >> precio >> kilometros;
      ss >> pasajeros;

      this->vuelos[id] = new Vuelo(
        id,
        idAvion,
        origen,
        destino,
        precio,
        kilometros,
        pasajeros
      );

      proximoIdVuelo = max(proximoIdVuelo, id + 1);
    }

    vuelos.close();
  };

  public:

    ManejadorVuelo() {
      this->cargarVuelos();
    }


    Vuelo** getVuelos() {
      return vuelos;
    }

    Vuelo* getVuelo(int id) {
      return this->vuelos[id];
    }
};

#endif //MANEJADORVUELO_H
