#ifndef START_H
#define START_H
#include "field.hpp"

class Start: public Field {
public:
    std::string name()const override;
    std::string className() const;

    void action(Player&);
};

#endif
