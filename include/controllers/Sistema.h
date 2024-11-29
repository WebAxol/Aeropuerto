//
// Created by gabriel on 27/11/24.
//

#ifndef SISTEMA_H
#define SISTEMA_H

#include <fstream>
#include <map>

#include "../models/Vuelo.h"
#include "../models/Avion.h"
#include "../models/Usuario.h"

#include "ManejadorAvion.h"
#include "ManejadorVuelo.h"
#include "ManejadorUsuario.h"


using namespace std;

class Sistema {
    private:
        int proximoIdVuelo;
        map<int, Vuelo*> vuelos;
        ManejadorAvion*   manejadorAvion;
        ManejadorUsuario* manejadorUsuario;
        ManejadorVuelo*   manejadorVuelo;

    public:
        Sistema() {

            manejadorUsuario = new ManejadorUsuario();
            manejadorAvion   = new ManejadorAvion();

            map<int, Avion*> aviones = manejadorAvion->getAviones();

            manejadorVuelo   = new ManejadorVuelo(aviones);
        };


        int registrarUsuario(string nombre, string clave) {
            return this->manejadorUsuario->registrarUsuario(nombre, clave);
        }

        int iniciarSesion(string nombre, string clave) {
            return this->manejadorUsuario->iniciarSesion(nombre, clave);
        }

        void consultarVuelos() {
            this->manejadorVuelo->consultarVuelos();
        }

        void cancelarReservacion(int idUsuario, int idReservacion);
};



#endif //SISTEMA_H
