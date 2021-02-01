#include "cardTakeMoney.hpp"

std::string CardTakeMoney::chanceMessage() const {
    return Card::chanceMessage() + m_name;
}


std::string CardTakeMoney::chestMessage() const {
    return Card::chestMessage() + m_name;
}

void CardTakeMoney::action(Player& player) const{
    std::cout << player.name() << " has to pay " << m_amount << "$.\n" << std::endl;
    player.pay(m_amount);
}