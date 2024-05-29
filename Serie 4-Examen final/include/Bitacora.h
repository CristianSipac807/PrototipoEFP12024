//Cristian David Sipac Ispache
//9959-23-1567
#ifndef BITACORA_H
#define BITACORA_H
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstring>
#include "usuarios.h"
using namespace std;

// Estructura registro bitacora
struct RegistroBitacora {

    char accion[80];
    char aplicacion[80];
    char nombre[80];
    char fechaHora[80];
};

// Clase bitacora
class Bitacora {
public:
    // Función para registrar una entrada en la bitácora
    void ingresoBitacora(const string& usuario, const string& codigoPrograma, const string& tipoIngreso);

    // Función para mostrar la bitácora
    void mostrarBitacora();

};

#endif // BITACORA_H
