/* abstract class Field */

#ifndef FIELD_H
#define FIELD_H

#include <string>
#include "player.hpp"

class Field{
public:
    virtual std::string name()const=0;
    virtual void action(Player&)=0;

    virtual ~Field(){}
};


#endif
