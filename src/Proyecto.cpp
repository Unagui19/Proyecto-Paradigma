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
	return 0;
}

//sistema
//sistema.crearus(us1)
//us1.hacerpreg()
//sistema.crearpreg(..., usu1)
