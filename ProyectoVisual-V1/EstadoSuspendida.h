#ifndef ESTADOSUSPENDIDA_H
#define ESTADOSUSPENDIDA_H

#include <iostream>
#include "Estado.h"
using namespace std;

class EstadoSuspendida : public Estado
{
private:
    /* data */
public:
    EstadoSuspendida(/* args */){
        // 
    }

    ~EstadoSuspendida(){
        // 
    }

    void mostrarEstado() const override {
        cout << "Pregunta suspendida" << endl;
    }

    bool puedeRecibirRespuesta() const override {
	    return true;
    }
};

#endif