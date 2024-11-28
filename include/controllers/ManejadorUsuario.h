//
// Created by gabriel on 27/11/24.
//

#ifndef MANEJADORUSUARIO_H
#define MANEJADORUSUARIO_H

#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "../models/Usuario.h"

class ManejadorUsuario {
    public:

    static void guardarUsuario(map<int, Usuario*> objUsuarios){

        ofstream usuarios

    }

    static map<int, Usuario*> cargarUsuarios() {

        map<int, Usuario*> objUsuarios;

        string linea;

        ifstream usuarios("./data/usuarios.csv");

        if(!usuarios.is_open()) {
            cerr << "Error al abrir el archivo usuarios.csv" << endl;
        }

        while (getline( usuarios, linea)) {
            stringstream ss(linea);

            int id;
            ss >> id;

            string nombre;
            ss >> nombre;

            string clave;
            ss >> clave;

            objUsuarios[id] = new Usuario(nombre, clave);
        }

        usuarios.close();

        return objUsuarios;
    };
};



#endif //MANEJADORUSUARIO_H
