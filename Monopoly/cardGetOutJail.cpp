#include "cardGetOutJail.hpp"

std::string CardGetOutJail::chanceMessage() const {
    return Card::chanceMessage() + m_name;
}


std::string CardGetOutJail::chestMessage() const {
    return Card::chestMessage() + m_name;
}

void CardGetOutJail::action(Player& player) const{
    std::cout << player.name() + " got a Get out of jail card.\n" << std::endl;
    player.changeJailCardNum(1); 
}