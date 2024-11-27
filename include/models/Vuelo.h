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
        const Avion* avion;
    public:
        Vuelo(string origen, string destino, Avion* avion) :
            origen(origen), destino(destino), avion(avion)
        {};

        string getOrigen() const {
            return origen;
        };

        string getDestino() const {
            return destino;
        };

        string getAerolinea() const {
            return avion->getAerolinea();
        };
};



#endif //VUELO_H
