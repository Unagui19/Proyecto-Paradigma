#ifndef ESTADO_H
#define ESTADO_H

#include <iostream>
using namespace std;

class Estado
{
private:
    /* data */
public:
    Estado(/* args */){

    }

    virtual ~Estado() {}

    virtual void mostrarEstado() const = 0;

    virtual bool puedeRecibirRespuesta() const =0;
  
};

#endif