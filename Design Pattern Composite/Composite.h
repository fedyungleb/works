//
// Created by User on 28.05.2021.
//

#ifndef DESIGN_PATTERN_COMPOSITE_COMPOSITE_H
#define DESIGN_PATTERN_COMPOSITE_COMPOSITE_H
#include "Component.h"
#include <iostream>
#include <list>

class Composite : public Component {
public:
void ShowInfo() override;
void addComponent(Component *item);
double getPrise() override;

Composite(const std::string &name);



private:
    std::string name;
    std::list<Component*>list_of_components;
};


#endif //DESIGN_PATTERN_COMPOSITE_COMPOSITE_H
