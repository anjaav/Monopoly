#include "start.hpp"

std::string Start::name() const
{
  return std::string("Start");
}

std::string Start::className() const
{
	return std::string("start");
}


void Start::action(Player& player){
    //no action is required here
    std::cout << player.name() << " is on field Start." << std::endl;
}
