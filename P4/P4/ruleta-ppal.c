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

    bool salidaBucle=true;
    int opcionUsuario=0;
    string dniJugador;
    Jugador auxiliar("0000D", "00000000K");
    string code;
    string dni;
    int gananciaBanca, nLanzamientos, nJugadores, dineroMesa;
    Crupier crupi("0014D","26251968K"); //Declaramos el crupier
    Ruleta rule(crupi); //Declaramos la ruleta

    while(salidaBucle) {
        cout << "Opciones del programa: " << endl;
        cout << "1) Cargar jugadores" << endl;
        cout << "2) Guardar jugadores" << endl;
        cout << "3) Ver estado" << endl;
        cout << "4) Hacer girar la ruleta" << endl;
        cout << "5) Eliminar a un jugador" << endl;
        cout << "6) Añadir un jugador" << endl;
        cout << "7) Salir del programa"<< endl;
        cout << "Elige tu opcion: ";
        cin >> opcionUsuario;
        cout << endl;

        switch(opcionUsuario) {
        case 1: rule.leeJugadores();
                break;

        case 2: rule.escribeJugadores();
                break;

        case 3: rule.getEstadoRuleta(&nJugadores, &dineroMesa, &nLanzamientos, &gananciaBanca);
            cout << "El numero de jugadores que hay en la mesa es de: " << nJugadores << endl;
            cout << "La cuantia total de dinero que hay en la mesa es de: " << dineroMesa << endl;
            cout << "El numero total de lanzamientos es de: " << nLanzamientos << endl;
            cout << "El saldo actual de la banca respecto al comienzo es de: " << gananciaBanca << endl;
                break;

        case 4: rule.giraRuleta();
                break;

        case 5: cout << "Escribe el DNI del jugador: ";
                cin >> dniJugador;
                rule.deleteJugador(dniJugador);
                break;

        case 6:     cout << "¿Cual es el codigo del jugador?" << endl;
                    cin >> code;
                    cout << "¿Cual es el DNI del jugador?" << endl;
                    cin >> dni;
                    auxiliar.setCodigo(code);
                    auxiliar.setDNI(dni);
                    rule.addJugador(auxiliar);
                break;

        case 7: salidaBucle=false;
                break;

        default: break;
        }
    }

    return 0;
}
