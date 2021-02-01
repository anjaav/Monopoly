#ifndef JAIL_H
#define JAIL_H
#include "field.hpp"

class Jail: public Field
{
public:
    std::string name()const override;	
    std::string className() const;
    
    void action(Player&);
};

#endif
