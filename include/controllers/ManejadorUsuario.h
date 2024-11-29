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

using namespace std;

class ManejadorUsuario {

    private:
        int proximoIdUsuario;
        map<int, Usuario*> usuarios;

    void guardarUsuario(){

        ofstream usuarios("./data/usuarios.csv");

        for (auto it = this->usuarios.begin(); it != this->usuarios.end(); it++) {

            Usuario* usuario = it->second;

            usuarios << it->first << " ";
            usuarios << usuario->getNombre() << " ";
            usuarios << usuario->getClave();
            usuarios << "\n";
        }

        usuarios.close();
    }

    void cargarUsuarios() {

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

            this->usuarios[id] = new Usuario(nombre, clave);
        }

        usuarios.close();
    };

    public:

        ManejadorUsuario() {
            this->cargarUsuarios();
            this->proximoIdUsuario = this->usuarios.size() + 1;
        }

        int buscarUsuario(string nombre) {

            // Busca el ID del usuario cuyo nombre sea igual al nombre dado

            for (auto it = this->usuarios.begin(); it != this->usuarios.end(); it++) {
                if(it->second->getNombre() == nombre) return it->first;
            }

            return -1;
        }

        int iniciarSesion(string nombre, string clave) {

            // Primero verifica que exista un nombre con tal nombre
            int idUsuario = this->buscarUsuario(nombre);

            if(idUsuario == -1){
                cout << "No se encontra el usuario " << nombre << endl;
                return -1;
            }
            Usuario* usuario = usuarios[idUsuario];

            // Luego comprueba que la clave corresponda a la clave de acceso para dicho usuario

            if(usuario->getClave() != clave){
                cout << "La clave es incorrecta" << endl;
                return -1;
            }

            return idUsuario;
        }

        int registrarUsuario(string nombre, string clave) {

            bool existe = this->buscarUsuario(nombre) > 0;


            if(existe){
                cout << "El usuario ya existe, por favor elija otro nombre" << endl;
                return -1;
            }

            Usuario* nuevoUsuario = new Usuario(nombre, clave);

            int idUsuario = ++this->proximoIdUsuario;

            this->usuarios[idUsuario] = nuevoUsuario;

            this->guardarUsuario();

            return idUsuario;
        }
};



#endif //MANEJADORUSUARIO_H
