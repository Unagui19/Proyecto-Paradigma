#ifndef ESTADOSOLUCIONADA_H
#define ESTADOSOLUCIONADA_H

#include <iostream>
#include "Estado.h"
using namespace std;

class EstadoSolucionada: public Estado
{
private:
    // ...
public:
    EstadoSolucionada(/* args */){
        // 
    }

    ~EstadoSolucionada(){
        // 
    }

    void mostrarEstado() const override {
        cout << "Pregunta solucionada" << endl;
    }

    bool puedeRecibirRespuesta() const override {
	    return false;
    }
};

#endif