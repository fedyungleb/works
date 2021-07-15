//
// Created by User on 28.05.2021.
//

#include "Leaf.h"
#include "Color.h"

Leaf::Leaf(const std::string &name, double price) : name(name), price(price) {}
    void Leaf::ShowInfo(){
    Color::setConsoleColor(6);
        std::cout<< name << ":"<<std::endl<< price << "UAH"<< std::endl;
    }
    double Leaf::getPrise()
    {
        return price;
    }

