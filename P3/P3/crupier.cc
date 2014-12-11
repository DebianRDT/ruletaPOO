#include <iostream>
#include "crupier.h"
#include "persona.h"
#include <ctime>
#include <cstdlib>
#include <string>



/**
 * --------------------------------------
 * Programa creado por Debian@Linceus.es
 * --------------------------------------
 * 
 */

using namespace std;


//Constructor de la clase crupier

Crupier::Crupier(string code, string dni, string nombre, string apellidos, string direccion, string localidad, string provincia, string pais) : Persona(dni,nombre,apellidos,direccion,localidad,provincia,pais)
  {
  setCodigo(code);
  }

//Metodo que asigna un determinado codigo al crupier

void Crupier::setCodigo(string code) {
	_codigo=code;
}

//Metodo que devuelve el codigo del crupier

string Crupier::getCodigo() {
	return _codigo;
}
