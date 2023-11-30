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
#include "Imagen.h"
#include "Fecha.h"

class Sistema;

class Usuario {
private:
	Sistema* sistema;
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
	Usuario(string, string, string, string, string, string, Sistema*);
	virtual ~Usuario();
	Usuario(const Usuario &other);
	void hacerPregunta();
	void responderPregunta(int);
	void listarInfo();
	void notificar();

	//------------GETTERS-------------------
	int getRespAcep() {
		return respAceptadas;
	};
	int getId() {
		return id;
	}
	string getNombre() {
		return nombre;
	}
};

#endif /* USUARIO_H_ */
