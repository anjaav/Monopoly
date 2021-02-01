#include "cardGoToJail.hpp"

std::string CardGoToJail::chanceMessage() const {
    return Card::chanceMessage() + m_name;
}


std::string CardGoToJail::chestMessage() const {
    return Card::chestMessage() + m_name;
}

void CardGoToJail::action(Player& player) const{
    std::cout << player.name() + " is sent to jail.\n" << std::endl;
    player.goToJail();
}