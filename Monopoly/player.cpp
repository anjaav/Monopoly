#include "player.hpp"
#include "city.hpp"


std::string Player::name() const
{
  return m_name;
}

void Player::setName(std::string name)
{
  m_name = name;
}

unsigned Player::id() const
{
  return m_id;
}

unsigned Player::money() const
{
  return m_money;
}

unsigned Player::position() const
{
  return m_position;
}

void Player::setPosition(unsigned position)
{
  m_position = position;
}

void Player::changePosition(int position)
{
  if((m_position + position) >= 40)
    {
    m_money += 200;
    m_position = (m_position + position) % 40;
    }
  else if ((m_position + 40 + position) < 40)
    {
    m_position = 40 + m_position + position;
    }
  else
    {
    m_position += position;
    }
}


void Player::pay(unsigned money)
{
    while(money>m_money){
        bool noMoney = turnCityToMortgage();
        if(!noMoney){
            std::cout << "Player " << m_name << " has no more money left or ability to take mortgage to repay the money."
                << "\nEnd game." << std::endl;
            std::exit(EXIT_SUCCESS);
        }
        std::cout << "Player " << m_name 
            << " has no more money, but has the ability to take mortgage to repay the money." << std::endl;
    }
    m_money -= money;
}

void Player::receive(unsigned money)
{
  m_money += money;
}



void Player::setNumberOfStation(unsigned numberOfStation)
{
  m_numberOfStation = numberOfStation;
}

unsigned Player::numberOfStation() const
{
  return m_numberOfStation;
}


void Player::buyCity(City* city){
    pay(city->price());
    m_boughtCities[city->group()].push_back(city);
    city->setOwner(this);
}

bool Player::turnCityToMortgage(){
    for(auto i=m_boughtCities.begin(); i!= m_boughtCities.end(); i++){
        for(auto j=i->second.rbegin(); j!=i->second.rend(); j++){
            if((*j)!=nullptr && !((*j)->mortgage())){
                (*j)->turnToMortgage();  //method also gives player the money
                return true;
            }
        }
    }
    return false;
}

std::map<std::string,std::vector<City*>>* Player::boughtCities()
{
  return &m_boughtCities;
}


void Player::setCityInBoughtCities(City *city)
{
  m_boughtCities[city->group()].push_back(city);
}


unsigned Player::jailCard()
{
  return m_jailCard;
}


void Player::changeJailCardNum(int number)
{
  m_jailCard += number;
}


int Player::isInJail() const{
  return m_isInJail;
}


void Player::goToJail(){
    m_isInJail=1;
    m_count=0; //in case Player got in jail with a card, and before that got doubles
    m_position=10;
}



std::pair<int,int> Player::rollDice(){
    int x=std::rand()%6+1;
    int y=std::rand()%6+1;  std::cout<< x << " " << y <<std::endl;
    
    //if a player got same numbers he plays again
    //he can play max 3 times in a sequence, 4th time he goes to jail
    if(x==y){
        m_count++;
        if(m_count==4){
            std::cout << "You got equal dice values 4 times in a row!\nYou are going to jail!" << std::endl;
            goToJail();
            m_count=0;
        }
    }
    else
        m_count=0;
    
    return std::make_pair(x,y);
}

//dice() returns sum of two dice trows
int Player::dice(){
    std::pair<int, int> dice;
    dice=rollDice();
    return dice.first + dice.second;
}


bool Player::movePlayer(){
    int step;
        
    if(!m_isInJail){ //player not in jail
        step = dice();
        if(m_isInJail)  //player can go to jail by trowing a dice (4 times doubles) or with a card
            return false;
    }
    else if(m_isInJail == 4){
        std::cout << m_name << " skiped 3 turns and can get out of jail!\nBut has to pay 50$" <<std::endl;
        pay(50); //player can't roll the dice anymore and has to pay to get out and continue playing
        m_isInJail=0;
        step = dice();
    }
    else{   //player can roll the dice again to get out of jail
        std::cout << m_name << " is in jail!\nRoll the dice to get out!" <<std::endl;
        std::pair<int, int> dice=rollDice();
            
        if(dice.first == dice.second){
            std::cout << "You got out of jail! Keep playing!" <<std::endl;
            m_isInJail=0;
            m_count=0; //player has the right to move only once after getting out of jail and we have to reset
                        //the counter, since the player just got doubles
            step = dice.first + dice.second;
        }
        else{
            std::cout << "No luck!" <<std::endl;
            m_isInJail++;
            return false; //returning false->this player doesn't move on the board
        }
    }
        
    changePosition(m_position + step);
    return true;
}


int Player::countTurns() const{
    return m_count;
}