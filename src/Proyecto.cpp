//============================================================================
// Name        : Proyecto.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Sistema.h"

int main() {
	Sistema sistema;
	Usuario usu1;
	sistema.crearUsuario("Franco", "Rodriguez Romano", "frodriguez@gmail.com", "soyfranquitouwu", "Argentina", "Unagui19");
	sistema.buscarUsuarioPorId(1)->hacerPregunta();
	sistema.buscarUsuarioPorId(1)->hacerPregunta();
	sistema.listarPreguntas();
	sistema.crearUsuario("Marcelo", "Kahedera", "marKaher@gmail.com", "adafqwqdf", "Argentina", "Kahecelo");
	sistema.buscarUsuarioPorId(1)->listarInfo();
	sistema.buscarUsuarioPorId(2)->listarInfo();
	sistema.buscarUsuarioPorId(2)->hacerPregunta();
	sistema.buscarUsuarioPorId(2)->responderPregunta(2);
	sistema.buscarUsuarioPorId(1)->aceptarRespuesta(2, 1);
	sistema.rankingUsuario();
	sistema.listarPreguntas();
	sistema.buscarUsuarioPorId(2)->eliminarCuenta();
	sistema.rankingUsuario();
	sistema.listarPreguntas();
	return 0;
}

//sistema
//sistema.crearus(us1)
//us1.hacerpreg()
//sistema.crearpreg(..., usu1)
