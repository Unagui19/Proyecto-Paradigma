/*
 * Imagen.cpp
 *
 *  Created on: 3 nov. 2023
 *      Author: Alumno
 */

#include "Imagen.h"
#include <string>
#include <iostream>

Imagen::Imagen() {
	// TODO Auto-generated constructor stub

}

Imagen::Imagen(string tit, string arch, string desc) {
	titulo = tit;
	archivo = arch;
	descripcion = desc;
}

Imagen::~Imagen() {
	// TODO Auto-generated destructor stub
}

Imagen::Imagen(const Imagen &other) {
	// TODO Auto-generated constructor stub

}
string Imagen::getImagen(){
	string txt = "Imagen: ";
	txt.append(this->titulo);
	return txt;
}
