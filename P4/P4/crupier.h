#ifndef CRUPIER_H
#define CRUPIER_H

#include "persona.h"
#include <string>

using namespace std;
//Archivo crupier.h

//En este archivo declaramos la clase crupier que hereda de la clase persona


/* La clase crupier, que hereda de persona, representa al crupier de una mesa*/

class Crupier : public Persona {
	
private:
	string _codigo;
	
public:
	//Constructor
	Crupier(string code, string dni, string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="", string pais="");
	string getCodigo();
	void setCodigo(string code);
	
	
};

#endif
