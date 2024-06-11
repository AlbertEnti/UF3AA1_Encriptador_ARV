#define NUMERO_ENCRIPTACION 10 // Definimos cuantos n�meros le queremos sumar en la tabla ASCII al char.
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

	// Si el archivo se puede abrir quiere decir que existe, haciendo que vaya directamente a la funci�n "recuperar", en caso de que no exista ir� hacia "escribir".
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

	// En el caso de que no se pueda abrir el archivo saldr� por pantalla y har� que acabe el programa.
	if (!file.is_open()) {
		cout << "No se pudo abrir el archivo." << endl;
		file.close();
	}
	cout << "Escribe lo que quieras" << endl;

	while (palabras != "exit")
	{
		cin >> palabras;
		// M�todo de encriptaci�n.
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

	short opcionA�adir;

	cout << "Mensajes guardados detectados, �desea recuperarlos? " << endl;
	cout << "1. Si / 2. No" << endl;

	cin >> opcionA�adir;

	// Hacemos un switch case en el que vamos a tener las dos funciones para depende de lo que necesite. 
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
	// Abrimos el archivo filename en modo append para a�adir a lo ya escrito + declaramos las variables necesarias.
	fstream file;
	file.open("filename.txt", std::ios::app);
	string mensajeDesencriptado;
	string mensajeEncriptado;
	string palabrasA�adir;
	string palabrasDesencriptar;
	char letraDesencriptacion;
	char letraEncriptacion;


	// 1. Desencriptaci�n mensajes anteriores

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


	// 3. A�adimos todo el input a la string.
	while (palabrasA�adir != "exit") {
		cin >> palabrasA�adir;

		// 4. Encriptaci�n
		for (short i = 0; i < palabrasA�adir.length(); i++) {

			letraEncriptacion = palabrasA�adir[i];

			letraEncriptacion = letraEncriptacion + NUMERO_ENCRIPTACION;

			mensajeEncriptado = letraEncriptacion;

			file << mensajeEncriptado;
		}
		cout << "Sigue escribiendo, para salir escribe: exit" << endl;
	}
	file.close();
}