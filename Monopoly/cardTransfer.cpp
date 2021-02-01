#include "cardTransfer.hpp"

std::string CardTransfer::chanceMessage() const {
    return Card::chanceMessage() + m_name;
}


std::string CardTransfer::chestMessage() const {
    return Card::chestMessage() + m_name;
}

void CardTransfer::action(Player& player) const{
    std::cout << player.name() << " transfered to field number " << m_field << ".\n" << std::endl;
    if (m_field < player.position())
        player.receive(200);
    player.setPosition(m_field);
    
}
