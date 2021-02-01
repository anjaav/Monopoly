#include "tax.hpp"

std::string Tax::name() const
{
  return std::string("Tax");
}

std::string Tax::className() const
{
	return std::string("tax");
}

void Tax::setTax(unsigned tax)
{
	m_tax = tax;
}

unsigned Tax::tax() const
{
	return m_tax;
}


void Tax::action(Player& player){
    std::cout << "You have to pay " << m_tax << "$" << std::endl;
    player.pay(m_tax);
    m_parking->reciveMoney(m_tax);
}
