//
// Created by gabriel on 27/11/24.
//

#ifndef RESERVACION_H
#define RESERVACION_H

#include "Vuelo.h"

using namespace std;

class Reservacion {
    private:
        const int id;
        const int idUsuario;
        const int idVuelo;
        const int numeroAsiento;
    public:
        Reservacion(
            int id,
            int idUsuario,
            int idVuelo,
            int numeroAsiento
        ) :
            id(id),
            idUsuario(idUsuario),
            idVuelo(idVuelo),
            numeroAsiento(numeroAsiento)
        {};
        int getId() const {
          return id;
        };
        int getIdUsuario() const {
          return idUsuario;
        };
        int getIdVuelo() const {
          return idVuelo;
        };
        int getNumeroAsiento() const {
          return numeroAsiento;
        };
};



#endif //RESERVACION_H
