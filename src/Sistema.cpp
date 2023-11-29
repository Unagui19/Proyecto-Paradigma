/*
 * Sistema.cpp
 *
 *  Created on: 3 nov. 2023
 *      Author: Alumno
 */
#include <iostream>
using namespace std;
#include "Sistema.h"
#include "Pregunta.h"
#include "Imagen.h"
#include "Fecha.h"
#include "Respuesta.h"
#include <vector>
#include <iterator>

Sistema::Sistema() {
	// TODO Auto-generated constructor stub

}

Sistema::~Sistema() {
	// TODO Auto-generated destructor stub
}

Sistema::Sistema(const Sistema &other) {
	// TODO Auto-generated constructor stub

}

void Sistema::mostrarListadoPreguntas(){
	for (int i = 0; i < preguntas.size(); ++i) {
			preguntas[i].listarInfo();
	}

}

void Sistema::mostrarPregunta(int codPregunta){
	bool flag=false;
	for (int i = 0; i < preguntas.size(); ++i) {
		if (codPregunta==preguntas[i].codigo) {
			preguntas[i].listarInfo();
			flag=true;
			break;
		}
	}
	if (flag==false) {
		cout<<"No hay pregunta con el codigo: "<<codPregunta<<endl;
	}

}

void Sistema::borrarUsuario(int idUsu){
	bool flag=false;
	Usuario usuABorrar;
	for (int i = 0; i < usuarios.size(); ++i) {
		if (idUsu==usuarios[i].id) {
			usuABorrar=usuarios[i];
			flag=true;
			break;
		}
	}
	if (flag==false) {
		cout<<"No hay usuario con el id: "<<idUsu<<endl;
	}
	else{
		usuABorrar.eliminarCuenta(idUsu);
	}
}

void Sistema:: mostrarUsuario(int idUsu){
	bool flag=false;
	for (int i = 0; i < usuarios.size(); ++i) {
		if (idUsu==usuarios[i].id) {
			usuarios[i].listarInfo();
			flag=true;
			break;
		}
	}
	if (flag==false) {
		cout<<"No hay usuario con el id: "<<idUsu<<endl;
	}
}

void Sistema:: rankingUsuarios(){
	for (int i = 0; i < usuarios.size(); ++i) {
			usuarios[i].listarInfo();
	}
};

void Sistema::crearPregunta(string allocator, string allocator1,
		Imagen imagen) {
//	Pregunta nuevaPregunta( nombre, apellido, email, contra, paisO,  nick);
//	usuarios.push_back(nuevoUsuario);
}

void Sistema::crearUsuario(string nombre, string apellido, string email, string contra,
		string paisO, string nick){
	//int static codigo;
	Usuario nuevoUsuario( nombre, apellido, email, contra, paisO,  nick);
	usuarios.push_back(nuevoUsuario);

}

vector<Pregunta> Sistema:: buscarPreguntaPorTags(string tag){
	bool flag=false;
	vector<Pregunta> aux;
	for (int i = 0; i < preguntas.size(); ++i) {
		if (tag==preguntas[i].tags) {
			preguntas[i].listarInfo();
			aux.push_back(preguntas[i]);
			flag=true;
		}
	}

	if(flag==false){
		cout<<"No existe pregunta con el tag: "<<tag<<endl;
		return NULL;
	}
	else
	{
		return aux;
	}
}


