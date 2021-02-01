#ifndef CARD_MOVE_H
#define CARD_MOVE_H

#include "card.hpp"
#include "player.hpp"
#include <iostream>
#include <string>

class CardMove: public Card{
public:
    CardMove(const std::string& name, int steps)
    :m_name(name), m_steps(steps){
    }
    
    std::string chanceMessage() const override;
    std::string chestMessage() const override;
    void action(Player& player) const;
private:
    std::string m_name;
    int m_steps;    
};


#endif
