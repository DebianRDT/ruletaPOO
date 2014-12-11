#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>
//Archivo persona.h

//En este archivo declaramos la clase persona


/*Clase persona, de la cual heredan jugador y crupier, esta clase representa a todas las personas implicadas en el
 *juego de la ruleta*/

using namespace std;


class Persona {
	
private:
	string _dni, _nombre, _apellidos, _direccion, _localidad, _provincia, _pais;
	
public:
	//Constructor
	Persona(string dni, string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="", string pais="");


	void setDNI(string dni);
	string getDNI();
	void setNombre(string nombre);
	string getNombre();
	void setApellidos(string apellidos);
	string getApellidos();
	void setDireccion(string direccion);
	string getDireccion();
	void setLocalidad(string localidad);
	string getLocalidad();
	void setProvincia(string provincia);
	string getProvincia();
	void setPais(string pais);
	string getPais();
	string getApellidosyNombre();
};

#endif
