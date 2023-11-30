/*
 * Pregunta.cpp
 *
 *  Created on: 3 nov. 2023
 *      Author: Alumno
 */

#include "Pregunta.h"

		//-------------CONSTRUCTORES Y DESTRUCTOR-------------------
Pregunta::Pregunta() {
	// TODO Auto-generated constructor stub

}

Pregunta::Pregunta(string tit, string desc, string tag, Imagen img, Fecha creacion, Usuario* usu) {
	codigo++;
	id = codigo;
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

		//------------OTROS METODOS-------------------

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
		if (respuestas[i]->getIdResp() == id) {
			return respuestas[i];
		}
	}
	cout << "No se encontro la pregunta" << endl;
	return 0;
}

void Pregunta::rankingRespuestas() {
	vector<Respuesta*> aux = respuestas;
	int maxId = 0;
	int max = -1;
	for (size_t j = 0; j < respuestas.size(); ++j) {
		for (size_t i = 0; i < aux.size(); ++i) {
			if(!respuestas[i]->isAceptada()) //control para ver si la respuesta es la aceptada
			{
				if (aux[i]->getCantMg() > max)
				{
					max = aux[i]->getCantMg();
					maxId = aux[i]->getIdResp();
				}
			}
			else{//si la respuesta esta aceptada sale del for direrectamente
				maxId = aux[i]->getIdResp();
				break;
			}
		}
		cout << "Respuesta: " << buscarRespuestaPorId(maxId)->getIdResp() << endl;
		cout << "Cantidad de Me Gusta: " << buscarRespuestaPorId(maxId)->getCantMg() << endl;

		if(buscarRespuestaPorId(maxId)->aceptada)
			cout << "¡¡Respuesta aceptada!!" << endl;
		}

		for(size_t i = 0; i < aux.size(); ++i) {
			if (aux[i]->getIdResp()() == maxId) {
				aux.erase(aux.begin() + i); //metodo eliminar un element esp
			}
		}
		max = -1;
		maxId = 0;
	}
}

void Pregunta::aceptarRespuesta(int id) {
	buscarRespuestaPorId(id)->aceptar();
	cambiarEstado(new Solucionada());
}
