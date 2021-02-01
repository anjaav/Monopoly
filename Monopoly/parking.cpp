#include "parking.hpp"

void Parking::giveMoney(Player &player)
{
	player.receive(m_money);
	m_money = 0;
}

void Parking::reciveMoney(unsigned money) 
{
	m_money += money;
}

std::string Parking::name() const
{
  return std::string("Parking");
}

void Parking::action(Player& player){
    //modified rule for stepping on the Free Parking field
    //player gets all the money; if there is no money, he gets 100$
    std::cout << player.name() << " is on Free parking field\n" << std::endl;

    if(m_money){
      std::cout << "You got " << m_money << "$ !\n" << std::endl;
      this->giveMoney(player);
    }
    else{
      std::cout << "There is no money on the Parking field, but you get 100$ !\n" << std::endl;
      player.receive(100);
    }
}