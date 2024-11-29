//
// Created by gabriel on 27/11/24.
//

#ifndef AVION_H
#define AVION_H

using namespace std;

class Avion {

    private:
        const int id;
        const string aerolinea;
        const string modelo;
        const int capacidad;
    public:
        Avion(
            const int id,
            string aerolinea,
            string modelo,
            int capacidad
        ) :
            id(id),
            aerolinea(move(aerolinea)),
            modelo(move(modelo)),
            capacidad(capacidad)
        {};

        int getId() const {
            return id;
        };

        string getAerolinea() const {
            return aerolinea;
        };

        string getModelo() const {
            return modelo;
        };

        int getCapacidad() const {
            return capacidad;
        }
};



#endif //AVION_H
