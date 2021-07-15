//
// Created by User on 28.05.2021.
//

#ifndef DESIGN_PATTERN_COMPOSITE_LEAF_H
#define DESIGN_PATTERN_COMPOSITE_LEAF_H
#include "Component.h"
#include <iostream>
#include <list>



class Leaf:public Component
 {
public:
     void ShowInfo() override;
    double getPrise() override;

public:
    Leaf(const std::string &name, double price);

private:
     std::string name;
     double price;


};


#endif //DESIGN_PATTERN_COMPOSITE_LEAF_H
