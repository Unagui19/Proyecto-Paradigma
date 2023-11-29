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

void Sistema::revisarFecha() {
}

vector<Pregunta*> Sistema::buscarPreguntasPorTag(string tag) {
	vector<Pregunta*> preguntasTag;
	for (size_t i = 0; i < preguntas.size(); ++i) {
		if (preguntas[i]->getTag() == tag) {
			preguntasTag.push_back(preguntas[i]);
		}
	}
	return preguntasTag;
}

Usuario* Sistema::buscarUsuarioPorId(int id) {
	for (size_t i = 0; i < usuarios.size(); ++i) {
		if (usuarios[i]->getId() == id) {
			return usuarios[i];
		}
	}
	cout << "No se encontro el usuario" << endl;
	return 0;
}

void Sistema::rankingUsuario() {
	vector<Usuario*> aux = usuarios;
	int maxId = 0;
	int max = -1;
	for (size_t j = 0; j < usuarios.size(); ++j) {
		for (size_t i = 0; i < aux.size(); ++i) {
			if (aux[i]->getRespAcep() > max) {
				max = aux[i]->getRespAcep();
				maxId = aux[i]->getId();
			}
		}
		cout << "Usuario: " << buscarUsuarioPorId(maxId)->getNombre() << endl;
		cout << "Cantidad respuestas aceptadas: " << buscarUsuarioPorId(maxId)->getRespAcep() << endl;
		for(size_t i = 0; i < aux.size(); ++i) {
			if (aux[i]->getId() == maxId) {
				aux.erase(aux.begin() + i); //metodo eliminar un element esp
			}
		}
		max = -1;
		maxId = 0;
	}
}

void Sistema::listarPreguntas() {
	for (size_t i = 0; i < preguntas.size(); ++i) {
		cout << "Id: " << preguntas[i]->getId() << endl;
		cout << "Titulo: " << preguntas[i]->getTitulo() << endl;
		cout << "Descripcion: " << preguntas[i]->getDescripcion() << endl;
		cout << "Tags: " << preguntas[i]->getTag() << endl;
	}
}
