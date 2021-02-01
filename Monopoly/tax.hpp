#ifndef TAX_H
#define TAX_H


#include "parking.hpp"
#include "field.hpp"


class Tax: public Field
{
public:
	Tax(const std::string name, unsigned tax, Parking* parking)
	: m_name(name), m_tax(tax), m_parking(parking) {
	}

	std::string name()const;
	std::string className() const;

	void setTax(unsigned tax);
	unsigned tax() const;
        
    void action(Player&);	
private:
	std::string m_name;
	unsigned m_tax;
        Parking* m_parking;
};

#endif
