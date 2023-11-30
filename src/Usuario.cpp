/*
 * Usuario.cpp
 *
 *  Created on: 3 nov. 2023
 *      Author: Alumno
 */

#include "Usuario.h"
#include "Sistema.h"

		//-------------CONSTRUCTORES Y DESTRUCTOR-------------------
Usuario::Usuario() {
	// TODO Auto-generated constructor stub

}

Usuario::Usuario(string nom, string ape, string em, string con, string po, string ni, Sistema* sis) {
	codigo++;
	sistema = sis;
	nombre = nom;
	apellido = ape;
	email = em;
	contrasenia = con;
	paisOrigen = po;
	nick = ni;
	respAceptadas = 0;
	notificaciones = 0;
}

int Usuario::codigo = 0;

Usuario::~Usuario() {
	// TODO Auto-generated destructor stub
}

Usuario::Usuario(const Usuario &other) {
	// TODO Auto-generated constructor stub

}


		//------------OTROS METODOS-------------------

void Usuario::notificar() {
	notificaciones++;
}

void Usuario::hacerPregunta() {
	string titulo, descripcion, tag;
	cout << "Titulo:" << endl;
	cin >> titulo;
	cout << "Descripcion:" << endl;
	cin >> descripcion;
	cout << "Etiqueta:" << endl;
	cin >> tag;
	cout << "Desea agregar una imagen? (Presione 1 si asi lo desea)" << endl;
	int op;
	cin >> op;
	Imagen imagen;
	if (op == 1) {
		string tituloIMG, archivoIMG, descripcionIMG;
		cout << "Titulo:" << endl;
		cin >> tituloIMG;
		cout << "Descripcion:" << endl;
		cin >> descripcionIMG;
		cout << "Archivo:" << endl;
		cin >> archivoIMG;
		imagen = Imagen(tituloIMG, archivoIMG, descripcionIMG);
	}
	sistema->crearPregunta(titulo, descripcion, tag, imagen, Fecha(), this);
}

void Usuario::responderPregunta(int idPregunta) {
	string titulo, descripcion;
	cout << "Titulo:" << endl;
	cin >> titulo;
	cout << "Descripcion:" << endl;
	cin >> descripcion;
	cout << "Desea agregar una imagen? (Presione 1 si asi lo desea)" << endl;
	int op;
	cin >> op;
	Imagen imagen;
	if (op == 1) {
		string tituloIMG, archivoIMG, descripcionIMG;
		cout << "Titulo:" << endl;
		cin >> tituloIMG;
		cout << "Descripcion:" << endl;
		cin >> descripcionIMG;
		cout << "Archivo:" << endl;
		cin >> archivoIMG;
		imagen = Imagen(tituloIMG, archivoIMG, descripcionIMG);
	}
	sistema->crearRespuesta(titulo, Fecha(), this, imagen, idPregunta);
}


void Usuario::eliminarCuenta() {
	cout << "Desea eliminar su cuenta? (Si [1], No [2])" << endl;
	int op;
	cin >> op;
	if (op == 1) {
		sistema->borrarUsuario(this);
		return;
	}
	cout << "Accion cancelada" << endl;
}

void Usuario::listarInfo(){
	cout << "Usuario: " << codigo  << "   Nick" << nick << endl;
	cout <<"Nombre: " << apellido << ", " << nombre << "   Foto: "<< foto.getImagen() << endl;
	cout <<"País: " << paisOrigen << "\nEmail: " << email  << endl;
	cout <<"Respuestas Aceptadas: " << this->getRespAcep() << "   Notificaciones: " << notificaciones << endl;
}
void Usuario::aceptarRespuesta(int idPreg, int idResp){
	Pregunta* pregunta = sistema->buscarPreguntaPorId(idPreg);
	Respuesta* respuesta = pregunta->buscarRespuestaPorId(idResp);
	respuesta->aceptar();
}

