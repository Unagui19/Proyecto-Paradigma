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

class Pregunta {
private:
	int static codigo;
	string titulo;
	string descripcion;
	string tags;
	Imagen imagen;
	Fecha fechaCreacion;
	Fecha ultimaRespuesta;
	vector<Respuesta*> respuestas;
	Usuario usuario;
	Estado* estadoActual;
	void guardarRespuesta(Respuesta*);
public:
	Pregunta();
	Pregunta(string, string, string, Imagen, Fecha, Usuario);
	virtual ~Pregunta();
	Pregunta(const Pregunta &other);
	void crearRespuesta(string, Fecha, Usuario, Imagen);
	void cambiarEstado(Estado* nuevoEstado);
	void mostrarRespuesta(int idResp);
	void listarInfo();

};

#endif /* PREGUNTA_H_ */
