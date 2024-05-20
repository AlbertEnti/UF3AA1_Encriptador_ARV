#define NUMERO_ENCRIPTACION 4 // Definimos cuantos números le queremos sumar en la tabla ASCII al char.
#include <iostream> // Incluimos todas las librerías necesarias para que nuestro código pueda funcionar correctamente.
#include <string>
#include <fstream>


using namespace std;
void escribirMensaje();
void recuperarMensaje();
void añadirMensaje();


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
	string mensajeEncriptado;
	char letraEncriptacion;
	
	ofstream file("filename.txt");

	if (!file.is_open()) {
		cout << "No se pudo abrir el archivo." << endl;
		file.close();
	}
	cout << "Escribe lo que quieras" << endl;

	while (palabras != "exit")
	{
		cin >> palabras;

		for (short i = 0; i < palabras.length(); i++) {

			letraEncriptacion = palabras[i];

			letraEncriptacion = letraEncriptacion + NUMERO_ENCRIPTACION;

			mensajeEncriptado = letraEncriptacion;

			file << mensajeEncriptado;
		}

		cout << "Sigue escribiendo, para salir escribe: exit" << endl;
	}
	file.close();
}

void recuperarMensaje() {
	
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

void añadirMensaje() {

	ofstream file;
	file.open("filename.txt", std::ios::app);
	string mensajeEncriptado;
	string palabrasAñadir;
	char letraEncriptacion;
	
	cout << "Escribe lo que quieras" << endl;

	while (palabrasAñadir != "exit") {
		cin >> palabrasAñadir;
		for (short i = 0; i < palabrasAñadir.length(); i++) {

			letraEncriptacion = palabrasAñadir[i];

			letraEncriptacion = letraEncriptacion + NUMERO_ENCRIPTACION;

			mensajeEncriptado = letraEncriptacion;

			file << mensajeEncriptado;
		}
		cout << "Sigue escribiendo, para salir escribe: exit" << endl;
	}
	file.close();

	/*while (getline(file, textoRecuperacion)) {
		cout << textoRecuperacion << endl;
	}
	*/
}

