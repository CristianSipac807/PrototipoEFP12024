//Cristian David Sipac Ispache
//9959-23-1567
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <unistd.h>
#include "Bitacora.h"
#include "usuarios.h"
#include "Login.h"
#include "clientes.h"
//#include "asignar_funciones.h"
//#include "peliculas.h"
//#include "Horarios.h"
using namespace std;

void menuGeneral();
void catalogos();
void reportes();
void procesos();
void seguridad();

string codigoPrograma="1";

int main()
{
    Login login;

if (login.validacion()) {
    menuGeneral();
} else {
    cout << "Intentelo nuevamente..." << endl; // Si la validación falla, muestra un mensaje de error
}

return 0; // Finaliza el programa
}

//Funcion menu general
void menuGeneral()
{
    int choice;

    do
    {
        system("cls");
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t|      SISTEMA DE GESTION     |"<< endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t 1. Catalogos" << endl;
        cout << "\t\t\t 2. Informes" << endl;
        cout << "\t\t\t 3. Usuarios" << endl;
        cout << "\t\t\t 4. Seguridad" << endl;
        cout << "\t\t\t 5. Salir del Sistema" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t|Opcion a escoger:[1/2/3/4/5]  |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opcion: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            catalogos();
            break;

        case 2:
            {
                //asignaciom_de_resultados asignacion1;
                //asignacion1.Menu();
               break;
            }
        case 3:
        {
                usuarios usuario;
                usuario.menu();
                break;
            }
        case 4:
            {
                Bitacora bitacora;
                bitacora.mostrarBitacora();
                break;
            }
        case 5:
            {
            string usuarioActual = Login::getUsuarioActual();
            Bitacora bitacora;

            bitacora.ingresoBitacora(usuarioActual, "2600", "LGO");
            exit(0);
            }

        default:
            cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
        }
    } while (choice != 5);
}


void catalogos()
{
    int choice;

    do
    {
        system("cls");
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t|        SISTEMA CATALOGOS Clientes         |" << endl;
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t 1. Clientes" << endl;
        //cout << "\t\t\t 2. Horarios" << endl;
        cout << "\t\t\t 3. Regresar" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\t | Opcion a escoger:[1/2/3/4/5/]|" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opcion: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
              Entrenador Entrenador1;
              Entrenador1.menu();
//            Equipos equipos1;
  //          equipos1.menuFUT();
            break;
        }


        case 2:
        {
//            Horarios horario1;
//            horario1.menuHorario();
            //Equipos equipos1;
            //equipos1.menuFUT();
            break;}


        case 3:{
            menuGeneral();
            //Horarios horario1;
            //horario1.menuHorario();
            break;
            }
        default:
            cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
        }
    }while (choice != 5);
}
