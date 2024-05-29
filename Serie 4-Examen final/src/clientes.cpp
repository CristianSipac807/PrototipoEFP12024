#include "clientes.h"
//Cristian David Sipac Ispache
//9959-23-1567
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<string>
#include "Bitacora.h"
#include "Login.h"


using namespace std;

Entrenador::Entrenador(string id,string nombre,string nombre2, string Apellido,string Apellido2,string fechadenacimiento)
{
    this->id = id;
    this->nombre = nombre;
   this->nombre2=nombre2;
   this->Apellido=Apellido;
   this->Apellido2=Apellido2;
   this->fechadenacimiento=fechadenacimiento;

}

string Entrenador::setid(string id)
{
    this->id = id;
    return id;
}

string Entrenador::getid()
{
    return id;
}
string Entrenador::setnombre(string nombre)
{
    this->nombre = nombre;
    return nombre;
}

string Entrenador::getnombre()
{
    return nombre;
}

string Entrenador::setnombre2(string nombre2)
{
    this->nombre2 = nombre2;
    return nombre2;
}

string Entrenador::getnombre2()
{
    return nombre2;
}

string Entrenador::setApellido(string Apellido)
{
    this->Apellido = Apellido;
    return Apellido;
}

string Entrenador::getApellido()
{
    return Apellido;
}

string Entrenador::setApellido2(string Apellido2)
{
    this->Apellido2 = Apellido2;
    return Apellido2;
}

string Entrenador::getApellido2()
{
    return Apellido2;
}

string Entrenador::setFechanaci(string fechadenacimiento)
{
    this->fechadenacimiento= fechadenacimiento;
    return fechadenacimiento;
}

string Entrenador::getFechanaci()
{
    return fechadenacimiento;
}

string Entrenador::settel(string telefono)
{
    this->telefono = telefono;
    return telefono;
}
string Entrenador::gettel()
{
    return telefono;
}


void Entrenador::menu()
{
    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();
    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;
    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2200", "ALM"); // Parámetros

    int opcion;
	char continuar;

	do
    {
		system("cls");
		cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|  BIENVENIDO AL SISTEMA DE GESTION DE ENTRENADORES   |"<<endl;
		cout<<"+-----------------------------------------------------+"<<endl;
		cout<<"|            1. Agregar Cliente                    |"<<endl;
		cout<<"|            2. Mostrar Cliente                    |"<<endl;
		cout<<"|            3. Modificar Cliente                  |"<<endl;
		cout<<"|            4. Borrar Cliente                     |"<<endl;
		cout<<"|            5. Regresar al menu                   |"<<endl;
		cout<<"+-----------------------------------------------------+"<<endl;
		cout<<"|        Ingrese su opcion [1/2/3/4/5/]              |"<<endl;
		cout<<"+-----------------------------------------------------+"<<endl;
		cin>>opcion;

		switch(opcion)
		{
			case 1:
				do
				{
					insertar();
					cout<<" -> ¿Deseas ingresar a otro cliente? (S/N): ";
					cin>>continuar;
				}while(continuar=='S' || continuar=='s');
				break;

			case 2:
                desplegar(  );
				break;

			case 3:
                modificar();
				break;

			case 4:
                borrar();
                break;

            case 5:
				break;
				//Si no elige una de las 5 opciones, mostrara el siguiente mensaje
			default:
				cout<<"ERROR, OPCION NO VALIDA, INTENTELO DE NUEVO PORFAVOR";
		}
		getch();
    }while(opcion != 5);
}

//Funcion para insertar
void Entrenador::insertar()
{

    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2201", "ALMI"); // Parámetros

    system("cls");
    cout<<"+---------------------------------------------------------+"<< endl;
    cout<<"|                Agregar detalles del Entrenador          |"<< endl;
    cout<<"+---------------------------------------------------------+"<< endl;

    srand(time(NULL));

    EntrenadorC entrenador;
    int year = 24;
    int numAleatorio = (rand() % 9998) + 1;

    string idString = "9958-" + to_string(year) + "-" + to_string(numAleatorio);

    for (int i = 0; i < idString.length(); ++i) {
        entrenador.id[i] = idString[i];
    }
    entrenador.id[idString.length()] = '\0';

    cout<<"       -> Generando carnet del cliente: " << entrenador.id<<endl;
    cin.ignore();

    cout<<"       -> Ingrese el primer nombre del cliente:  ";
    cin.getline(entrenador.nombre, 50);

    cout<<"       -> Ingrese el segundo nombre del cliente:  ";
    cin.getline(entrenador.nombre2, 50);

    cout<<"       -> Ingrese el primer Apellido del cliente:  ";
    cin.getline(entrenador.Apellido, 50);
    cout<<"       -> Ingrese el segundo Apellido del cliente:  ";
    cin.getline(entrenador.Apellido2, 50);
    cout<<"       -> Ingrese la fecha de nacimiento del cliente (DD/MM/AA): ";
    cin.getline(entrenador.fechadenacimiento, 50);
//    cout<<"       -> Ingrese el telefono del cliente: ";
//    cin.getline(entrenador.telefono, 50);

    cout<<"+---------------------------------------------------------+"<< endl;

    ofstream archivo("Entrenadores.dat", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&entrenador), sizeof(entrenador));
    archivo.close();
}

void Entrenador::desplegar()
{
    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2202", "ALMD"); // Parámetros

    system("cls");
    cout << "+---------------------------------------------------------------------------------+" << endl;
    cout << "+                            Tabla de Detalles del cliente                        +" << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;

    ifstream archivo3("Entrenadores.dat", ios::binary | ios::in);

    if (!archivo3){
        cout << "Error, no se encuentra informacion..." << endl;
        return;
    }
    EntrenadorC entrenador;

  while (archivo3.read(reinterpret_cast<char*>(&entrenador), sizeof(EntrenadorC)))
    {

        cout << "                        Mostrando -> ID del cliente: " << entrenador.id << endl;
        cout << "                        Mostrando -> 1r Nombre del cliente: " << entrenador.nombre << endl;
        cout << "                        Mostrando -> 2d0 Nombre del cliente: " << entrenador.nombre2 << endl;
        cout << "                        Mostrando -> 1r Apellido del cliente: " << entrenador.Apellido << endl;
        cout << "                        Mostrando -> 2d0 Apellido del cliente: " << entrenador.Apellido2 << endl;
        cout << "                        Mostrando -> fecha de nacimiento del Entrenador: " << entrenador.fechadenacimiento << endl;

        cout << "+---------------------------------------------------------------------------------+" << endl;
    }
    archivo3.close(); //cierra

    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}

void Entrenador::modificar()
{

    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2203", "ALMM"); // Parámetros

	system("cls");
    fstream archivo1;
    string idPersona;

    bool encontrado = false;

    cout << "+---------------------------------------------------------------------------------+" << endl;
    cout << "+                       Modificar Detalles del estudiante                         +" << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;

    archivo1.open("Entrenadores.dat", ios::binary | ios::in | ios::out);
    if (!archivo1) {
        cout << "Error, no se encuentra informacion...";
        return;
    }
    cout << "Ingrese el ID de la persona que desea modificar: ";
    cin >> idPersona;

    EntrenadorC entrenador;
    while (archivo1.read(reinterpret_cast<char*>(&entrenador), sizeof(EntrenadorC))) {
        if (entrenador.id == idPersona) {
            encontrado = true;
            cout << "Ingrese el nuevo ID del cliente: ";
            cin >> entrenador.id;
            cout << "Ingrese el nuevo 1re nombre del cliente: ";
            cin >> entrenador.nombre;
            cout << "Ingrese el nuevo 2do nombre del cliente: ";
            cin >> entrenador.nombre2;
            cout << "Ingrese el nuevo 1re Apellido del cliente: ";
            cin >> entrenador.Apellido;
            cout << "Ingrese el nuevo 2do Apellido del cliente: ";
            cin >> entrenador.Apellido2;
            cout << "Ingrese la nueva Fecha de nacimiento (dd/mm/aaaa) : ";
            cin >> entrenador.fechadenacimiento;

            archivo1.seekp(-static_cast<int>(sizeof(EntrenadorC)), ios::cur);

            archivo1.write(reinterpret_cast<char*>(&entrenador), sizeof(EntrenadorC));
            break;
        }
    }

    archivo1.close(); // Cierra el archivo

    //si no lo encuentra mostrara el siguiente mensaj
    if (!encontrado) {
        cout << "No se encontró un cliente con el ID proporcionado." << endl;
    }

    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}

//funcion para borrarr
void Entrenador::borrar()
{

    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2204", "ALMB"); // Parámetros

	system("cls");
	string idPersona;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;
	cout<<"+                             Eliminar cliente                                 +"<<endl;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;


    ifstream archivo("Entrenadores.dat", ios::binary);

	if(!archivo)
	{
		cout<<"Error, no se encuentra informacion...";
		return;
	}
	ofstream archivo2("Entrenadores2.dat", ios::binary);

	EntrenadorC entrenador;

    cout<<"-> Ingrese el ID de la persona que desea eliminar: ";
    cin>>idPersona;

    bool resta = false;

		while(archivo.read(reinterpret_cast<char*>(&entrenador), sizeof(EntrenadorC)))
		{
			if(entrenador.id != idPersona)
			{
				archivo2.write(reinterpret_cast<const char*>(&entrenador), sizeof(EntrenadorC));
			}
			else
			{
			    resta = true;
			}

		}
        //cierra ambos archivos
		archivo.close();
		archivo2.close();

		remove("Entrenadores.dat");

		rename("Entrenadores2.dat","Entrenadores.dat");

		if (resta)
        {
        cout << "cliente eliminado con exito." << endl;
        }
        else
        {
        cout << "No se a podido encontrar el codigo del Entrenador" << endl;
        }
}
