#ifndef IMPL_CHANCE_H
#define IMPL_CHANCE_H

#include "card.hpp"
#include "cardMove.hpp"
#include "cardTransfer.hpp"
#include "cardGetOutJail.hpp"
#include "cardGoToJail.hpp"
#include "cardGiveMoney.hpp"
#include "cardTakeMoney.hpp"
#include "player.hpp"
#include "field.hpp"

#include <vector>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <memory>


class VChance:public Field{
public:
    static VChance* getSample(){
        if( !_chanceSample ){
            _chanceSample = new VChance();
        }
        return _chanceSample;
    }
    
    void action(Player&);
    VChance(const VChance&) =delete;
    VChance& operator=(const VChance&) =delete;
    std::string name()const;

    std::string className() const;

private:
    static VChance* _chanceSample;
    std::vector<std::unique_ptr<Card> > m_vchance;
    size_t m_vsize;
    std::string m_name="CHANCE? ";
    
    void fillTheVector();
    
    VChance(){
        fillTheVector();
        m_vsize=m_vchance.size();
    }

};



#endif
