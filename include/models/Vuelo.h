//
// Created by gabriel on 27/11/24.
//

#ifndef VUELO_H
#define VUELO_H

#include <utility>

using namespace std;


class Vuelo {
    private:
        const int id;
        const int idAvion;
        const string origen;
        const string destino;
        const float precio;
        float kilometros;
        int pasajeros;
    public:
        Vuelo(
            int id,
            int idAvion,
            string origen,
            string destino,
            float precio,
            float kilometros,
            int pasajeros
        ) :
            id(id),
            idAvion(idAvion),
            origen(move(origen)),
            destino(move(destino)),
            precio(precio),
            kilometros(kilometros),
            pasajeros(pasajeros)
        {};
        int getId() const {
            return id;
        };
        int getIdAvion() const {
            return idAvion;
        };
        string getOrigen() const {
            return origen;
        };

        string getDestino() const {
            return destino;
        };

        float getPrecio() const {
            return precio;
        }
        int getPasajeros() const {
            return pasajeros;
        }
        float getKilometros() {
            return kilometros;
        }
};



#endif //VUELO_H
