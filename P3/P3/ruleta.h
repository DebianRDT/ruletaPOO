#ifndef RULETA_H
#define RULETA_H

#include <iostream>
#include <string>
#include <list>
#include "crupier.h"
#include "persona.h"
#include "apuestas.h"
#include "jugador.h"


/* La clase ruleta representa a la ruleta fisica que giraria y determinaria las condiciones en las cuales
 *un jugador perderia el dinero apostado o sacaria beneficio economico*/


using namespace std;

class Ruleta {
private:
    int banca_, bola_;
    list<Jugador> jugadores_;
    Crupier crupier_;

public:
    Ruleta(Crupier crupier);
    void setCrupier(Crupier crupier);
    Crupier getCrupier();
    void setBanca(int dinero);
    void setBola(int numero);
    int getBanca();
    int getBola();
    list<Jugador> getJugadores();
    void addJugador(Jugador jugador);
    int deleteJugador(Jugador jugador);
    int deleteJugador(string dniJugador);
    void escribeJugadores();
    void leeJugadores();
    void giraRuleta();
    void getPremios();
    int ganaOPierde(int tipoApuesta, string valor, int cantidad, int ball);
    void getDineroJugador();
};


#endif
