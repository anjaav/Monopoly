#ifndef CARD_GET_OUT_JAIL_H
#define CARD_GET_OUT_JAIL_H

#include "card.hpp"
#include "player.hpp"
#include <iostream>
#include <string>

class CardGetOutJail: public Card{
public:
    CardGetOutJail(const std::string& name)
    :m_name(name){
    }
    
    std::string chanceMessage() const override;
    std::string chestMessage() const override;
    void action(Player& player) const; 
private:
    std::string m_name;
};


#endif
