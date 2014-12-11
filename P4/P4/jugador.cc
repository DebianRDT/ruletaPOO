#include <iostream>
#include "crupier.h"
#include "persona.h"
#include "jugador.h"
#include "apuestas.h"
#include <ctime>
#include <cstdlib>
#include <string>
#include <cstring>
#include <list>
#include <fstream>
#include <sstream>
#include "stdlib.h"


/**
 * --------------------------------------
 * Programa creado por Debian@Linceus.es
 * --------------------------------------
 * 
 */

using namespace std;


//Constructor de la clase
Jugador::Jugador(string code, string dni, string nombre, string apellidos, string direccion, string localidad, string provincia, string pais) : Persona(dni,nombre,apellidos,direccion,localidad,provincia,pais)
  {
  setDinero(1000);
  setCodigo(code);
  }

//Metodo que devuelve el dinero que tiene el jugador
int Jugador::getDinero() {
	return _dinero;
}

//Metodo que asigna una cantidad de dinero al jugador
void Jugador::setDinero(int cantidad) {
	_dinero=cantidad;
}

//Metodo que devuelve el codigo del jugador
string Jugador::getCodigo() {
	return _codigo;
}

//Metodo que asigna un codigo a un jugador
void Jugador::setCodigo(string code) {
	_codigo=code;
}

//Metodo que devuelve la lista de apuestas del jugador, que son cargadas desde un fichero externo, nombrado con su DNI
std::list<Apuestas> Jugador::getApuestas() {
	return _apuestas;
}

void Jugador::setApuestas(string dni) {
	string nombreFichero=dni+".txt";
	char *conversion=strdup(nombreFichero.c_str());
	ifstream fichero(conversion);
	string linea;
	Apuestas apuesta;
	if(!fichero.is_open()) {
		cout<<"No se ha podido abrir el fichero"<<endl;
		exit(0);
	}
	else {
		while(getline(fichero,linea,',')) {
			apuesta._tipo=atoi(linea.c_str());
			getline(fichero,linea,',');
			apuesta._valor=linea;
			getline(fichero,linea,'\n');
			apuesta._cantidad=atoi(linea.c_str());
			_apuestas.push_back(apuesta);
		}

		
		
	}
}
