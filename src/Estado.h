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
	virtual bool notificar() {
		return true;
	};
};

class Activa : public Estado {
public:
	bool puedeRecibirRespuesta();
	void mostrarEstado() {
		cout << "Activa" << endl;
	};
	bool notificar() {
		return true;
	};
};

class Inactiva : public Estado {
public:
	bool puedeRecibirRespuesta();
	void mostrarEstado() {
		cout << "Inactiva" << endl;
	};
	bool notificar() {
		return true;
	};
};

class Solucionada : public Estado {
public:
	bool puedeRecibirRespuesta();
	void mostrarEstado()  {
		cout << "Solucionada" << endl;
	};
	bool notificar() {
		return false;
	}
};

class Suspendida : public Estado {
public:
	bool puedeRecibirRespuesta();
	void mostrarEstado()  {
		cout << "Suspendida" << endl;
	};
	bool notificar() {
		return false;
	}
};

#endif /* ESTADO_H_ */

