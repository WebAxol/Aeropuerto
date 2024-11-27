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
        const int id;
        string nombre;
        string claveAcceso;
        map<int, Reservacion> reservas;
        float  kilometros = 0;

    public:
        Usuario(int id, string nombre, string claveAcceso) :
            id(id),
            nombre(nombre),
            claveAcceso(claveAcceso)
        {};
        void reservar(Reservacion r);
        void cancelarReservacion(int idReservacion);
};



#endif //USUARIO_H
