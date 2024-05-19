#include <iostream>
#include <string>
#include <fstream>

using namespace std;
void escribirMensaje();
void recuperarMensaje();
void a�adirMensaje();
void encriptarMensaje();
void eliminarArchivo();


void menuPrincipal() {

	ifstream file("filename.txt");
	file.open("filename.txt");

	if (file.is_open()) {
		recuperarMensaje();
	}
	else
		escribirMensaje();
}

void escribirMensaje() {

	string palabras;
	ofstream escribirMensaje("filename.txt");

	if (!escribirMensaje.is_open()) {
		cout << "No se pudo abrir el archivo." << std::endl;
		escribirMensaje.close();
	}
	cout << "Escribe lo que quieras" << std::endl;

	while (palabras != "exit")
	{
		cin >> palabras;
		escribirMensaje << palabras;
		cout << "Sigue escribiendo, para salir escribe: exit" << std::endl;
	}
	escribirMensaje.close();
}

void recuperarMensaje() {
	
	string palabras;
	string textoRecuperacion;
	short opcionA�adir;
	
	cout << "Mensajes guardados detectados, �desea recuperarlos? " << endl;
	cout << "1. Si / 2. No, quiero machacar el archivo " << endl;

	cin >> opcionA�adir;

		switch (opcionA�adir) {
		
		case 1:
			a�adirMensaje();
			break;
		case 2:
			eliminarArchivo();
			break;
		default:
			cout << "Usa los n�meros que se te dan!!!" << endl;
			break;
		}
}

void encriptarMensaje() {

}

void a�adirMensaje() {

	string textoRecuperacion;
	string palabrasA�adir;
	ofstream recuperarMensaje_2("filename.txt", std::ios::app);

	while (getline(recuperarMensaje_2, textoRecuperacion)) {
		cout << textoRecuperacion << endl;
	}

	cout << "Escribe lo que quieras" << std::endl;

	while (palabrasA�adir != "exit") {
		cin >> palabrasA�adir;
		recuperarMensaje_2 << palabrasA�adir;
		cout << "Sigue escribiendo, para salir escribe: exit" << std::endl;
	}
}

void eliminarArchivo() {
	remove("filename.txt");
	cout << "Archivo eliminado, saliendo del programa..." << endl;
	exit(0);
}
