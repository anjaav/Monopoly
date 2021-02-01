#ifndef PLAYER_HPP
#define PLAYER_HPP

class City;

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>



class Player {
 public:
  Player(std::string name, unsigned id, unsigned money, unsigned position)
    : m_name(name), m_id(id), m_money(money), m_position(position)
  {
    m_jailCard = 0;
    m_isInJail = 0;
    m_numberOfStation = 0;
    m_count=0;
  }
  std::string name() const;
  void setName(std::string name);
  
  unsigned id() const;
  void setId(unsigned id);

  unsigned money() const;

  unsigned position() const;
  void setPosition(unsigned position);
  void changePosition(int position);


  void pay(unsigned money);
  void receive(unsigned money);

  void setNumberOfStation(unsigned numberOfStation);
  unsigned numberOfStation() const;

  void buyCity(City*);
  bool turnCityToMortgage();

  std::map<std::string,std::vector<City*>> *boughtCities();
  void setCityInBoughtCities(City *city);
  
  unsigned jailCard();
  void changeJailCardNum(int number);
  int isInJail() const;
  void goToJail();
  bool movePlayer();
  
  std::pair<int,int> rollDice();
  int dice();
  int countTurns() const;
  
 private:
  std::string m_name;
  unsigned m_id;
  unsigned m_money;
  unsigned m_position;
  unsigned m_jailCard;
  int m_isInJail;
  unsigned m_numberOfStation;               
  std::map<std::string,std::vector<City*> > m_boughtCities;
  int m_count;
};

#endif
