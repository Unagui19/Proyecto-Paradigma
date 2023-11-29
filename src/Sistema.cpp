/*
 * Sistema.cpp
 *
 *  Created on: 3 nov. 2023
 *      Author: Alumno
 */

#include "Sistema.h"

Sistema::Sistema() {
	// TODO Auto-generated constructor stub

}

Sistema::~Sistema() {
	// TODO Auto-generated destructor stub
}

Sistema::Sistema(const Sistema &other) {
	// TODO Auto-generated constructor stub

}

void Sistema::guardarUsuario(Usuario* usuario) {
	usuarios.push_back(usuario);
}

void Sistema::crearUsuario(string nom, string ape, string em, string con, string po, string ni) {
	Usuario* usuario = new Usuario(nom, ape, em, con, po, ni, this);
	guardarUsuario(usuario);
}

void Sistema::guardarPregunta(Pregunta* pregunta) {
	preguntas.push_back(pregunta);
}

void Sistema::crearPregunta(string tit, string desc, string tag, Imagen img, Fecha creacion, Usuario* usu) {
	Pregunta* pregunta = new Pregunta(tit, desc, tag, img, creacion, usu);
	guardarPregunta(pregunta);
}

void Sistema::crearRespuesta(string tit, Fecha fecha, Usuario* usu, Imagen img, int idPregunta) {
	buscarPreguntaPorId(idPregunta)->crearRespuesta(tit, fecha, usu, img);
}

Pregunta* Sistema::buscarPreguntaPorId(int id) {
	for (size_t i = 0; i < preguntas.size(); ++i) {
		if (preguntas[i]->getId() == id) {
			return preguntas[i];
		}
	}
	cout << "No se encontro la pregunta" << endl;
	return 0;
}
