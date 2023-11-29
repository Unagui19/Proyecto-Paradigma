/*
 * Imagen.cpp
 *
 *  Created on: 3 nov. 2023
 *      Author: Alumno
 */

#include "Imagen.h"

Imagen::Imagen() {
	// TODO Auto-generated constructor stub

}

Imagen::~Imagen() {
	// TODO Auto-generated destructor stub
}

//const string& Imagen::getArchivo() const {
//	return archivo;
//}

const string& Imagen::getDescripcion() const {
	return descripcion;
}

Imagen::Imagen(string titulo, string descripcion) {
	this->titulo=titulo;
	this->descripcion=descripcion;
}

const string& Imagen::getTitulo() const {
	return titulo;
}

Imagen::Imagen(const Imagen &other) {
	// TODO Auto-generated constructor stub

}

