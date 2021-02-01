#include "goToJail.hpp"

std::string GoToJail::name() const
{
  return std::string("Go to jail field");
}

std::string GoToJail::className() const
{
	return std::string("goToJail");
}

void GoToJail::action(Player& player){
    if(player.jailCard()){
        player.changeJailCardNum(-1);
        std::cout << player.name() << " stepped on Go to Jail field, but has the Get out of jail card." << std::endl;
    }
    else{
        player.goToJail(); //setting position and flag (count of turns)
        std::cout << player.name() << " is on Go to jail field!\nGo strait to jail!" << std::endl;
    }
}