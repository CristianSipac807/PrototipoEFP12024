//Cristian David Sipac Ispache
//9959-23-1567
#include <cstring>
#include "Bitacora.h"
#include "Login.h"

void Bitacora::ingresoBitacora(const string& usuario, const string& codigoPrograma, const string& tipoIngreso) {


    ofstream archivo("Bitacora.dat", ios::binary | ios::app);


    if (archivo.is_open()) {

        RegistroBitacora registro;
        strncpy(registro.nombre, usuario.c_str(), sizeof(registro.nombre) - 1);
        registro.nombre[sizeof(registro.nombre) - 1] = '\0';
        strncpy(registro.aplicacion, codigoPrograma.c_str(), sizeof(registro.aplicacion) - 1);
        registro.aplicacion[sizeof(registro.aplicacion) - 1] = '\0';
        strncpy(registro.accion, tipoIngreso.c_str(), sizeof(registro.accion) - 1);
        registro.accion[sizeof(registro.accion) - 1] = '\0';
        time_t now = time(0);
        tm *ltm = localtime(&now);
        string fechaHora = to_string(ltm->tm_year + 1900) + "-" + to_string(ltm->tm_mon + 1) + "-" + to_string(ltm->tm_mday) + " " +
                           to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
        strncpy(registro.fechaHora, fechaHora.c_str(), sizeof(registro.fechaHora) - 1);
        registro.fechaHora[sizeof(registro.fechaHora) - 1] = '\0';

        archivo.write(reinterpret_cast<char*>(&registro), sizeof(RegistroBitacora));

        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo de bit�cora." << endl;
    }
}



void Bitacora::mostrarBitacora() {

    // Obteniendo el usuario actual que ha iniciado sesi�n
    string usuarioActual = Login::getUsuarioActual();

    // Registra el ingreso del usuario actual en la bit�cora
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2000", "BIT");

    // Limpiando la pantalla
    system("cls");

    // Abre el archivo de bit�cora en modo de lectura binaria
    ifstream archivo("Bitacora.dat", ios::binary | ios::in);

    // Verificacion si el archivo se ha abierto correctamente
    if (!archivo) {

        //Si no se ha abierto correctamente muestra lo siguiente
        cout << "No hay informaci�n registrada en la bit�cora." << endl;
        return;
    }

    //Instancia de RegistroBitacora
    RegistroBitacora registro;
    while (archivo.read(reinterpret_cast<char*>(&registro), sizeof(RegistroBitacora))) {
        cout << "Usuario: " << registro.nombre << ", Aplicacion: " << registro.aplicacion << ", Accion: " << registro.accion << ", Fecha y Hora: " << registro.fechaHora << endl;
    }
    //Cerrar archivo
    archivo.close();

    //Mensaje al usuario
    cout << "Presione Enter para continuar";
    cin.ignore();
    cin.get();
}



