            /* abstract class Card */

#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>
#include "player.hpp"

class Card{
public:
    virtual std::string chanceMessage() const;
    virtual std::string chestMessage() const;
    virtual void action(Player&) const =0;
    virtual ~Card(){}
private:
    std::string m_sMessage= "***CHANCE*** \n";
    std::string m_iMessage= "***COMMUNITY CHEST***\n";
};

#endif
