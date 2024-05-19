#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h> 

using namespace std;
void escribirMensaje();
void recuperarMensaje();
void añadirMensaje();
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
	short opcionAñadir;
	
	cout << "Mensajes guardados detectados, ¿desea recuperarlos? " << endl;
	cout << "1. Si / 2. No" << endl;

	cin >> opcionAñadir;

		switch (opcionAñadir) {
		
		case 1:
			añadirMensaje();
			break;
		case 2:
			escribirMensaje();
			break;
		default:
			cout << "Usa los números que se te dan!!!" << endl;
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

void añadirMensaje() {

	ofstream file;
	file.open("filename.txt", std::ios::app);
	string textoRecuperacion;
	string palabrasAñadir;
	
	cout << "Escribe lo que quieras" << endl;

	while (palabrasAñadir != "exit") {
		cin >> palabrasAñadir;
		file << palabrasAñadir;
		cout << "Sigue escribiendo, para salir escribe: exit" << endl;
	}
	file.close();

	/*while (getline(recuperarMensaje_2, textoRecuperacion)) {
		cout << textoRecuperacion << endl;
	}
	*/
}

