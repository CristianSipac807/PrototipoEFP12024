//Cristian David Sipac Ispache
//9959-23-1567
#ifndef USUARIOS_H
#define USUARIOS_H
#include <iostream>

using namespace std;

struct Usuarios {
    char nombre[80];
    char contra[80];
};


class usuarios {
private:
    string nombre, contra;
public:
    //
    usuarios(){}
    usuarios(string nombre, string contra);

    string setnombre(string nombre);
    string getnombre();

    string setcontra(string contra);
    string getcontra();


    void menu();
    void pideDatos();
    void muestraDatos();
    void editaDatos();
    void borraDatos();
};

#endif // USUARIOS_H
