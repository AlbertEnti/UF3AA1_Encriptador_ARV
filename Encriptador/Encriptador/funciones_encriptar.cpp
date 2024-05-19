#include <iostream>
#include <string>
#include <fstream>

using namespace std;
void escribirMensaje();
void recuperarMensaje();
void añadirMensaje();
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
	short opcionAñadir;
	
	cout << "Mensajes guardados detectados, ¿desea recuperarlos? " << endl;
	cout << "1. Si / 2. No, quiero machacar el archivo " << endl;

	cin >> opcionAñadir;

		switch (opcionAñadir) {
		
		case 1:
			añadirMensaje();
			break;
		case 2:
			eliminarArchivo();
			break;
		default:
			cout << "Usa los números que se te dan!!!" << endl;
			break;
		}
}

void encriptarMensaje() {

}

void añadirMensaje() {

	string textoRecuperacion;
	string palabrasAñadir;
	ofstream recuperarMensaje_2("filename.txt", std::ios::app);

	while (getline(recuperarMensaje_2, textoRecuperacion)) {
		cout << textoRecuperacion << endl;
	}

	cout << "Escribe lo que quieras" << std::endl;

	while (palabrasAñadir != "exit") {
		cin >> palabrasAñadir;
		recuperarMensaje_2 << palabrasAñadir;
		cout << "Sigue escribiendo, para salir escribe: exit" << std::endl;
	}
}

void eliminarArchivo() {
	remove("filename.txt");
	cout << "Archivo eliminado, saliendo del programa..." << endl;
	exit(0);
}
