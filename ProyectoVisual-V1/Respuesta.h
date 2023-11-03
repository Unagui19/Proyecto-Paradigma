// respuesta.h
#ifndef RESPUESTA_H
#define RESPUESTA_H

#include <iostream>
#include <time.h>
#include "Usuario.h"
using namespace std;

class Respuesta
{
private:
    int codigo;
    string descripcion;
    Usuario *usuario;
    time_t fecha;

public:
    Respuesta(Usuario *usuario, string descripcion) :  
    usuario(usuario), descripcion(descripcion){
        fecha = time(0); // Fecha actual
    }

    ~Respuesta(){
        // 
    }

    int GetCodigo(){
        return codigo;
    }

    string GetDescripcion(){
        return descripcion;
    }

    Usuario* GetUsuario(){
        return usuario;
    }

};

#endif
