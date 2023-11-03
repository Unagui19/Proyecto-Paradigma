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

Pregunta::Pregunta(string tit, string desc, string tag, Imagen img, Fecha creacion, Usuario usu) {
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
	delete estadoActual;
	estadoActual = nuevoEstado;
}

void Pregunta::guardarRespuesta(Respuesta* respuesta) {
	respuestas.push_back(respuesta);
}

void Pregunta::crearRespuesta(string desc, Fecha fec, Usuario usu, Imagen img) {
	if (estadoActual->puedeRecibirRespuesta()) {
		switch (estadoActual->mostrarEstado()) {
			case typeid(Activa):
				Respuesta* respuesta = new Respuesta(desc, fec, usu, img);
				guardarRespuesta(respuesta);
				break;
			case typeid(Inactiva):
				Respuesta* respuesta = new Respuesta(desc, fec, usu, img);
				guardarRespuesta(respuesta);
				cambiarEstado(new Activa());
				break;
			case typeid(Suspendida):
				Respuesta* respuesta = new Respuesta(desc, fec, usu, img);
				guardarRespuesta(respuesta);
				break;
		}
		if (estadoActual->notificar()) {
			usuario.notificar();
		}
	} else {
		cout << estadoActual->mostrarEstado() << endl;
	}

}
