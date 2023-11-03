/*
 * Imagen.h
 *
 *  Created on: 3 nov. 2023
 *      Author: Alumno
 */

#ifndef IMAGEN_H_
#define IMAGEN_H_
#include <iostream>
using namespace std;

class Imagen {
private:
	string titulo;
	string descripcion;
	string archivo;
public:
	Imagen();
	virtual ~Imagen();
	Imagen(const Imagen &other);
};

#endif /* IMAGEN_H_ */
