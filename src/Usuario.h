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
public:
	Usuario();
	Usuario(string, string, string, string, string, string);
	virtual ~Usuario();
	Usuario(const Usuario &other);
	void hacerPregunta();
	void responderPregunta();
	void listarInfo();
	void eliminarCuenta(int idUsuario);
	void notificar();
};

#endif /* USUARIO_H_ */
