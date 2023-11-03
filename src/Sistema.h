/*
 * Sistema.h
 *
 *  Created on: 3 nov. 2023
 *      Author: Alumno
 */

#ifndef SISTEMA_H_
#define SISTEMA_H_
#include "Usuario.h"
#include "Pregunta.h"

class Sistema {
private:
	vector<Usuario> usuarios;
	vector<Pregunta> preguntas;
	void guardarUsuario();
	void guardarPregunta();
public:
	Sistema();
	virtual ~Sistema();
	Sistema(const Sistema &other);
	void crearPregunta(string, string, Imagen);
	void crearUsuario(string, string, string, string, string, string);
};

#endif /* SISTEMA_H_ */
