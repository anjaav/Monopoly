#ifndef CARD_GO_TO_JAIL_H
#define CARD_GO_TO_JAIL_H

#include "card.hpp"
#include "player.hpp"
#include <iostream>
#include <string>

class CardGoToJail: public Card{
public:
    CardGoToJail(const std::string& name)
    :m_name(name){
    }
    
    std::string chanceMessage() const override;
    std::string chestMessage() const override;
    void action(Player& player) const;
private:
    std::string m_name;
};


#endif
