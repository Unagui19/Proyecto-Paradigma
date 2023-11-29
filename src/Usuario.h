/*
 * Usuario.h
 *
 *  Created on: 3 nov. 2023
 *      Author: Alumno
 */

#ifndef USUARIO_H_
#define USUARIO_H_
#include <iostream>
using namespace std;
#include "Pregunta.h"
#include "Respuesta.h"

class Usuario {
private:
	int static id;
	string nombre;
	string apellido;
	string email;
	string contrasenia;
	string paisOrigen;
	string nick;
	int respAceptadas;
	int notificaciones;
	Pregunta preg;
	Respuesta resp;

public:
	Usuario();
	Usuario(string nom, string ape, string em, string con, string po, string ni);
	virtual ~Usuario();
	Usuario(const Usuario &other);
	void hacerPregunta();
	void responderPregunta();
	void listarInfo();
	void eliminarCuenta(int idUsuario);
	void notificar();
};

#endif /* USUARIO_H_ */
