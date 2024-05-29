//Cristian David Sipac Ispache
//9959-23-1567
#ifndef CLIENTES_H
#define CLIENTES_H
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<string>
//#include<Entrenador.h>
using namespace std;
 struct EntrenadorC {

    char id[20];
    char nombre[50];
    char nombre2[50];
    char Apellido[50];
    char Apellido2[50];
    char fechadenacimiento[50];

};
class Entrenador{
    private:
    string id, nombre, nombre2, telefono, Apellido, Apellido2, fechadenacimiento;

    public:
        Entrenador() {}
        Entrenador(string id,string nombre,string nombre2, string Apellido,string Apellido2,string fechadenacimiento);
        string setid(string id);
        string getid();
        string setnombre(string nombre);
        string getnombre();
        string setnombre2(string nombre2);
        string getnombre2();
        string setApellido(string Apellido);
        string getApellido();
        string setApellido2(string Apellido2);
        string getApellido2();
        string setFechanaci(string fechadenacimiento);
        string getFechanaci();
        string settel(string telefono);
        string gettel();




    //Funciones
    void menu();
    void insertar();
    void desplegar();
    void modificar();
    void buscar();
    void borrar();



};


#endif // ENTRENADOR_H
