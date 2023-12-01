/*
 * Pregunta.h
 *
 *  Created on: 3 nov. 2023
 *      Author: Alumno
 */

#ifndef PREGUNTA_H_
#define PREGUNTA_H_
#include <vector>
#include "Respuesta.h"
#include "Estado.h"
#include "Usuario.h"

class Pregunta {
private:
	int static codigo;
	int id;
	string titulo;
	string descripcion;
	string tags;
	Imagen imagen;
	Fecha fechaCreacion;
	Fecha* ultimaRespuesta;
	vector<Respuesta*> respuestas;
	Usuario* usuario;
	Estado* estadoActual;
	void guardarRespuesta(Respuesta*);
	Respuesta* buscarRespuestaPorId(int);
public:
	Pregunta();
	Pregunta(string, string, string, Imagen, Fecha, Usuario*);
	virtual ~Pregunta();
	Pregunta(const Pregunta &other);
	void crearRespuesta(string, Fecha, Usuario*, Imagen);
	void cambiarEstado(Estado*);
	void rankingRespuestas();
	void listarInformacion();
	void mostrarRespuesta(int);
	int getId() {
		return id;
	};
	void aceptarRespuesta(int);
	string getTag() {
		return tags;
	};
	string getTitulo() {
		return titulo;
	};
	string getDescripcion() {
		return descripcion;
	};
	Fecha* getUltimaRespuesta() {
		return ultimaRespuesta;
	};
	Usuario* getUsuario() {
		return usuario;
	};
	string getEstadoActual(){
		return estadoActual->getEstado();
	};
};

#endif /* PREGUNTA_H_ */
