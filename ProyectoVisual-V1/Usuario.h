// usuario.h
#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
using namespace std;

class Usuario
{
private:
    int id;
    string nombre;
    
public:
    Usuario(string _nombre, int _id) : 
    nombre(_nombre), id(_id) {}

    ~Usuario(){
        // 
    }

    int GetId(){
        return id;
    }

    string GetNombre(){
        return nombre;
    }

    // // m de sistema
    // void eliminarCuenta()
    // {
    //     // Cambiar el estado de todas las preguntas asociadas al usuario a "suspendida"
    //     for (Pregunta *pregunta : ListaPreguntas)
    //     {
    //         pregunta->cambiarEstado(new EstadoSuspendida());
    //     }
    //     // Limpiar la lista de preguntas
    //     ListaPreguntas.clear();
    //     cout << "La cuenta del usuario ha sido eliminada, y sus preguntas asociadas han sido suspendidas." << endl;
    // }
    
};

#endif