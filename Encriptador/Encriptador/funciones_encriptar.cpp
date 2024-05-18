#include <iostream>
#include <string>
#include <fstream>

using namespace std;
void escribirMensaje();
void recuperarMensaje();


void menuPrincipal() {
	
	short eleccionMenu;
	
	cout << "¡Bienvenido a tu encriptador personal!" << std::endl;
	cout << "¿Que quieres hacer?" << std::endl;
	cout << "1. Escribir mensajes / 2. Recuperar conversacion" << std::endl;

	cin >> eleccionMenu;

	switch (eleccionMenu) {
	case 1:
		 escribirMensaje();
		break;

	case 2:
		recuperarMensaje();	
		break;

	default:
		cerr << "Usa uno de los dos números que se te da!!" << std::endl;
	}
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
	short opcionAñadir;
	string textoRecuperacion;
	ifstream recuperarMensaje("filename.txt");
	while (getline (recuperarMensaje, textoRecuperacion)) {
		cout << textoRecuperacion;
	}
	/*cout << "Quieres añadir nuevos mensajes?" << endl;
		cin >> opcionAñadir;
	*/
	recuperarMensaje.close();


} 




