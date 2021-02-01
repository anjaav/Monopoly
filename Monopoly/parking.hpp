#ifndef PARKING_H
#define PARKING_H
#include "field.hpp"
#include "player.hpp"


class Parking: public Field
{
public:
	Parking(){
		m_money = 0;
	}

	void giveMoney(Player &player);
	void reciveMoney(unsigned money);

	std::string name()const override;
        
    void action(Player&);

private:
	unsigned m_money;
};

#endif
