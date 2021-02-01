#include "station.hpp"

	void Station::setName(std::string name)
	{
		m_name = name;
	}
	std::string Station::name() const
	{
		return m_name;
	}

	void Station::setPrice(unsigned price)
	{
		m_price = price;
	}
 	unsigned Station::price() const
 	{
 		return m_price;
 	}

	void Station::setMortgageValue(unsigned mortgageValue)
	{
		m_mortgageValue = mortgageValue;
	}
	unsigned Station::mortgageValue() const
	{
		return m_mortgageValue;
	}

        void Station::turnToMortgage()
        {
          m_owner->receive(m_mortgageValue);
          m_price = 0;
        }

	void Station::setOwner(Player* owner){
		m_owner = owner;
	}
	
	void Station::changeOwner(Player* newOwner)
	{
            m_isOwned=true;
            m_owner=newOwner;
	}


	void Station::action(Player& player){
            if(!m_isOwned)
            {
                std::string answer;
                std::cout << "Do you wish to buy this station? (yes/no)" << std::endl;
                std::cin >> answer;
				std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
    			if(answer=="yes" || answer=="y")
                {
                    player.pay(m_price);
                    changeOwner(&player);
                    player.setNumberOfStation(player.numberOfStation() + 1);
                    std::cout << "You just bought " << this->name() << std::endl;
                }
            }
            else if(m_owner != &player)
            {
                unsigned rent = (m_price * player.numberOfStation())/4;
                player.pay(rent);
                m_owner->receive(rent);
            }
        }


