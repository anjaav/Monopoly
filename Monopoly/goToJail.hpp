#ifndef GOTOJAIL_H
#define GOTOJAIL_H
#include "field.hpp"

class GoToJail: public Field
{
public:
    std::string name()const;
    std::string className() const;
    
    void action(Player&);
};

#endif
