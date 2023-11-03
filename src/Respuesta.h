/*
 * Respuesta.h
 *
 *  Created on: 3 nov. 2023
 *      Author: Alumno
 */

#ifndef RESPUESTA_H_
#define RESPUESTA_H_
#include "Fecha.h"
#include "Imagen.h"
#include "Usuario.h"

class Respuesta {
private:
	string respuesta;
	Fecha fecha;
	Usuario usuario;
	Imagen imagen;
	bool aceptada;
	int static codigo;
	int cantMg;
public:
	Respuesta();
	Respuesta(string, Fecha, Usuario, Imagen);
	virtual ~Respuesta();
	Respuesta(const Respuesta &other);
	void darMg();
};

#endif /* RESPUESTA_H_ */
