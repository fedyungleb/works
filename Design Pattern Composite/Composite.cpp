//
// Created by User on 28.05.2021.
//

#include "Composite.h"
#include "Color.h"
Composite::Composite(const std::string &name) : name(name) {}
void Composite::ShowInfo() {
    Color::setConsoleColor(5);
std::cout<<name<<std::endl;
    for (Component *c: list_of_components) {
        c->ShowInfo();

    }
}
void Composite::addComponent(Component *item) {
    list_of_components.push_back(item);
}
double Composite::getPrise() {

    double total = 0.0;
    for(Component *c: list_of_components){
        total += c->getPrise();
    }
    return total;
}


