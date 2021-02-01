#include "game.hpp"


VChance* VChance::_chanceSample = 0;
VChest* VChest::_chestSample = 0;

//global var onTheMove
//if true, on the move is player1, else player2
bool onTheMove;




void initialize_board(std::vector<Field*> &board)
{
  Field* parking = new Parking();
  Field* start = new Start();
  board.push_back(start);
  Field* city1 = new City("Barcelona", 60, "brown");
  board.push_back(city1);
  Field* chest1 = VChest::getSample();
  board.push_back(chest1);
  Field* city2 = new City("Madrid", 60, "brown");
  board.push_back(city2);
  Field* porez1 = new Tax("Income tax", 200, (Parking*)parking);
  board.push_back(porez1);
  Field* station1 = new Station("Madrid Puerta de Atocha station");
  board.push_back(station1);
  Field* city3 = new City("Naples", 100, "light blue");
  board.push_back(city3);
  Field* chance1 = VChance::getSample();
  board.push_back(chance1);
  Field* city4 = new City("Milan", 100, "light blue");
  board.push_back(city4);
  Field* city5 = new City("Rome", 120, "light blue");
  board.push_back(city5);
  Field* jail = new Jail();
  board.push_back(jail);
  Field* city6 = new City("Birmingham", 140, "purple");
  board.push_back(city6);
  Field* utility1 = new Utilities("Utilities -  Electric Company");
  board.push_back(utility1);
  Field* city7 = new City("Manchester", 140, "purple");
  board.push_back(city7);
  Field* city8 = new City("London", 160, "purple");
  board.push_back(city8);
  Field* station2 = new Station("Gare du Nord station");
  board.push_back(station2);
  Field* city9 = new City("Marseille", 180, "orange");
  board.push_back(city9);
  Field* chest2 = VChest::getSample();
  board.push_back(chest2);
  Field* city10 = new City("Bordeaux", 180, "orange");
  board.push_back(city10);
  Field* city11 = new City("Paris", 200, "orange");
  board.push_back(city11);
  //parking is already created at the begining
  board.push_back(parking);
  Field* city12 = new City("Nis", 220, "red");
  board.push_back(city12);
  Field* chance2 = VChance::getSample();
  board.push_back(chance2);
  Field* city13 = new City("Novi Sad", 220, "red");
  board.push_back(city13);
  Field* city14 = new City("Belgrade", 240, "red");
  board.push_back(city14);
  Field* station3 = new Station("Leningradskiy Railway Station");
  board.push_back(station3);
  Field* city15 = new City("Novosibirsk", 260, "yellow");
  board.push_back(city15);
  Field* city16 = new City("St. Petersburg", 260, "yellow");
  board.push_back(city16);
  Field* utility2 = new Utilities("Utilities - Water supply");
  board.push_back(utility2);
  Field* city17 = new City("Moscow", 280, "yellow");
  board.push_back(city17);
  Field* gtJail = new GoToJail();
  board.push_back(gtJail);
  Field* city18 = new City("Munich", 300, "green");
  board.push_back(city18);
  Field* city19 = new City("Hamburg", 300, "green");
  board.push_back(city19);
  Field* chest3 = VChest::getSample();
  board.push_back(chest3);
  Field* city20 = new City("Berlin", 320, "green");
  board.push_back(city20);
  Field* station4 = new Station("Leipzig Central Station");
  board.push_back(station4);
  Field* chance3 = VChance::getSample();
  board.push_back(chance3);
  Field* city21 = new City("Geneva", 350, "blue");
  board.push_back(city21);
  Field* porez2 = new Tax("Luxury tax", 100, (Parking*)parking);
  board.push_back(porez2);
  Field* city22 = new City("Zürich", 400, "blue");
  board.push_back(city22);
  
}

//welcome note and players' name input
std::pair<std::string, std::string> welcomeNote(){
    std::string name1, name2;
    const std::string note = "* Welcome to Monopoly (edition for 2 players) !!! *";
    const std::string bar(note.size(), '*');
    std::cout << '\n' << bar << '\n' << note << '\n' << bar << '\n' << std::endl;
    std::cout << "Enter first player's name:  ";
    std::cin >> name1;
    std::cout << "Enter second player's name:  ";
    std::cin >> name2;
    return std::make_pair(name1, name2);
}


//used for initializing global var -onTheMove-
bool playesFirst(){
    std::srand(std::time(NULL));
    int x1,y1,x2,y2;
    std::cout<< "\n--> First on the move is the player with greater dice values.\n" <<std::endl;

    x1=std::rand()%6+1;  
    y1=std::rand()%6+1;  std::cout<< "First player's dice values: " << x1  << " " << y1 <<std::endl;
    x2=std::rand()%6+1;  
    y2=std::rand()%6+1;  std::cout<< "Second player's dice values: " << x2  << " " << y2 << '\n' <<std::endl;
    
    return x1+y1>x2+y2;    
}


//this function is called from main to get a pointer to a player who is on the move in each loop
Player* fCurrentPlayer(Player* player1,Player* player2){    
    if(onTheMove==true){
        onTheMove=false;
        return player1;
    }
    else{
        onTheMove=true;
        return player2;
    }
}
