//
// Created by gabriel on 27/11/24.
//

#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <map>

#include "Reservacion.h"

using namespace std;

class Usuario {
    private:
        string nombre;
        string claveAcceso;
        map<int, Reservacion*> reservas;
        float  kilometros = 0;

    public:
        Usuario(string nombre, string claveAcceso) :
            nombre(nombre), claveAcceso(claveAcceso)
        {};
        void agregarReservacion(int id, Reservacion* r) {
            this->reservas[id] = r;
        };
        void cancelarReservacion(int idReservacion);

        string getNombre() {
            return nombre;
        }

        string getClave() {
            return claveAcceso;
        }
};



#endif //USUARIO_H
