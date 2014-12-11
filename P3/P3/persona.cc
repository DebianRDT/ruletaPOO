#include <iostream>
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




//Constructor
Persona::Persona(string dni, string nombre, string apellidos, string direccion, string localidad, string provincia, string pais) {
	setDNI(dni);
	setNombre(nombre);
	setApellidos(apellidos);
	setDireccion(direccion);
	setLocalidad(localidad);
	setProvincia(provincia);
	setPais(pais);
}

//Metodo que asigna un DNI a una persona
void Persona::setDNI(string dni) {
	_dni=dni;
}

//Metodo que asigna un nombre a una persona
void Persona::setNombre(string nombre) {
	_nombre=nombre;
}

//Metodo que asigna unos apellidos a una persona
void Persona::setApellidos(string apellidos) {
	_apellidos=apellidos;
}

//Metodo que asigna una direccion a una persona
void Persona::setDireccion(string direccion) {
	_direccion=direccion;
}

//Metodo que asigna una localidad a una persona
void Persona::setLocalidad(string localidad) {
	_localidad=localidad;
}

//Metodo que asigna una provincia a una persona
void Persona::setProvincia(string provincia) {
	_provincia=provincia;
}

//Metodo que asigna un pais a una persona
void Persona::setPais(string pais) {
	_pais=pais;
}

//Metodo que devuelve el DNI de una persona
string Persona::getDNI() {
	return _dni;
}

//Metodo que devuelve el pais de una persona
string Persona::getPais() {
	return _pais;
}

//Metodo que devuelve el nombre de una persona
string Persona::getNombre() {
	return _nombre;
}

//Metodo que devuelve los apellidos de una persona
string Persona::getApellidos() {
	return _apellidos;
}

//Metodo que devuelve la provincia de una persona
string Persona::getProvincia() {
	return _provincia;
}

//Metodo que devuelve la localidad de una persona
string Persona::getLocalidad() {
	return _localidad;
}

//Metodo que devuelve la direccion de una persona
string Persona::getDireccion() {
	return _direccion;
}

//Metodo que devuelve el nombre y los apellidos de una persona
string Persona::getApellidosyNombre() {
	return _apellidos+", "+_nombre;
}
