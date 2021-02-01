#ifndef CARD_GIVE_MONEY_H
#define CARD_GIVE_MONEY_H

#include "card.hpp"
#include "player.hpp"
#include <iostream>
#include <string>

class CardGiveMoney: public Card{
public:
    CardGiveMoney(const std::string& name, unsigned amount)
    :m_name(name), m_amount(amount){
    }
    
    std::string chanceMessage() const override;
    std::string chestMessage() const override;
    void action(Player& player) const;
private:
    std::string m_name;
    unsigned m_amount;    
};


#endif
