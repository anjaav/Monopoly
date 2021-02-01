#include "utilities.hpp"

std::string Utilities::name() const
{
  return m_name;
}

void Utilities::changeOwner(Player* p)
{
  m_owner = p;
}

void Utilities::setOwner(Player* p)
{
  m_owner = p;
}

Player* Utilities::owner() const
{
  return m_owner;
}

unsigned Utilities::price() const
{
  return m_price;
}

unsigned Utilities::mortgageValue() const
{
  return m_mortgageValue;
}

void Utilities::turnToMortgage()
{
  m_owner->receive(m_mortgageValue);
  m_rent = 0;
}

void Utilities::repayMortgage()
{
  m_owner->pay(m_mortgageValue);
  m_rent = m_price/3;
}

unsigned Utilities::rent() const
{
  return m_rent;
}

std::string Utilities::className() const
{
	return std::string("utilities");
}

void Utilities::action(Player& player){
    if(!m_owner){
        std::string answer;
	      std::cout << "Do you wish to buy this utility? (yes/no)" << std::endl;
	      std::cin >> answer;
        std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
        if(answer=="yes" || answer=="y"){
            player.pay(m_price);
            changeOwner(&player);
            std::cout << "You just bought " << m_name << std::endl;
        }
      }
    else{ //other player is the owner
        player.pay(m_rent);   
        m_owner->receive(m_rent);
    }                   
}