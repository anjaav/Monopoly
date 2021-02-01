#ifndef UTILITIES_H_
#define UTILITIES_H_

#include "field.hpp"
#include "player.hpp"

#include <iostream>
#include <algorithm>

class Utilities: public Field{
public:
  Utilities(std::string name)
    : m_name(name){
        m_price = 150;
        m_mortgageValue = m_price / 2;
        m_owner = NULL;
        m_rent = m_price/3;
  }
  
  std::string name() const;
  void changeOwner(Player* p);
  void setOwner(Player* p);
  Player* owner() const;
  unsigned price() const;
  unsigned mortgageValue() const;
  void turnToMortgage();
  void repayMortgage();
  unsigned rent() const;

  std::string className() const;
  
  void action(Player&);

private:
  std::string m_name;
  Player* m_owner;
  unsigned m_price;
  unsigned m_mortgageValue;
  unsigned m_rent;
};

#endif
