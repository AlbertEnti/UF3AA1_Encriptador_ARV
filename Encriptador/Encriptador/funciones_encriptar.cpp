#include <iostream>
#include <fstream>
#include <string>

void menuPrincipal() {

	short eleccionMenu;
	string palabras;
	ofstream file("filename.txt");

	std::cout << "Bienvenido a tu encriptador personal" << std::endl;
	std::cout << "�Qu� quieres hacer?" << std::endl;
	std::cout << "1. Escribir mensajes / 2. Desencriptar mensaje" << std::endl;

	std::cin >> eleccionMenu;

	switch (eleccionMenu) {
	case 1:

		if (!file.is_open()) {
			std::cout << "Se pudo abrir el archivo." << std::endl;
			file.close();
		}

		while (palabras != "exit")
		{
			std::cout << "Escribe lo que quieras"<< std::endl;
			std::cin >> palabras;
			file << palabras;
			std::cout << "Sigue escribiendo, para salir escribe: exit" << std::endl;
		}
		file.close();
		break;

	case 2:

		std::cout << "Por ahora esta opci�n no est� disponible." << std::endl;
		break;


	default:

		std::cerr << "Usa uno de los dos n�meros que se te da!!" << std::endl;

	}
}