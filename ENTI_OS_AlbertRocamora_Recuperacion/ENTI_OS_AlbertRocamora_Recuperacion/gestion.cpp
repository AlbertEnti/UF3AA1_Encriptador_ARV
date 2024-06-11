#include <iostream>
#include <string>

void menuInicial() {

	std::cout << "Bienvenido a ENTI OS:" << std::endl;
	std::cout << "Introduzca su usuario:" << std::endl;
	std::cin >> usuarioActual;
	std::cout << "Introduzca la contrase�a de" << usuarioActual <<":" << std::endl;
	std::cin >> contrase�a;
	std::cout << "Introduzca de nuevo la contrase�a de" << usuarioActual << ":" << std::endl;
	std::cin >> contrase�aConfirmacion;
}

void menuAdmin() {

	std::cout << "Estas logueado como	" << usuarioActual << std::endl;
	std::cout << std::endl;
	std::cout << "1 - Gestionar usuario" << std::endl;
	std::cout << "2 - Cambiar usuario" << std::endl;
	std::cout << "3 - Gestionar directorios" << std::endl;
	std::cout << "4 - Gestionar tareas" << std::endl;
	std::cout << "5 - Salir del sistema" << std::endl;

	std::cin >> opcion;

	switch (opcion) {
	case 1:
		creacionUsuario();
		break;
	case 2:
		cambiarUsuario();
		break;
	case 3:
		gestionDirectorios();
		break;
	case 4:
		gestionTareas();
		break;
	case 5:
		std::cout << "Saliendo del sistema..." << std::endl;
		break;

	default:
		std::cout << "Usa los n�meros que se dan." << std::endl;
		break;

	}
}

void gestionUsuario() {

	std::cout << "1 - Crear usuario" << std::endl;
	std::cout << "2 - Salir del sistema" << std::endl;
	std::cout << "3 - Salir del sistema" << std::endl;
	std::cout << "4 - Salir del sistema" << std::endl;
	std::cin >> opcion;

		switch (opcion) {
		case 1:
			creacionUsuario();
			break;
		case 2:
			modificarPass();
			break;
		case 3:
			eliminarUsuario();
			break;
		case 4:
			menuAdmin();
			break;
		default:
			std::cout << "Usa las opciones que se te dan." << std::endl;
			break;

	}
}

void creacionUsuario() {

	std::cout << "Introduzca el nombre del nuevo usuario" << std::endl;
	std::cin >> nuevoUsuario;
	std::cout << "Introduzca la contrase�a del nuevo usuario" << std::endl;
	std::cin >> nuevaConstrase�a;
	std::cout << "Introduzca de nuevo la contrase�a del nuevo usuario" << std::endl;
	std::cin >> repenuevaConstrase�a;


	if (nuevaContrase�a != repenuevaContrase�a) {
		std::cout << "Contrase�as no coincidentes, vuelva a intentarlo." << std::endl;
	}
	else {

	}
}

void modificarPass() {

}

void eliminarUsuario() {

}

void cambiarUsuario() {

}

void gestionDirectorios() {

}

void gestionTareas() {

}