// sistema.h
#include <iostream>
#include <vector>
#include "Pregunta.h"
#include "Usuario.h"
using namespace std;

class Sistema
{
private:
    vector <Pregunta*> ListaPreguntas;
    vector <Usuario*> ListaUsuarios;
    
public:
    Sistema(){

    }

    ~Sistema(){

    }

    // Método para crear un usuario y agregarlo a la lista
    void crearUsuario(string nombre, int id) {
        Usuario* nuevoUsuario = new Usuario(nombre, id);
        ListaUsuarios.push_back(nuevoUsuario);
    }

    void crearPregunta(int cod_pregunta, Usuario* usuario, string titulo, string descripcion) {
        Pregunta* nuevaPregunta = new Pregunta(cod_pregunta, usuario, titulo, descripcion);
        ListaPreguntas.push_back(nuevaPregunta);
    }


    Usuario* obtenerUsuarioPorID(int id) {
        for (Usuario* usuario : ListaUsuarios) {
            if (usuario->GetId() == id) {
                return usuario;
            }
        }
        // Devolver nullptr si no se encuentra el usuario
        return nullptr;
    }

    Pregunta* obtenerPreguntaPorCodigo(int codigo) {
        for (Pregunta* pregunta : ListaPreguntas) {
            if (pregunta->GetCod() == codigo) {
                return pregunta;
            }
        }
        // Devolver nullptr si no se encuentra la pregunta
        return nullptr;
    }

    vector<Usuario*> obtenerListadoUsuarios() const {
        return ListaUsuarios;
    }

    vector<Pregunta*> obtenerListadoPreguntas() const {
        return ListaPreguntas;
    }

};

