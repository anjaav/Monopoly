#ifndef STATION_H
#define STATION_H

#include "field.hpp"
#include "player.hpp"
#include <algorithm>

class Station: public Field
{
public:
	Station(std::string name)
	:m_name(name)
	{
	    m_price = 200;
		m_mortgageValue = m_price/2;
		setOwner(NULL);
		m_isOwned=false;
	};

	void setName(std::string name);
	std::string name() const;

	void setPrice(unsigned price);
 	unsigned price() const;

	void setMortgageValue(unsigned mortgageValue);
	unsigned mortgageValue()  const;
    void turnToMortgage();

	void setOwner(Player* owner);
	Player* owner() const;

	bool isOwned() const;
	void changeOwner(Player* newOwner);

    void action(Player&);
private:
	std::string m_name;
	unsigned m_price;
	unsigned m_mortgageValue;
	Player* m_owner;
	bool m_isOwned;
};

#endif
