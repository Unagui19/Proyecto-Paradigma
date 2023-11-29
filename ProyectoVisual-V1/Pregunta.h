// pregunta.h
#ifndef PREGUNTA_H
#define PREGUNTA_H

#include <iostream>
#include <vector>
#include "Respuesta.h"
#include "Usuario.h"
#include "Estado.h"
#include "EstadoActiva.h"
#include "EstadoInactiva.h"
#include "EstadoSolucionada.h"
#include "EstadoSuspendida.h"

#include <time.h>

using namespace std;

class Pregunta
{
private:
    int cod_pregunta;
    string titulo;
    string descripcion;
    vector<Respuesta *> ListaRespuestas;
    Usuario *usuario;
    Estado *estado;
    time_t fechaCreacion;

public:
    Pregunta(int cod_pregunta, Usuario *_usuario, string _titulo, string _descripcion) : cod_pregunta(cod_pregunta), usuario(_usuario), titulo(_titulo), descripcion(_descripcion)
    {
        estado = new EstadoActiva();
        fechaCreacion = time(0);
    }

    ~Pregunta()
    {
        //
    }

    // void crearRespuesta(Usuario *usuario, string descripcion)
    // {
    //     Respuesta *nuevaRespuesta = new Respuesta(usuario, descripcion);
    //     ListaRespuestas.push_back(nuevaRespuesta);
    // }

    void crearRespuesta(Usuario *usuario, string descripcion)
    {
        // Verificar si la pregunta está en un estado que permite agregar respuestas
        bool Permiso = obtenerEstado()->puedeRecibirRespuesta();
        
        if (Permiso)
        {
            Respuesta *nuevaRespuesta = new Respuesta(usuario, descripcion);
            ListaRespuestas.push_back(nuevaRespuesta);
            cout << "Respuesta agregada exitosamente." << endl;
        }
        else
        {
            cout << "No se puede agregar una respuesta en el estado actual de la pregunta." << endl;
        }
    }

    // quien la crea?
    // void agregarRespuesta(Respuesta *nuevaRespuesta)
    // {
    //     ListaRespuestas.push_back(nuevaRespuesta);
    // }

    int GetCod()
    {
        return cod_pregunta;
    }

    string GetTitulo()
    {
        return titulo;
    }

    string GetDescripcion()
    {
        return descripcion;
    }

    // Método para obtener un listado de respuestas
    vector<Respuesta *> obtenerListadoRespuestas() const
    {
        return ListaRespuestas;
    }

    // ----------- Estados ----------- 

    void cambiarEstado(Estado *nuevoEstado)
    {
        delete estado;        // Liberamos la memoria del estado actual
        estado = nuevoEstado; // Asignamos el nuevo estado
    }

    void mostrarEstado() const
    {
        estado->mostrarEstado();
    }

    Estado* obtenerEstado(){
        return estado;
    }

    // cambiar estados

    void activarPregunta()
    {
        cambiarEstado(new EstadoActiva());
    }

    // Cambiar el estado de la pregunta a inactiva
    void desactivarPregunta()
    {
        cambiarEstado(new EstadoInactiva());
    }

    void suspenderPregunta()
    {
        cambiarEstado(new EstadoSuspendida);
    }

    void solucionarPregunta()
    {
        cambiarEstado(new EstadoSolucionada());
    }

};

#endif