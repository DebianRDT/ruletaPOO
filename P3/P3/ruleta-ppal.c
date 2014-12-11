#include "apuestas.h"
#include "crupier.h"
#include "jugador.h"
#include "persona.h"
#include "ruleta.h"
#include <iostream>
#include <string>

using namespace std;

// Programa principal que probará el software



int main() {

    //Declaracion de variables
    Crupier crupi("0014D","26251968K"); //Declaramos el crupier
    Ruleta rule(crupi); //Declaramos la ruleta
    int cantidadJugadores; //Declaramos la cantidad de jugadores que se recogeran
    Jugador auxiliar("0000D", "00000000K");

    //Actualmente la banca tiene un millon de euros, pero ahora vamos a cargar a los jugadores y las
    //apuestas que van a efectuar. Estas apuestas y la cantidad apostada estara en un fichero de jugador
    //que tendran declarado

    cout << "¿Cuantos jugadores quieres crear?" << endl;
    cin >> cantidadJugadores;

    //Si el numero de jugadores es 0, se leeran directamente del fichero jugadores.txt, en caso contrario
    //se le iran pidiendo al usuario los jugadores y se incluiran en un fichero jugadores.txt

    if(cantidadJugadores==0) {

        rule.leeJugadores();

    } // fin del if
    else {

        int i;
        string code;
        string dni;
        for(i=0; i<cantidadJugadores; i++) {
            cout << "¿Cual es el codigo del jugador?" << endl;
            cin >> code;
            cout << "¿Cual es el DNI del jugador?" << endl;
            cin >> dni;
            auxiliar.setCodigo(code);
            auxiliar.setDNI(dni);
            rule.addJugador(auxiliar);

        } //fin del for

        rule.escribeJugadores();

    } // fin del else

    //Una vez leidos los jugadores vamos a hacer girar la ruleta

    rule.giraRuleta();

    //Por ultimo vamos a cargar las apuestas de los jugadores y actualizar su dinero y el de la banca

    rule.getPremios();

    //Una vez actualizados los premios vamos a mostrar el dinero de la banca por pantalla

    cout << "El dinero actual de la banca es: " << rule.getBanca() << endl;

    //Ahora vamos a mostrar el dinero de cada jugador por pantalla

    cout << "El dinero de cada jugador es: " << endl << endl;

    rule.getDineroJugador();

    cout << "Borramos al ultimo jugador  " << endl << endl;

    rule.deleteJugador(auxiliar);

    cout << "Volvemos a mostrar el dinero de los jugadores: " << endl << endl;

    rule.getDineroJugador();


    return 0;
}
