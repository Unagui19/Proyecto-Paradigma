#ifndef ESTADOINACTIVA_H
#define ESTADOINACTIVA_H

#include <iostream>
#include "Estado.h"
using namespace std;

class EstadoInactiva : public Estado
{
private:
    /* data */
public:
    EstadoInactiva(/* args */){
        // 
    }
    
    ~EstadoInactiva(){
        // 
    }

    void mostrarEstado() const override {
        cout << "Pregunta inactiva" << endl;
    }

    bool puedeRecibirRespuesta() const override {
	    return true;
    }
};

#endif