
#ifndef ESTADO_H_
#define ESTADO_H_
#include "Usuario.h"

		//------------CLASE PADRE "ESTADO"-------------------
class Estado {
public:
	Estado();
	virtual ~Estado();
	Estado(const Estado &other);
	virtual bool puedeRecibirRespuesta();
	virtual string getEstado() {
		return "";
	};
	virtual bool notificar() {
		return true;
	};
};


		//------------CLASE HIJA: "ACTIVA"-------------------
class Activa : public Estado {
public:
	bool puedeRecibirRespuesta();
	string getEstado() {
		return "Activa";
	};
	bool notificar() {
		return true;
	};
};


		//------------CLASE HIJA: "INACTIVA"-------------------

class Inactiva : public Estado {
public:
	bool puedeRecibirRespuesta();
	string getEstado() {
		return "Inactiva";
	};
	bool notificar() {
		return true;
	};
};


		//------------CLASE HIJA: "SUSPENDIDA"-------------------

class Suspendida : public Estado {
public:
	bool puedeRecibirRespuesta();
	string getEstado()  {
		return "Suspendida";
	};
	bool notificar() {
		return false;
	}
};

//------------CLASE HIJA: "SOLUCIONADA"-------------------

class Solucionada : public Estado {
public:
	bool puedeRecibirRespuesta();
	string getEstado()  {
		return "Solucionada";
	};
	bool notificar() {
		return false;
	}
};
#endif /* ESTADO_H_ */

