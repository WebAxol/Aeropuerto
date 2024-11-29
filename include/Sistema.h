//
// Created by gabriel on 27/11/24.
//

#ifndef SISTEMA_H
#define SISTEMA_H

#include <fstream>
#include <sstream>
#include "Vuelo.h"
#include "Usuario.h"
#include <map>
#include <vector>

using namespace std;

class Sistema {
    private:
        const int proximoIdUsuario = 1;
        const int proximoIdVuelo = 1;
        map<int, Vuelo> vuelos;
        map<int, Usuario> usuario;
    public:
        Sistema() = default;

        void cargarUsuarios() {

            vector<string> lineas;

            string linea;

            ifstream usuarios("./data/usuarios.csv");

            if(!usuarios.is_open()) {
                cerr << "Error al abrir el archivo" << endl;
            }

            while (getline( usuarios, linea)) {
                cout << linea << endl;
                stringstream ss(linea);

                int id;
                ss >> id;

                string nombre;
                ss >> nombre;

                string clave;
                ss >> clave;

                Usuario usuario(id, nombre, clave);
            }

            usuarios.close();
        };

        void consultarVuelos();
        void reservar(int idUsuario, int idVuelo);
        void cancelarReservacion(int idUsuario, int idReservacion);
};



#endif //SISTEMA_H
