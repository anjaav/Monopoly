#include "jail.hpp"

std::string Jail::name() const
{
  return std::string("Jail field");
}

std::string Jail::className() const {
	return std::string("jail");
}

void Jail::action(Player& player){
    //no action is required here
    std::cout << player.name() << " is on Jail field.\nJust visiting!" << std::endl;
}
