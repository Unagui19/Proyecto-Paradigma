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
	Usuario(const Usuario &other);
	virtual ~Usuario();
	void notificar();
	void hacerPregunta();
	void responderPregunta(int);
	void eliminarCuenta();
	void listarInfo();
	void aceptarRespuesta(int);

	//------------GETTERS-------------------
	int getRespAcep() {
		return respAceptadas;
	};
	int getCodigo() {
		return codigo;
	}
	string getNombre() {
		return nombre;
	}
};

#endif /* USUARIO_H_ */
