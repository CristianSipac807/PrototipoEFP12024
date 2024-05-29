#include "usuarios.h"
//Cristian David Sipac Ispache
//9959-23-1567
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Login.h"
#include "Bitacora.h"

using namespace std;

usuarios::usuarios(string nombre, string contra){
this->nombre = nombre;
this->contra = contra;
}

string usuarios::setnombre(string nombre)
{
    this->nombre = nombre;
    return nombre;
}

string usuarios::getnombre()
{
    return nombre;
}

string usuarios::setcontra(string contra)
{
    this->contra = contra;
    return contra;
}

string usuarios::getcontra()
{
    return contra;
}

void usuarios::menu()
{
    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2100", "GUA"); // Parámetros

    int opc;
    do
    {
        system("cls");
        cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|        Gestion de Usuarios de Alumnos         |"<<endl;
		cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|            1. Agregar Usuario                 |"<<endl;
		cout<<"|            2. Mostrar Usuario                 |"<<endl;
		cout<<"|            3. Modificar Usuario               |"<<endl;
		cout<<"|            4. Borrar Usuario                  |"<<endl;
		cout<<"|            5. Regresar al menu                |"<<endl;
		cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|         Ingrese su opcion [1/2/3/4/5]         |"<<endl;
		cout<<"+-----------------------------------------------+"<<endl;
        cin >> opc;

        switch(opc)
        {
        case 1:
            pideDatos();
            break;

        case 2:
            muestraDatos();
            break;

        case 3:
            //Funcion editar datos
            editaDatos();
            break;

        //Opcion 4
        case 4:
            //Funcion borrar datos
            borraDatos();
            break;

        //Opcion 5
        case 5:
            break;
        }
    } while (opc!=5);

}

//Funcion pedir datos
void usuarios::pideDatos()
{
    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2102", "USPD"); // Parámetros

    system("cls");
    cout<<"+---------------------------------------------------------+"<< endl;
    cout<<"|        Agregar detalles del Usuario de Alumnos          |"<< endl;
    cout<<"+---------------------------------------------------------+"<< endl;

    Usuarios usuario;
    cout<<"       -> Ingrese un nombre: ";
    cin.ignore();
    cin.getline(usuario.nombre, 80);
    cout<<"       -> Ingrese una contrasena: ";
    cin.getline(usuario.contra, 80);

    ofstream archivo("Usuario.dat", ios::binary | ios::app);

    archivo.write(reinterpret_cast<const char*>(&usuario), sizeof(usuario));

    archivo.close();
}

void usuarios::muestraDatos()
{
    //Implementacion de la bitacora
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2102", "USMD"); // Parámetros

    system("cls");
    cout<<"+---------------------------------------------------------+"<< endl;
    cout<<"|        Mostrar detalles del Usuario de Alumnos          |"<< endl;
    cout<<"+---------------------------------------------------------+"<< endl;

    ifstream archivo("Usuario.dat", ios::binary | ios::in);
    if(!archivo)
    {
        cout << "No hay informacion registrada";
        return;
    }
        Usuarios usuario;

        while (archivo.read(reinterpret_cast<char*>(&usuario), sizeof(Usuarios)))
        {
            cout<<"       -> Nombre de usuario: "<< usuario.nombre << endl;
            cout<<"       -> Contrasena usuario: "<<usuario.contra << endl;
            cout << "+---------------------------------------------------------+" << endl;
        }
            //Cierra el archivo
            archivo.close();


    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}
//Funcion editar datos
void usuarios::editaDatos()
 {
    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2103", "USED"); // Parámetros

    //Limpiando pantalla
    system("cls");
    fstream archivo;
    string nom;
    bool encontrado = false;

    cout<<"+---------------------------------------------------------+"<< endl;
    cout<<"|         Editar detalles del Usuario de Alumnos          |"<< endl;
    cout<<"+---------------------------------------------------------+"<< endl;

    archivo.open("Usuario.dat",ios::binary | ios::in | ios::out);
    if(!archivo){

        cout << "No hay informacion registrada";
        return;
    }
        cout << "Ingrese el nombre del usuario que quiera modificar: ";
        cin >> nom;

        Usuarios usuario;

        while (archivo.read(reinterpret_cast<char*>(&usuario), sizeof(Usuarios))) {
        if (usuario.nombre == nom) {
            encontrado = true;

            cout << "Ingrese el nuevo nombre del usuario: ";
            cin >> usuario.nombre;
            cout << "Ingrese la nueva contraseña del usuario: ";
            cin >> usuario.contra;


            archivo.seekp(-static_cast<int>(sizeof(Usuarios)), ios::cur);

            archivo.write(reinterpret_cast<char*>(&usuario), sizeof(Usuarios));
            break;
        }
    }

    archivo.close(); // Cierra el archivo

    //si no lo encuentra mostrara el siguiente mensaje
    if (!encontrado) {
        cout << "No se encontró un usuario con el nombre proporcionado." << endl;
    }

    //Mensaje al usuario
    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}

//Funcion borrar datos
void usuarios::borraDatos()
{
    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2104", "USBD"); // Parámetros

    //Limpiando pantalla
   	system("cls");


	string nom;

	cout<<"+---------------------------------------------------------+"<< endl;
    cout<<"|       Eliminar detalles del Usuario de Alumnos          |"<< endl;
    cout<<"+---------------------------------------------------------+"<< endl;

    ifstream archivo("Usuario.dat", ios::binary);

	if(!archivo)
	{
		cout<<"Error, no se encuentra informacion...";
		return;
	}
    ofstream archivo2("Usuario2.dat", ios::binary);
	Usuarios usuario;

    cout<<"-> Ingrese el nombre de la persona que desea eliminar: ";
    cin>>nom;

    bool resta = false;

		while(archivo.read(reinterpret_cast<char*>(&usuario), sizeof(Usuarios)))
		{
			if(usuario.nombre != nom)
			{
				archivo2.write(reinterpret_cast<const char*>(&usuario), sizeof(Usuarios));
			}
			else
			{
			    resta = true;
			}

		}
        //cierra ambos archivos
		archivo.close();
		archivo2.close();

		remove("Usuario.dat");

		rename("Usuario2.dat","Usuario.dat");

		if (resta)
        {
        cout << "Usuario eliminado con exito." << endl;
        }
        else
        {
        cout << "No se a podido encontrar el nombre del Usuario" << endl;
        }
}

