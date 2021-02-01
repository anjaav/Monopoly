#include "cardMove.hpp"

std::string CardMove::chanceMessage() const {
    return Card::chanceMessage() + m_name;
}


std::string CardMove::chestMessage() const {
    return Card::chestMessage() + m_name;
}

void CardMove::action(Player& player) const{
    std::cout << player.name() << " moves for " << m_steps << " steps.\n" << std::endl;
    player.changePosition(m_steps);
}