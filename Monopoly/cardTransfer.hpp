#ifndef CARD_TRANSFER_H
#define CARD_TRANSFER_H

#include "card.hpp"
#include "player.hpp"
#include <iostream>
#include <string>

class CardTransfer: public Card{
public:
    CardTransfer(const std::string& name, unsigned field)
    :m_name(name), m_field(field){
    }
    
    std::string chanceMessage() const override;
    std::string chestMessage() const override;
    void action(Player& player) const;
private:
    std::string m_name;
    unsigned m_field;    
};


#endif
