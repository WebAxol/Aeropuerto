//
// Created by gabriel on 27/11/24.
//

#ifndef RESERVACION_H
#define RESERVACION_H

#include "Vuelo.h"

using namespace std;

class Reservacion {
    private:
        const Vuelo* vuelo;
        const int asiento;
    public:
        Reservacion(const Vuelo* vuelo, int asiento) :
            vuelo(vuelo), asiento(asiento)
        {};

};



#endif //RESERVACION_H
