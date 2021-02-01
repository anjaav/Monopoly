#include "vchance.hpp"


void VChance::action(Player& player){
    unsigned i=rand() % m_vsize;
    std::cout << m_vchance[i]->chanceMessage() << std::endl;
    m_vchance[i]->action(player);    
}
    


void VChance::fillTheVector() {
    m_vchance.push_back(std::make_unique<CardTransfer>("Advance to Go\n(Collect $200)\n",0));
    m_vchance.push_back(std::make_unique<CardGiveMoney>("Bank pays you dividend of $50\n",50));
    m_vchance.push_back(std::make_unique<CardMove>("Go 3 steps forward\n",3));
    m_vchance.push_back(std::make_unique<CardTransfer>("Advance to Illinois Ave\nIf you pass Go, collect $200\n",23));
    m_vchance.push_back(std::make_unique<CardGetOutJail>("You received the\n'Get Out of Jail Free' card\n"));
    m_vchance.push_back(std::make_unique<CardMove>("Go Back 3 Spaces\n",-3));
    
    m_vchance.push_back(std::make_unique<CardGetOutJail>("You received card 'Get out of jail'\nYou can keep it and use it when you need it.\n"));
    m_vchance.push_back(std::make_unique<CardGoToJail>("Go to Jail\nGo directly to Jail\nDo not pass Go, do not collect $200\n"));
    m_vchance.push_back(std::make_unique<CardMove>("Go Back 3 Spaces\n",-3));
    m_vchance.push_back(std::make_unique<CardTransfer>("Advance to St. Charles Place\nIf you pass Go, collect $200\n",16));
    m_vchance.push_back(std::make_unique<CardTakeMoney>("Pay tax of 70\n",70));
    m_vchance.push_back(std::make_unique<CardGoToJail>("Go to Jail\nGo directly to Jail\nDo not pass Go, do not collect $200\n"));
    m_vchance.push_back(std::make_unique<CardGiveMoney>("Your building and loan matures\nCollect $150\n",150));
    
    m_vchance.push_back(std::make_unique<CardTakeMoney>("Pay poor tax of $15\n",15)); 
    m_vchance.push_back(std::make_unique<CardMove>("Go 3 steps forward\n",3));
    m_vchance.push_back(std::make_unique<CardTransfer>("Take a trip to Reading Railroad\nIf you pass Go, collect $200\n",34));
    m_vchance.push_back(std::make_unique<CardTakeMoney>("Pay school tax $50\n",50));
    m_vchance.push_back(std::make_unique<CardGiveMoney>("You have won a crossword competition\nCollect $100\n",100));
    m_vchance.push_back(std::make_unique<CardGoToJail>("Go to Jail\nGo directly to Jail\nDo not pass Go, do not collect $200\n"));
    m_vchance.push_back(std::make_unique<CardGetOutJail>("You received card 'Get out of jail'\nYou can keep it and use it when you need it.\n"));
}

    
std::string VChance::name()const{
    return m_name;
}

std::string VChance::className() const
{
    return std::string("vchance");
}
