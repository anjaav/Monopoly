#ifndef IMPL_CHEST_H
#define IMPL_CHEST_H

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
#include <utility>
#include <memory>


class VChest:public Field{
public:
    static VChest* getSample(){
        if( !_chestSample ){
            _chestSample = new VChest();
        }
        return _chestSample;
    }
    
    void action(Player&);
    std::string name()const;
    VChest(const VChest&) =delete;
    VChest& operator=(const VChest&) =delete;

    
private:
    static VChest* _chestSample;
    std::vector<std::unique_ptr<Card>> m_vchest;
    size_t m_vsize;
    std::string m_name="COMMUNITY CHEST? ";
    
    void fillTheVector();
    
    VChest(){
        fillTheVector();
        m_vsize=m_vchest.size();
    }

};



#endif