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

Respuesta::Respuesta(string desc, Fecha fec, Usuario usu, Imagen img) {
	respuesta = desc;
	fecha = fec;
	usuario = usu;
	imagen = img;
	codigo++;
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

int Respuesta::getMG(){
	return cantMg;
};
