/*
 * Sistema.cpp
 *
 *  Created on: 3 nov. 2023
 *      Author: Alumno
 */
#include <iostream>
using namespace std;
#include "Sistema.h"
#include "Usuario.h"
#include "Pregunta.h"
#include "vector"
#include <algorithm>//en esta libreria esta la funcion find
		//-------------CONSTRUCTORES Y DESTRUCTOR-------------------

Sistema::Sistema() {
	// TODO Auto-generated constructor stub

}

Sistema::~Sistema() {
	// TODO Auto-generated destructor stub
}

Sistema::Sistema(const Sistema &other) {
	// TODO Auto-generated constructor stub

}

		//------------METODOS PARA USUARIO-------------------

void Sistema::guardarUsuario(Usuario* usuario) {
	usuarios.push_back(usuario);
}

void Sistema::crearUsuario(string nom, string ape, string em, string con, string po, string ni) {
	Usuario* usuario = new Usuario(nom, ape, em, con, po, ni, this);
	guardarUsuario(usuario);
}


void Sistema::crearRespuesta(string tit, Fecha fecha, Usuario* usu, Imagen img, int idPregunta) {
	buscarPreguntaPorId(idPregunta)->crearRespuesta(tit, fecha, usu, img);
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
				aux.erase(aux.begin() + i); //metodo eliminar un element especifico
			}
		}
		max = -1;
		maxId = 0;
	}
}

void Sistema::borrarUsuario(Usuario* usu){
	auto it=find(usuarios.begin(),usuarios.end(),usu);//busca un elemento especifico en un rango determinado (como en vectores, filas , etc)

	if (it != usuarios.end()) {
	        // Si se encontró el elemento, eliminarlo
		usuarios.erase(it);
		cout << "Elemento eliminado con éxito del listado." << endl;
	} else {
		cout << "Elemento no encontrado en el vector." << endl;
	}

	for (size_t i = 0; i < preguntas.end(); ++i) {//aqui busco las preguntas asociadas al usuario eliminado y les cambio el estado a "Suspendida"
		if(preguntas[i]->usuario->getId()==usu->getId()){
			preguntas[i]->cambiarEstado(new Suspendida);
			preguntas[i]->usuario=nullptr;//apunto las preguntas relacionadas al usuario eliminado hacia null;
		}
	}

	delete(usu);
}

		//------------METODOS PARA PREGUNTAS-------------------

void Sistema::guardarPregunta(Pregunta* pregunta) {
	preguntas.push_back(pregunta);
}

void Sistema::crearPregunta(string tit, string desc, string tag, Imagen img, Fecha creacion, Usuario* usu) {
	Pregunta* pregunta = new Pregunta(tit, desc, tag, img, creacion, usu);
	guardarPregunta(pregunta);
}
void Sistema::listarPreguntas() {
	for (size_t i = 0; i < preguntas.size(); ++i) {
		cout << "Id: " << preguntas[i]->getId() << endl;
		cout << "Titulo: " << preguntas[i]->getTitulo() << endl;
		cout << "Descripcion: " << preguntas[i]->getDescripcion() << endl;
		cout << "Tags: " << preguntas[i]->getTag() << endl;
	}
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


vector<Pregunta*> Sistema::buscarPreguntasPorTag(string tag) {
	vector<Pregunta*> preguntasTag;
	for (size_t i = 0; i < preguntas.size(); ++i) {
		if (preguntas[i]->getTag() == tag) {
			preguntasTag.push_back(preguntas[i]);
		}
	}
	return preguntasTag;
}


void Sistema::revisarFecha(){

	Fecha fechaActual;
	for (size_t i = 0; i < preguntas.size(); ++i) {

		if(fechaActual-preguntas[i]->ultimaRespuesta>183){
			preguntas[i]->cambiarEstado(new Inactiva);
		}
	}
}
