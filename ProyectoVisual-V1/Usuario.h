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
    
};

#endif