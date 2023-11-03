// pregunta.h
#ifndef PREGUNTA_H
#define PREGUNTA_H

#include <iostream>
#include <vector>
#include "Respuesta.h"
#include "Usuario.h"
#include "Estado.h"

#include <time.h>

using namespace std;


class Pregunta
{
private:
    int cod_pregunta;
    string titulo;
    string descripcion;
    vector <Respuesta*> ListaRespuestas;
    Usuario *usuario;
    time_t fechaCreacion;
public:
    Pregunta(int cod_pregunta ,Usuario *_usuario, string _titulo, string _descripcion) : 
    cod_pregunta(cod_pregunta), usuario(_usuario), titulo(_titulo), descripcion(_descripcion) {
        // estado = ACTIVA;
        fechaCreacion = time(0); 
    }
    
    ~Pregunta(){
        // 
    }

    // quien la crea?
    void agregarRespuesta(Respuesta* nuevaRespuesta) {
        // crear
        ListaRespuestas.push_back(nuevaRespuesta);
    }

    int GetCod(){
        return cod_pregunta;
    }

    string GetTitulo(){
        return titulo;
    }

    string GetDescripcion(){
        return descripcion;
    }

    // Método para obtener un listado de respuestas
    vector<Respuesta*> obtenerListadoRespuestas() const {
        return ListaRespuestas;
    }



};

#endif