/*
 * Respuesta.cpp
 *
 *  Created on: 3 nov. 2023
 *      Author: Alumno
 */

#include "Respuesta.h"

Respuesta::Respuesta() {
	// TODO Auto-generated constructor stub

}

Respuesta::Respuesta(string desc, Fecha fec, Usuario* usu, Imagen img) {
	respuesta = desc;
	fecha = fec;
	usuario = usu;
	imagen = img;
	codigo++;
	idResp=codigo;
	cantMg = 0;
	aceptada = false;
}

int Respuesta::codigo = 0;

Respuesta::~Respuesta() {
	// TODO Auto-generated destructor stub
}

Respuesta::Respuesta(const Respuesta &other) {
	// TODO Auto-generated constructor stub

}

void Respuesta::darMg() {
	cantMg++;
}

bool Respuesta::estaAceptada() {
	return aceptada;
}

void Respuesta::aceptar() {
	aceptada = true;
}

bool Respuesta::isAceptada() const {
	return aceptada;
}


//-----------Getters y Setters--------------

void Respuesta::setAceptada(bool aceptada) {
	this->aceptada = aceptada;
}

int Respuesta::getCantMg() const {
	return cantMg;
}

void Respuesta::setCantMg(int cantMg) {
	this->cantMg = cantMg;
}

int Respuesta::getIdResp() const {
	return idResp;
}



const Imagen& Respuesta::getImagen() const {
	return imagen;
}



const string& Respuesta::getRespuesta() const {
	return respuesta;
}


void Respuesta::listarInfo() {
	cout << "Respuesta: "<< respuesta << "\n Imagen: " << imagen.getImagen() << endl;
	cout << "Fecha: " << fecha << "   Usuario: " << usuario << endl;
	cout << "Cantidad de Me Gusta: " << getCantMg() << "Esta Aceptada: " << isAceptada() << endl;
}
