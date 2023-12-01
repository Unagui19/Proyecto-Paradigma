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

class Sistema {
private:
	vector<Usuario*> usuarios;
	vector<Pregunta*> preguntas;
	void guardarUsuario(Usuario*);
	void guardarPregunta(Pregunta*);
public:
	Sistema();
	virtual ~Sistema();
	Sistema(const Sistema &other);

	void crearUsuario(string, string, string, string, string, string);
	Usuario* buscarUsuarioPorId(int);
	void rankingUsuario();
	void borrarUsuario(Usuario*);

	void crearRespuesta(string, Fecha, Usuario*, Imagen, int);
	void crearPregunta(string, string, string, Imagen, Fecha, Usuario*);
	vector<Pregunta*> buscarPreguntasPorTag(string);
	Pregunta* buscarPreguntaPorId(int);
	void listarPreguntas();
	void revisarFecha();
	void mostrarUsuario(int);
	void mostrarPregunta(int);
};

#endif /* SISTEMA_H_ */
