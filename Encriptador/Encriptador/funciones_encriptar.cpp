#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h> 

using namespace std;
void escribirMensaje();
void recuperarMensaje();
void a�adirMensaje();
void encriptarMensaje();


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
		cout << "No se pudo abrir el archivo." << endl;
		escribirMensaje.close();
	}
	cout << "Escribe lo que quieras" << endl;

	while (palabras != "exit")
	{
		cin >> palabras;
		escribirMensaje << palabras << endl;

		cout << "Sigue escribiendo, para salir escribe: exit" << endl;
	}
	escribirMensaje.close();
}

void recuperarMensaje() {
	
	string palabras;
	string textoRecuperacion;
	short opcionA�adir;
	
	cout << "Mensajes guardados detectados, �desea recuperarlos? " << endl;
	cout << "1. Si / 2. No" << endl;

	cin >> opcionA�adir;

		switch (opcionA�adir) {
		
		case 1:
			a�adirMensaje();
			break;
		case 2:
			escribirMensaje();
			break;
		default:
			cout << "Usa los n�meros que se te dan!!!" << endl;
			break;
		}
}

void encriptarMensaje(string palabras) {
	
	char letraEncriptacion;

	for (short i = 0; i < palabras.length(); i++) {

		letraEncriptacion = palabras[i];

		letraEncriptacion = letraEncriptacion + 4;
	}
}

void a�adirMensaje() {

	ofstream file;
	file.open("filename.txt", std::ios::app);
	string textoRecuperacion;
	string palabrasA�adir;
	
	cout << "Escribe lo que quieras" << endl;

	while (palabrasA�adir != "exit") {
		cin >> palabrasA�adir;
		file << palabrasA�adir;
		cout << "Sigue escribiendo, para salir escribe: exit" << endl;
	}
	file.close();

	/*while (getline(recuperarMensaje_2, textoRecuperacion)) {
		cout << textoRecuperacion << endl;
	}
	*/
}

