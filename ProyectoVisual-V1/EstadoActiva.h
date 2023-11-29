#ifndef ESTADOACTIVA_H
#define ESTADOACTIVA_H

#include <iostream>
#include "Estado.h"
using namespace std;

class EstadoActiva : public Estado
{
private:
    /* data */
public:
    EstadoActiva(/* args */){
        // 
    }
    
    ~EstadoActiva(){

    }

    void mostrarEstado() const override {
        cout << "Pregunta activa" << endl;
    }

    bool puedeRecibirRespuesta() const override {
	    return true;
    }
    
};

#endif

