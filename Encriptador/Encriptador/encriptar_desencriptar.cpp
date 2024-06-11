#define NUMERO_ENCRIPTACION 10 // Definimos cuantos números le queremos sumar en la tabla ASCII al char.
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

	// Si el archivo se puede abrir quiere decir que existe, haciendo que vaya directamente a la función "recuperar", en caso de que no exista irá hacia "escribir".
	if (file.is_open()) {
		recuperarMensaje();
	}
	else
		escribirMensaje();
}

void escribirMensaje() {

	// Declaramos las variables + abrimos el archivo.
	string palabras;
	string mensajeEncriptado;
	char letraEncriptacion;
	ofstream file("filename.txt");

	// En el caso de que no se pueda abrir el archivo saldrá por pantalla y hará que acabe el programa.
	if (!file.is_open()) {
		cout << "No se pudo abrir el archivo." << endl;
		file.close();
	}
	cout << "Escribe lo que quieras" << endl;

	while (palabras != "exit")
	{
		cin >> palabras;
		// Método de encriptación.
		for (short i = 0; i < palabras.length(); i++) {

			letraEncriptacion = palabras[i];

			letraEncriptacion = letraEncriptacion + NUMERO_ENCRIPTACION;

			mensajeEncriptado = letraEncriptacion;

			file << mensajeEncriptado;
		}
		cout << "Sigue escribiendo, para salir escribe: exit" << endl;
	}
	short checksum = 0;

	for (short i = 0; i < palabras.size(); i++)
	{
		for (short j = 0; j < palabras[i].size(); j++)
		{
			palabras[i][j] = palabras[i][j] + NUMERO_ENCRIPTACION;
			checksum += int(palabras[i].at(j));	
		}
	}
	file << checksum << std::endl;
	for (short i = 0; i < palabras.size(); i++)
	{
		file << palabras[i] << ';';
	}

	file.close();
}


void recuperarMensaje()
{

	short opcionAñadir;

	cout << "Mensajes guardados detectados, ¿desea recuperarlos? " << endl;
	cout << "1. Si / 2. No" << endl;

	cin >> opcionAñadir;

	// Hacemos un switch case en el que vamos a tener las dos funciones para depende de lo que necesite. 
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
	// Abrimos el archivo filename en modo append para añadir a lo ya escrito + declaramos las variables necesarias.
	fstream file;
	file.open("filename.txt", std::ios::app);
	string mensajeDesencriptado;
	string mensajeEncriptado;
	string palabrasAñadir;
	string palabrasDesencriptar;
	char letraDesencriptacion;
	char letraEncriptacion;


	// 1. Desencriptación mensajes anteriores

	file >> mensajeDesencriptado;

	for (short i = 0; i < mensajeDesencriptado.length(); i++) {

		letraDesencriptacion = palabrasDesencriptar[i];

		letraDesencriptacion = letraDesencriptacion - NUMERO_ENCRIPTACION;

		mensajeDesencriptado = letraDesencriptacion;
	}

	// 2. Mostramos mensajes anteriores. (NO FUNCIONA :/)
	while (getline(file, mensajeDesencriptado)) {
		cout << mensajeDesencriptado << endl;
	}

	cout << "Escribe lo que quieras" << endl;


	// 3. Añadimos todo el input a la string.
	while (palabrasAñadir != "exit") {
		cin >> palabrasAñadir;

		// 4. Encriptación
		for (short i = 0; i < palabrasAñadir.length(); i++) {

			letraEncriptacion = palabrasAñadir[i];

			letraEncriptacion = letraEncriptacion + NUMERO_ENCRIPTACION;

			mensajeEncriptado = letraEncriptacion;

			file << mensajeEncriptado;
		}
		cout << "Sigue escribiendo, para salir escribe: exit" << endl;
	}
	file.close();
}