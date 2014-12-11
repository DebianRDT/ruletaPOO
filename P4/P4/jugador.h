#ifndef JUGADOR_H
#define JUGADOR_H

//Archivo jugador.h

#include "persona.h"
#include "apuestas.h"
#include <string>
#include <list>


/* Clase jugador, que hereda de persona, representa a cada jugador que participa en el juego de la ruleta. Jugador es aquel
 *que apuesta dinero a unas determinadas condiciones*/


class Jugador : public Persona {
	
private:
	int _dinero;
	string _codigo;
	list<Apuestas> _apuestas;
	
	
	
public:
	//Constructor
	Jugador(string code, string dni, string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="", string pais="");
	
	//Metodos
	int getDinero();
	void setDinero(int cantidad);
	string getCodigo();
	void setCodigo(string code);
	list<Apuestas> getApuestas();
	void setApuestas(string dni);
	
	
};


#endif
