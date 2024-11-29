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
    map<int, Vuelo*> vuelos;


  void cargarVuelos( map<int, Avion*> aviones ) {

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

      float precio;
      ss >> precio;

      ss >> pasajeros;

      // Se relaciona al vuelo con su avion correspondiente
      // Varios vuelos pueden tener un mismo avion asociado
      Avion* avion = aviones[idAvion];

      if (avion == NULL) {
        cerr << "Atencion: el avion con identificacion " << idAvion << " no existe" << endl;
      }
      else this->vuelos[id] = new Vuelo(origen,destino,avion, precio, pasajeros);
    }

    vuelos.close();
  };

  public:

    ManejadorVuelo( map<int, Avion*> aviones) {
      this->cargarVuelos(aviones);
    }

    void consultarVuelos() {

      // Imprime un listado de los vuelos con sus atributos

      cout << "Vuelos" << endl << endl;

      for (auto it = vuelos.begin(); it != vuelos.end(); it++) {

        Vuelo* vuelo = it->second;

        // Filtrar vuelos por disponibilidad

        if (!vuelo->disponible()) continue;

        cout << "Identificador : " << it->first << endl;
        cout << "Aerolinea : " << vuelo->getAerolinea() << endl;
        cout << "Origen : "   << vuelo->getOrigen() << endl;
        cout << "Destino : " << vuelo->getDestino() << endl;
        cout << "Precio : " << vuelo->getPrecio() << endl;

        cout << endl;

      }
    };
};

#endif //MANEJADORVUELO_H
