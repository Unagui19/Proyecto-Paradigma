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
	void mostrarListadoPreguntas();
	void mostrarPregunta(int idPregunta);
	void borrarUsuario(int idUsu);
	void mostrarUsuario(int idUsu);
	void rankingUsuarios();
	Pregunta buscarPreguntaPorTags(string tag);

};

#endif /* SISTEMA_H_ */
