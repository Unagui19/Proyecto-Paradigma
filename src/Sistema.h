
#ifndef SISTEMA_H_
#define SISTEMA_H_
#include <iostream>
using namespace std;
#include "Usuario.h"
#include "Pregunta.h"

class Sistema {
private:
	vector<Usuario*> usuarios;
	vector<Pregunta*> preguntas;
	void guardarUsuario(Usuario*);
	void guardarPregunta(Pregunta*);
public:
	Sistema();
	Sistema(const Sistema &other);
	virtual ~Sistema();

	void crearUsuario(string, string, string, string, string, string);
	Usuario* buscarUsuarioPorId(int);
	void rankingUsuario();
	void borrarUsuario(Usuario*);
	void mostrarUsuario(int);

	void crearRespuesta(string, Fecha, Usuario*, Imagen, int);
	void crearPregunta(string, string, string, Imagen, Fecha, Usuario*);
	void mostrarPregunta(int);
	vector<Pregunta*> buscarPreguntasPorTag(string);
	Pregunta* buscarPreguntaPorId(int);
	void listarPreguntas();
	void revisarFecha();
};

#endif /* SISTEMA_H_ */
