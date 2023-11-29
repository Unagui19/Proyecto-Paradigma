/*
 * Pregunta.cpp
 *
 *  Created on: 3 nov. 2023
 *      Author: Alumno
 */

#include "Pregunta.h"

Pregunta::Pregunta() {
	// TODO Auto-generated constructor stub

}

Pregunta::Pregunta(string tit, string desc, string tag, Imagen img, Fecha creacion, Usuario* usu) {
	codigo++;
	titulo = tit;
	descripcion = desc;
	tags = tag;
	imagen = img;
	fechaCreacion = creacion;
	usuario = usu;
	estadoActual = new Activa();
}

int Pregunta::codigo = 0;

Pregunta::~Pregunta() {
	// TODO Auto-generated destructor stub
}

Pregunta::Pregunta(const Pregunta &other) {
	// TODO Auto-generated constructor stub

}

void Pregunta::cambiarEstado(Estado* nuevoEstado) {
	if (typeid(*estadoActual) != typeid(Solucionada)) {
		delete estadoActual;
		estadoActual = nuevoEstado;
	}
}

void Pregunta::guardarRespuesta(Respuesta* respuesta) {
	respuestas.push_back(respuesta);
}

void Pregunta::crearRespuesta(string desc, Fecha fec, Usuario* usu, Imagen img) {
	if (estadoActual->puedeRecibirRespuesta()) {
		Respuesta* respuesta = new Respuesta(desc, fec, usu, img);
		guardarRespuesta(respuesta);
		if (estadoActual->notificar()) {
			usuario->notificar();
		}
		if (typeid(*estadoActual) == typeid(Inactiva)) {
			cambiarEstado(new Activa());
		}
	} else {
		cout << "La pregunta ya fue solucionada" << endl;
	}
}

Respuesta* Pregunta::buscarRespuestaPorId(int id) {
	for (size_t i = 0; i < respuestas.size(); ++i) {
		if (respuestas[i]->getId() == id) {
			return respuestas[i];
		}
	}
	cout << "No se encontro la pregunta" << endl;
	return 0;
}

void Pregunta::aceptarRespuesta(int id) {
	buscarRespuestaPorId(id)->aceptar();
	cambiarEstado(new Solucionada());
}
