#include <iostream>
#include "Sistema.h"
#include "Usuario.h"
#include "Pregunta.h"
#include "Respuesta.h"
using namespace std;

int main() {
    // Crear un sistema
    Sistema sistema;

    // Crear usuarios
    sistema.crearUsuario("Usuario1", 1);
    sistema.crearUsuario("Usuario2", 2);

    // Crear preguntas con respuestas
    sistema.crearPregunta(1, sistema.obtenerUsuarioPorID(1), "Pregunta 1", "Descripción Pregunta 1");
    sistema.crearPregunta(2, sistema.obtenerUsuarioPorID(2), "Pregunta 2", "Descripción Pregunta 2");

    // Obtener la primera pregunta creada
    // Pregunta* pregunta1 = sistema.getListaPreguntas()[0];

    // Crear respuestas para la primera pregunta
    // Realizar correcciones
    // que se esta haciendo aqui
    sistema.obtenerPreguntaPorCodigo(1)->agregarRespuesta(new Respuesta(sistema.obtenerUsuarioPorID(1), "Respuesta 1")); //corregir

    sistema.obtenerPreguntaPorCodigo(1)->agregarRespuesta(new Respuesta(sistema.obtenerUsuarioPorID(1), "Respuesta 2"));

    sistema.obtenerPreguntaPorCodigo(2)->agregarRespuesta(new Respuesta(sistema.obtenerUsuarioPorID(1), "Respuesta 1")); //corregir

    sistema.obtenerPreguntaPorCodigo(2)->agregarRespuesta(new Respuesta(sistema.obtenerUsuarioPorID(2), "Respuesta 2"));


    //------------Mostrar información--------------
    // Realizar metodos individuales

    cout << "Usuarios creados:" << endl;
    for (Usuario* usuario : sistema.obtenerListadoUsuarios()) {
        cout << "ID: " << usuario->GetId() << ", Nombre: " << usuario->GetNombre()<< endl;
    }

    cout << "\nPreguntas creadas:" << endl;
    for (Pregunta* pregunta : sistema.obtenerListadoPreguntas()) {
        cout << "Título: " << pregunta->GetTitulo() << ", Descripción: " << pregunta->GetTitulo() << endl;
        cout << "Respuestas:" << endl;
        for (Respuesta* respuesta : pregunta->obtenerListadoRespuestas()) {
            cout << "- " << respuesta->GetDescripcion() << ", Usuario: " << respuesta->GetUsuario()->GetNombre() << endl;
        }
    }

    // Liberar memoria
    return 0;
}
