/*
 * Sistema.h
 *
 *  Created on: 3 nov. 2023
 *      Author: Alumno
 */

#ifndef SISTEMA_H_
#define SISTEMA_H_
#include <iostream>
using namespace std;
#include "Usuario.h"
#include "Pregunta.h"
#include "Imagen.h"
#include "Fecha.h"
#include "Respuesta.h"
#include <vector>

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
	void crearUsuario(string nombre, string apellido, string email, string contra, string paisO, string nick);
	void mostrarListadoPreguntas();
	void mostrarPregunta(int idPregunta);
	void borrarUsuario(int idUsu);
	void mostrarUsuario(int idUsu);
	void rankingUsuarios();
	vector<Pregunta> buscarPreguntaPorTags(string tag);

};

#endif /* SISTEMA_H_ */
