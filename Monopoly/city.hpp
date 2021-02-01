            /*  class City   */
// 22 fields which may be bought, expended with houses
// or mortgaged, will be objects of this class

#ifndef CITY_H
#define CITY_H

class Player;

#include "field.hpp"
#include <iostream>
#include <algorithm>

class City: public Field{
public:
    City(const std::string name, unsigned price, const std::string group) 
    : m_name(name), m_price(price), m_group(group)    {
        m_owner=NULL;
        m_isOwned=false;
        m_numHouses=0;
        m_mortgageValue=m_price/2;
        m_mortgage=false;
        m_rent=m_price/3;
    } 
    std::string name() const;
    void setOwner(Player*);
    unsigned price() const;
    bool increaseNumHouses(); 
    unsigned numHouses() const;
    std::string group() const;
    
    void turnToMortgage();
    bool mortgage() const;
    void repayMortgage();
    
    unsigned rent() const;

    std::string className() const;

    void changeOwner(Player* newOwner);
    
    
    void action(Player&);
    
    
private:
    std::string m_name;
    unsigned m_price;
    std::string m_group;
    Player* m_owner;
    bool m_isOwned;
    unsigned m_numHouses;
    unsigned m_mortgageValue;
    bool m_mortgage;
    unsigned m_rent;
};


#endif