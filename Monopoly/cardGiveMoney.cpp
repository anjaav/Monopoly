#include "cardGiveMoney.hpp"

std::string CardGiveMoney::chanceMessage() const {
    return Card::chanceMessage() + m_name;
}


std::string CardGiveMoney::chestMessage() const {
    return Card::chestMessage() + m_name;
}

void CardGiveMoney::action(Player& player) const{
   std::cout << player.name() << " got " << m_amount << "$.\n" << std::endl;
    player.receive(m_amount);
}