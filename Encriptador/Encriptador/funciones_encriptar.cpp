#define NUMERO_ENCRIPTACION 4 // Definimos cuantos n�meros le queremos sumar en la tabla ASCII al char.
#include <iostream> // Incluimos todas las librer�as necesarias para que nuestro c�digo pueda funcionar correctamente.
#include <string>
#include <fstream>


using namespace std;
void escribirMensaje();
void recuperarMensaje();
void a�adirMensaje();


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

void a�adirMensaje() {

	ofstream file;
	file.open("filename.txt", std::ios::app);
	string mensajeEncriptado;
	string palabrasA�adir;
	char letraEncriptacion;
	
	cout << "Escribe lo que quieras" << endl;

	while (palabrasA�adir != "exit") {
		cin >> palabrasA�adir;
		for (short i = 0; i < palabrasA�adir.length(); i++) {

			letraEncriptacion = palabrasA�adir[i];

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

