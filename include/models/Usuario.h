//
// Created by gabriel on 27/11/24.
//

#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <utility>

using namespace std;

class Usuario {
    private:
        const int id;
        string nombre;
        string claveAcceso;
        int    reservas = 0;
        float  kilometros = 0;
    public:

        Usuario(
            int id,
            string nombre,
            string  claveAcceso
        ) :
            id(id),
            nombre(move(nombre)),
            claveAcceso(move(claveAcceso))
        {};

        string getNombre() {
            return nombre;
        };

        string getClave() {
            return claveAcceso;
        };
        int getId() const {
            return id;
        }
        float getKilometros() {
            return kilometros;
        }

        void sumarKilometros(float kilometros) {
            this->kilometros += kilometros;
        }
};



#endif //USUARIO_H
