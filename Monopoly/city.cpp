#include "city.hpp"
#include "player.hpp"

std::string City::name() const{
    return m_name;
}
    
void City::setOwner(Player* newOwner){
    m_isOwned=true;
    m_owner=newOwner;
}

unsigned City::price() const{
    return m_price;
}

bool City::increaseNumHouses(){
    if(m_numHouses==4){
        std::cout<<"You have reached maximum number of houses for this city."<< std::endl;
        return 0;
    }
    m_price+=m_price/2;
    m_rent += m_price/3;
    m_owner->pay(m_price);
    m_numHouses++;
    m_mortgageValue+=m_mortgageValue/2;
    return 1;
}

unsigned City::numHouses() const{
    return m_numHouses;
}

std::string City::group() const{
    return m_group;
}

std::string City::className() const
{
    return std::string("city");
}

void City::turnToMortgage(){
    m_mortgage=true;
    m_owner->receive(m_mortgageValue);
}

bool City::mortgage() const{
    return m_mortgage;
}

void City::repayMortgage(){
    m_mortgage=false;
    m_owner->pay(m_mortgageValue);
}


unsigned City::rent() const{
    return m_rent;
}
void City::changeOwner(Player* newOwner)
{
   newOwner->pay(m_price); 
   m_owner->receive(m_price);

   std::map<std::string,std::vector<City*>> *cities = m_owner->boughtCities();
   auto i = cities->find(m_group);
   for(auto j = i->second.begin(); j != i->second.end(); j++)
   {
    if(this == (*j))
    {
        i->second.erase(j);
        break;
    }
   }

   m_owner = newOwner;
   m_owner->setCityInBoughtCities(this);

}

bool checkAnswer(std::string& answer){
    std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
    if(answer=="yes" || answer=="y")
        return true;
    return false;

}

void City::action(Player& player){
    if(!m_isOwned){ //not owned
        std::string answer;
        std::cout << "Do you wish to buy this city? (yes/no)" << std::endl;
        std::cin >> answer;
        if(checkAnswer(answer)) {
            player.buyCity(this);
            setOwner(&player);
            std::cout << "You just bought " << m_name << std::endl;
        }
    }
            
    else if(m_owner == &player){ //currentPlayer is the owner
        std::string answer;
        std::cout << "Do you wish to buy an improvement for this property? (yes/no)" << std::endl;
        std::cin >> answer;
        if(checkAnswer(answer)) {
            increaseNumHouses(); //method takes care of the payment and if it is allowed
        }
    }
    else{ //other player is the owner
        std::string answer;
        std::cout << player.name() << ", do you want to buy this city from the other player?! (yes/no)" << std::endl;
        std::cin >> answer;
        if(checkAnswer(answer)) {
            std::cout << m_owner->name() << ", do you want to sell this city? (yes/no)" << std::endl;
            std::cin >> answer;
            if(checkAnswer(answer)) 
                changeOwner(&player);
            else{
                unsigned rent = m_rent;
                player.pay(rent);   
                m_owner->receive(rent);
            }
        }
    }
}