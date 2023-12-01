
#ifndef IMAGEN_H_
#define IMAGEN_H_
#include <iostream>
using namespace std;

class Imagen {
private:
	string titulo;
	string descripcion;
	string archivo;
public:
	Imagen();
	Imagen(string, string, string);
	Imagen(const Imagen &other);
	virtual ~Imagen();
	string getImagen();
};

#endif /* IMAGEN_H_ */
