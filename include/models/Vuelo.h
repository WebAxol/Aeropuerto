//
// Created by gabriel on 27/11/24.
//

#ifndef VUELO_H
#define VUELO_H

#include "Avion.h"

using namespace std;


class Vuelo {
    private:
        const string origen;
        const string destino;
        const float precio;
        const Avion* avion;
        int pasajeros;
    public:
        Vuelo(string origen, string destino, Avion* avion, float precio, int pasajeros) :
            origen(origen), destino(destino), avion(avion), precio(precio), pasajeros(pasajeros)
        {};

        bool disponible() {
            return this->avion->getCapacidad() > this->pasajeros;
        }

        string getOrigen() const {
            return origen;
        };

        string getDestino() const {
            return destino;
        };

        string getAerolinea() const {
            return avion->getAerolinea();
        };

        float getPrecio() const {
            return precio;
        }

        const Avion* getAvion() const {
            return avion;
        }
};



#endif //VUELO_H
