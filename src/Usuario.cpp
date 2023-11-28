/*
 * Usuario.cpp
 *
 *  Created on: 3 nov. 2023
 *      Author: Alumno
 */

#include "Usuario.h"

Usuario::Usuario() {
	// TODO Auto-generated constructor stub

}

Usuario::Usuario(string nom, string ape, string em, string con, string po, string ni) {
	id++;
	nombre = nom;
	apellido = ape;
	email = em;
	contrasenia = con;
	paisOrigen = po;
	nick = ni;
	respAceptadas = 0;
	notificaciones = 0;
}

int Usuario::id = 0;

Usuario::~Usuario() {
	// TODO Auto-generated destructor stub
}

Usuario::Usuario(const Usuario &other) {
	// TODO Auto-generated constructor stub

}

void Usuario::hacerPregunta(){};
void Usuario:: responderPregunta(){};
void Usuario:: listarInfo(){};
void Usuario::eliminarCuenta(int idUsuario){};

void Usuario::notificar() {
	notificaciones++;
}


