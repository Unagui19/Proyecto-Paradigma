/*
 * Estado.h
 *
 *  Created on: 3 nov. 2023
 *      Author: Alumno
 */

#ifndef ESTADO_H_
#define ESTADO_H_
#include "Usuario.h"

class Estado {
public:
	Estado();
	virtual ~Estado();
	Estado(const Estado &other);
	virtual bool puedeRecibirRespuesta();
	virtual void mostrarEstado();
};

class Activa : public Estado {
public:
	bool puedeRecibirRespuesta();
	void mostrarEstado() {
		cout << "Activa" << endl;
	};
};

class Inactiva : public Estado {
public:
	bool puedeRecibirRespuesta();
	void mostrarEstado() {
		cout << "Inactiva" << endl;
	};
};

class Solucionada : public Estado {
public:
	bool puedeRecibirRespuesta();
	void mostrarEstado()  {
		cout << "Solucionada" << endl;
	};
};

class Suspendida : public Estado {
public:
	bool puedeRecibirRespuesta();
	void mostrarEstado()  {
		cout << "Suspendida" << endl;
	};
};

#endif /* ESTADO_H_ */

