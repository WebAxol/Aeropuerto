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
    public:
        Avion(int id, string aerolinea, string modelo) :
            id(id), aerolinea(aerolinea), modelo(modelo)
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
};



#endif //AVION_H
