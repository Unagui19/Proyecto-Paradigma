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
	int static codigo;
	int id;
	string nombre;
	string apellido;
	string email;
	string contrasenia;
	string paisOrigen;
	string nick;
	int respAceptadas;
	int notificaciones;
	Imagen foto;
public:
	Usuario();
	Usuario(string, string, string, string, string, string, Sistema*);
	virtual ~Usuario();
	Usuario(const Usuario &other);
	void hacerPregunta();
	void responderPregunta(int);
	void listarInfo();
	void notificar();
	void eliminarCuenta();
	void aceptarRespuesta(int, int);

	//------------GETTERS-------------------
	int getRespAcep() {
		return respAceptadas;
	};
	int getId() {
		return id;
	}
	string getNombre() {
		return nombre;
	};
	string getNick() {
			return nick;
	};
};

#endif /* USUARIO_H_ */
