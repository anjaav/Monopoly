#ifndef _GAME_H
#define _GAME_H

#include "field.hpp"
#include "city.hpp"
#include "player.hpp"
#include "station.hpp"
#include "utilities.hpp"
#include "start.hpp"
#include "vchance.hpp"
#include "vchest.hpp"
#include "tax.hpp"
#include "jail.hpp"
#include "goToJail.hpp"

#include "parking.hpp"

#include <utility>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>


extern bool onTheMove;

void initialize_board(std::vector<Field*> &board);
std::pair<std::string, std::string> welcomeNote();
bool playesFirst();
Player* fCurrentPlayer(Player*, Player*);

#endif
