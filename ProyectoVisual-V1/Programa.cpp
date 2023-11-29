#include <iostream>
#include "Sistema.h"
#include "Usuario.h"
#include "Pregunta.h"
#include "Respuesta.h"

#include "Estado.h"
#include "EstadoActiva.h"
#include "EstadoInactiva.h"
// #include "EstadoSolucionada.h"
// #include "EstadoSuspendida.h"
using namespace std;

int main() {
    // ---------Crear un sistema----------
    Sistema sistema;

    // -----Estados------

    EstadoActiva estadoActiva;
    EstadoInactiva estadoInactiva;

    Estado& estado1 = estadoActiva;
    Estado& estado2 = estadoInactiva;

    // Crear usuarios
    sistema.crearUsuario("Usuario1", 1);
    sistema.crearUsuario("Usuario2", 2);

    // ----------Crear preguntas-----------
    sistema.crearPregunta(1, sistema.obtenerUsuarioPorID(1), "Pregunta 1", "Descripción Pregunta 1");
    sistema.crearPregunta(2, sistema.obtenerUsuarioPorID(2), "Pregunta 2", "Descripción Pregunta 2");

    // Dprueva
    sistema.crearPregunta(3, sistema.obtenerUsuarioPorID(2), "Pregunta 3", "Descripción Pregunta 3");

    // test

    sistema.obtenerPreguntaPorCodigo(1)->mostrarEstado();
    sistema.obtenerPreguntaPorCodigo(1)->solucionarPregunta(); // estado solucionada
    sistema.obtenerPreguntaPorCodigo(1)->mostrarEstado();

    // ---------------Crear respuestas---------------
    // sistema.obtenerPreguntaPorCodigo(1)->agregarRespuesta(new Respuesta(sistema.obtenerUsuarioPorID(1), "Respuesta 1")); //corregir
    // sistema.obtenerPreguntaPorCodigo(1)->agregarRespuesta(new Respuesta(sistema.obtenerUsuarioPorID(1), "Respuesta 2"));
    // sistema.obtenerPreguntaPorCodigo(2)->agregarRespuesta(new Respuesta(sistema.obtenerUsuarioPorID(1), "Respuesta 1")); //corregir
    // sistema.obtenerPreguntaPorCodigo(2)->agregarRespuesta(new Respuesta(sistema.obtenerUsuarioPorID(2), "Respuesta 2"));

    sistema.obtenerPreguntaPorCodigo(1)->crearRespuesta(sistema.obtenerUsuarioPorID(1), "Respuesta 1");
    sistema.obtenerPreguntaPorCodigo(1)->crearRespuesta(sistema.obtenerUsuarioPorID(1), "Respuesta 2");
    sistema.obtenerPreguntaPorCodigo(2)->crearRespuesta(sistema.obtenerUsuarioPorID(1), "Respuesta 1"); //corregir
    sistema.obtenerPreguntaPorCodigo(2)->crearRespuesta(sistema.obtenerUsuarioPorID(2), "Respuesta 2");

    //------------Mostrar información--------------
    // Realizar metodos individuales

    cout << "-------Usuarios creados:-----------" << endl;
    for (Usuario* usuario : sistema.obtenerListadoUsuarios()) {
        cout << "ID: " << usuario->GetId() << ", Nombre: " << usuario->GetNombre()<< endl;
    }

    cout << "\n--------------Preguntas creadas:---------" << endl;
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
