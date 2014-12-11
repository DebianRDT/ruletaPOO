#include <iostream>
#include "persona.h"
#include "ruleta.h"
#include "crupier.h"
#include "jugador.h"
#include <ctime>
#include <cstdlib>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>



using namespace std;

/**
 * --------------------------------------
 * Programa creado por Debian@Linceus.es
 * --------------------------------------
 *
 */

//Constructor de la clase
Ruleta::Ruleta(Crupier crupier) : crupier_(crupier) { //Tener en cuenta esto, paso a explicarlo abajo
    /*
     *Por defecto, si en C++ trato de inicializar el constructor poniendo el objeto
     *Crupier dentro del constructor, al compilar se cree que estas creando un
     *objeto de tipo crupier, por eso ponemos el : crupier_(crupier) para indicar
     *que lo que estamos haciendo es pasarle un objeto ya existente */

    setBanca(1000000);
    bola_=-1;
    lanzamientos_=0;
}

//Metodo que asigna un crupier a la ruleta
void Ruleta::setCrupier(Crupier crupier) {
    crupier_=crupier;
}

//Metodo que devuelve el crupier de la ruleta
Crupier Ruleta::getCrupier() {
    return crupier_;
}

//Metodo que asigna un dinero a la ruleta
void Ruleta::setBanca(int dinero) {
    if (dinero>0) {
        banca_=dinero;
    }
    else {
        cout<<"Error. La cantidad ha de ser positiva"<<endl;
    }
}

//Metodo que asigna el resultado de la bola a la ruleta
void Ruleta::setBola(int numero) {
    if (numero >= 0 && numero <= 36) {
        bola_=numero;
    }
    else {
        cout<<"\nError. El número debe estar comprendido entre 0 y 36\n"<<endl;
   }
}

//Metodo que devuelve el dinero actual de la ruleta
int Ruleta::getBanca() {
    return banca_;
}

//Metodo que devuelve el resultado actual de la bola
int Ruleta::getBola() {
    return bola_;
}

//Metodo que hace rular la ruleta y por consiguiente cambia el valor de la bola
void Ruleta::giraRuleta() {
    srand(time(NULL));
    int numero=rand()%36;
    setBola(numero);
    lanzamientos_++;

}

//Metodo que devuelve la lista de jugadores que hay jugando en la ruleta
std::list<Jugador> Ruleta::getJugadores() {
        return jugadores_;
}

//Metodo que añade un jugador a la ruleta
void Ruleta::addJugador(Jugador jugador) {
    jugadores_.push_back(jugador);
    string nombreFichero=jugador.getDNI()+".txt";
    char * conversion=strdup(nombreFichero.c_str());
    ifstream fichero (conversion);
    if (fichero.is_open()) {

    }
    else {
        ofstream ficheroNuevo (conversion);
        ficheroNuevo.close();
    }
    fichero.close();
}

//Metodo que borra a un jugador, pasado como tal
int Ruleta::deleteJugador(Jugador jugador) {
    int verificacion;
    if(jugadores_.empty()) {
        verificacion=-1;
    }
    else {
        list<Jugador>::iterator i;
                for(i=jugadores_.begin(); i != jugadores_.end(); i++) {


                    if (jugador.getDNI()==(*i).getDNI()) {
                       i = jugadores_.erase(i);
                       verificacion=1;
                    }
                else {
                    verificacion=-2;
                }

             }

    }
    return verificacion;
}


//Metodo que borra a un jugador, indicado por su DNI
int Ruleta::deleteJugador(string dniJugador) {
    int verificacion;
    if(jugadores_.empty()) {
        verificacion=-1;
    }
    else {
        list<Jugador>::iterator i;
                for(i=jugadores_.begin(); i != jugadores_.end(); i++) {


                    if (dniJugador==(*i).getDNI()) {
                       i = jugadores_.erase(i);
                       verificacion=1;
                    }
                else {
                    verificacion=-2;
                }

             }

    }
    return verificacion;
}

//Metodo que escribe los jugadores que hay en la lista en un fichero externo llamado jugadores.txt
void Ruleta::escribeJugadores() {

    ofstream fichero("jugadores.txt");

    if(!fichero) {
        cout <<"No se ha podido crear el fichero"<<endl;
    }
    else {
        list<Jugador>::iterator i;
                for(i=jugadores_.begin(); i != jugadores_.end(); i++) {
                    fichero<<(*i).getDNI();
                    fichero<<",";
                    fichero<<(*i).getCodigo();
                    fichero<<",";
                    fichero<<(*i).getNombre();
                    fichero<<",";
                    fichero<<(*i).getApellidos();
                    fichero<<",";
                    fichero<<(*i).getDireccion();
                    fichero<<",";
                    fichero<<(*i).getLocalidad();
                    fichero<<",";
                    fichero<<(*i).getProvincia();
                    fichero<<",";
                    fichero<<(*i).getPais();
                    fichero<<",";
                    fichero<<(*i).getDinero();
                    fichero<<endl;
                }
    }
    fichero.close();
}

//Metodo que lee los jugadores de un fichero externo, borrando la lista ya existente
void Ruleta::leeJugadores() {
    //Primero borramos la lista
    jugadores_.clear();


   //Recogemos las variables que nos seran de ayuda en la construccion de un jugador
    ifstream fichero("jugadores.txt");
    string linea, dni, codigo, nombre, apellidos, direccion, localidad, provincia, pais;
    int dinero;
    if(!fichero.is_open()) {
        cout<<"El archivo no se ha podido abrir"<<endl;
    }
    else {

        Jugador jugador("lolo","lolo");
        while(getline(fichero,linea,',')) {
            dni=linea;
            getline(fichero,linea,',');
            codigo=linea;
            getline(fichero,linea,',');
            nombre=linea;
            getline(fichero,linea,',');
            apellidos=linea;
            getline(fichero,linea,',');
            direccion=linea;
            getline(fichero,linea,',');
            localidad=linea;
            getline(fichero,linea,',');
            provincia=linea;
            getline(fichero,linea,',');
            pais=linea;
            getline(fichero,linea,'\n');
            dinero=atoi(linea.c_str());

            jugador.setCodigo(codigo);
            jugador.setDNI(dni);
            jugador.setNombre(nombre);
            jugador.setApellidos(apellidos);
            jugador.setDireccion(direccion);
            jugador.setLocalidad(localidad);
            jugador.setProvincia(provincia);
            jugador.setPais(pais);
            jugador.setDinero(dinero);

            jugadores_.push_back(jugador);

        }
    }
}

//Metodo que verifica que jugadores han ganado o perdido y actualiza su dinero
void Ruleta::getPremios() {
    //Declaracion de variables
     int tipo;
     string valor;
     int cantidad;
     string nombreFichero;
     char * conversion;
     ifstream fichero;
     string linea;
     int resultado;


    //Primero recorremos la lista
    list<Jugador>::iterator i;
    for(i=jugadores_.begin(); i!=jugadores_.end(); i++) {
        (*i).setApuestas((*i).getDNI());
        list<Apuestas> listaApuestas=(*i).getApuestas();
            nombreFichero=(*i).getDNI()+".txt";
            conversion=strdup(nombreFichero.c_str());
            fichero.open(conversion);
            if(!fichero.is_open()) {
                cout<<"No se ha podido abrir el fichero"<<endl;
                exit(0);
            }
            else {
                while(getline(fichero,linea,',')) {
                    tipo=atoi(linea.c_str());
                    getline(fichero,linea,',');
                    valor=linea;
                    getline(fichero,linea,'\n');
                    cantidad=atoi(linea.c_str());
                    resultado=(ganaOPierde(tipo, valor, cantidad, bola_));

                    if(resultado!=-11254798) {

                        (*i).setDinero((*i).getDinero()+resultado);
                        setBanca(getBanca()-resultado);

                    }
                    else {
                        printf("El tipo de apuesta no es valida");
                    }
                }
            } fichero.close();
 }
}


//Metodo que determina si un jugador ha perdido o ganado en cada apuesta
int Ruleta::ganaOPierde(int tipoApuesta, string valor, int cantidad, int ball) {
    int resultado=-11254798;
    int bola=ball;
    string color="Debian";
    int apuestaI;
    string apuestaS;
    string parImpar;
    string bajoAlto;


    switch(tipoApuesta) {
    case 1: //Comienzo del tipo de apuesta 1

        apuestaI=atoi(valor.c_str());
        if(apuestaI <= 36 && apuestaI >=0) { //Se comprueba que la apuesta es valida
            if(apuestaI==bola) {

                resultado=cantidad*35; //Ha ganado

            }
            else {

                resultado=0-cantidad; //Ha perdido

            }
            break;
        }
        else {
                cout << "Tipo de apuesta invalida" << apuestaI << endl;
                break;
        }

    case 2: //Comienzo de la apuesta 2

        apuestaS=valor;
        if (apuestaS == "rojo" || apuestaS == "negro") {
            if (bola == 0) {
                resultado=-cantidad;
                break;
            }

            switch(bola) {

            //Numeros en los que la bola caera en una casilla roja
            case 1:case 3:case 5:case 7:case 9:case 12:
            case 14:case 16:case 18:case 19:case 21:
            case 23:case 25:case 27:case 30:case 32:
            case 34:case 36: color="rojo";

            //Numeros en los que la bola caera en una casilla negra
            case 2:case 4:case 6:case 8:case 10:case 11:
            case 13:case 15:case 17:case 20:case 22:case 24:
            case 26:case 28:case 29:case 31:case 33:case 35: color="negro";

            }
            if(apuestaS == color) {
                resultado=cantidad;
            }
            else {
                resultado=0-cantidad;
            }
            break;
        }
        else {
            cout << "Tipo de apuesta invalida" << apuestaS << endl;
            break;
        }
    case 3: //Comienzo de la apuesta 3

        apuestaS=valor;
        if(apuestaS == "par" || apuestaS == "impar") {
            if (bola == 0) {
                resultado=0-cantidad;
                break;
            }
            if((bola%2) == 0) {
                parImpar="par";
            }
            else {
                parImpar="impar";
            }
            if(apuestaS == parImpar) {
                resultado=cantidad;
            }
            else {
                resultado=0-cantidad;
            }
            break;
        }
        else {
            cout << "Tipo de apuesta invalida" << apuestaS << endl;
            break;
        }
    case 4:  //Comienzo de la apuesta 4

        apuestaS=valor;
        if(apuestaS == "alto" || apuestaS == "bajo") {
            if (bola == 0) {
                resultado=0-cantidad;
                break;
            }
            if (bola >=1 && bola <=18) {
                bajoAlto="bajo";
            }
            else {
                bajoAlto="alto";
            }
            if(apuestaS == bajoAlto) {
                resultado=cantidad;
            }
            else {
                resultado=0-cantidad;
            }
            break;
        }
        else {
            printf("Tipo de apuesta invalida\n");
            break;
        }
    default: cout << "No existe el tipo de apuesta" << tipoApuesta << endl;
            break;
    }

    return resultado;
}


//Metodo que devuelve el dinero de cada jugador de la lista
void Ruleta::getDineroJugador() {

    list<Jugador>::iterator i;
    for(i=jugadores_.begin(); i!=jugadores_.end(); i++) {
        cout << "-------------------" << endl;
        cout << "El jugador con DNI " << (*i).getDNI() << " tiene ahora " << (*i).getDinero() <<" €";
        if((*i).getDinero()<0) {
            cout << " -----> Arruinado";
        }
        cout<< endl;
        cout << "-------------------" << endl;
    }

}

//Metodo que acepta por referencia diversos parametros para conocer el estado de la ruleta
void Ruleta::getEstadoRuleta(int *numJugadores, int *canDinero, int *contLanzarBola, int *gananciaBanca) {

    //Contabilizamos el numero de jugadores que hay en la mesa
    *numJugadores=jugadores_.size();

    //Contabilizamos el dinero total que hay en la mesa
    int dineroTotal=getBanca();
    list<Jugador>::iterator i;
    for(i=jugadores_.begin(); i!=jugadores_.end(); i++) {
        dineroTotal+=(*i).getDinero();
    }
    *canDinero=dineroTotal;

    //Contabilizamos el numero de lanzamientos
    *contLanzarBola=lanzamientos_;

    //Contabilizamos la ganancia de la banca
    *gananciaBanca=getBanca()-1000000;

}

