/*
 * Estado.cpp
 *
 *  Created on: 3 nov. 2023
 *      Author: Alumno
 */

#include "Estado.h"

Estado::Estado() {
	// TODO Auto-generated constructor stub

}

Estado::~Estado() {
	// TODO Auto-generated destructor stub
}

Estado::Estado(const Estado &other) {
	// TODO Auto-generated constructor stub

}


		//------------CLASE PADRE "ESTADO"-------------------

bool Estado::puedeRecibirRespuesta(){
	return true;
}


		//------------CLASES HIJAS-------------------

bool Activa::puedeRecibirRespuesta() {
	return true;
}

bool Inactiva::puedeRecibirRespuesta() {
	return true;
}

bool Solucionada::puedeRecibirRespuesta() {
	 return false;
}

bool Suspendida::puedeRecibirRespuesta() {
	return true;
}
