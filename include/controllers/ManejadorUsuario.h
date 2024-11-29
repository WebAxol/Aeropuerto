//
// Created by gabriel on 27/11/24.
//

#ifndef MANEJADORUSUARIO_H
#define MANEJADORUSUARIO_H

#include <fstream>
#include <sstream>
#include <iostream>
#include "../models/Usuario.h"

using namespace std;

class ManejadorUsuario {

    private:
        int proximoIdUsuario = 0;
        Usuario* usuarios[100];

    void guardarUsuarios(){

        ofstream usuarios("./data/usuarios.csv");

        for (auto usuario : this->usuarios) {

            if (usuario == nullptr) continue;

            usuarios << usuario->getId() << " ";
            usuarios << usuario->getNombre() << " ";
            usuarios << usuario->getClave();
            usuarios << "\n";
        }

        usuarios.close();
    };

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

            this->usuarios[id] = new Usuario(
                id,
                nombre,
                clave
            );
            proximoIdUsuario = max(proximoIdUsuario, id + 1);
        }

        usuarios.close();
    };

    public:

        ManejadorUsuario() {
            this->cargarUsuarios();
        };

        Usuario* buscarUsuarioPorId(int id) {
            return this->usuarios[id];
        };

        int buscarIdPorNombre(string nombre) {

            // Busca el ID del usuario cuyo nombre sea igual al nombre dado

            for (auto usuario : usuarios) {
                if (usuario == nullptr) continue;

                if(usuario->getNombre() == nombre) return usuario->getId();
            }

            return -1;
        };

        Usuario* iniciarSesion(string nombre, string clave) {

            // Primero verifica que exista un nombre con tal nombre
            int idUsuario = this->buscarIdPorNombre(nombre);

            if(idUsuario == -1){
                cout << "No se encontra el usuario " << nombre << endl;
                return nullptr;
            }
            Usuario* usuario = usuarios[idUsuario];

            // Luego comprueba que la clave corresponda a la clave de acceso para dicho usuario

            if(usuario->getClave() != clave){
                cout << "La clave es incorrecta" << endl;
                return nullptr;
            }
            return usuario;
        };

        int registrarUsuario(string nombre, string clave) {

            bool existe = this->buscarIdPorNombre(nombre) > 0;


            if(existe){
                cout << "El usuario ya existe, por favor elija otro nombre" << endl;
                return -1;
            }

            int idUsuario = this->proximoIdUsuario;

            Usuario* nuevoUsuario = new Usuario(
                idUsuario,
                nombre,
                clave
            );

            // TODO: Arreglar metodo guardartUsuarios();
            // this->guardarUsuarios();

            this->usuarios[idUsuario] = nuevoUsuario;

            proximoIdUsuario++;


            return idUsuario;
        };

        void sumarKilometros(int idUsuario, float kilometros) {
            this->usuarios[idUsuario]->sumarKilometros(kilometros);
        }

        float consultarKilometrosPorId(int id) {
            return this->usuarios[id]->getKilometros();
        }
};



#endif //MANEJADORUSUARIO_H
