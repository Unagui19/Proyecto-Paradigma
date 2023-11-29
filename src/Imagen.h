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
	//string archivo;//que es archivo?
public:
	Imagen();
	Imagen(string titulo, string descripcion);
	virtual ~Imagen();
	Imagen(const Imagen &other);
	//const string& getArchivo() const;
	const string& getDescripcion() const;
	const string& getTitulo() const;
};

#endif /* IMAGEN_H_ */
