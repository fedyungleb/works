#include <iostream>
#include "Composite.h"
#include "Leaf.h"







int main() {
 auto *computer = new Composite("Asus");
 auto *peripherals = new Composite("Peripherals");
 auto *cabinet = new Composite("Cabinet");
 auto *motherboard = new Composite("Motherboard");

 auto *cpu = new Leaf ("AMD Ryzen 5 5600X", 9509);
 auto *ram = new Leaf ("DDR4 RAM 16GB Apacer", 2919);
 auto *hdd = new Leaf("Seagate SkyHawk HDD 8TB", 13999);
 auto *ssd = new Leaf("Samsung 970 Evo series 1TB M.2", 6999);

auto *mouse= new Leaf("Logitech G Pro X", 4999);
auto *keyboard = new Leaf("SteelSeries Apex Pro", 11039);
auto *monitor = new Leaf("ASUS 64,5d ROG Swift", 221585);

motherboard->addComponent(cpu);
motherboard->addComponent(ram);

cabinet->addComponent(hdd);
cabinet->addComponent(ssd);


peripherals->addComponent(mouse);
peripherals->addComponent(keyboard);
peripherals->addComponent(monitor);

computer->addComponent(cabinet);
computer->addComponent(peripherals);
cabinet->addComponent(motherboard);


int a = 0;
std::cout<<"Choose an option:"<<std::endl<<"1. Show all elements"<<std::endl<<"2. Show only cabinet items"<<std::endl<<"3. Show only peripherals items"<<std::endl;
std::cin>>a;
    if (a==1)
        computer->ShowInfo();
    else if (a==2)
        cabinet->ShowInfo();
    else if(a==3)
        peripherals->ShowInfo();
    else
        std::cout<<"Incorrect input";




    return 0;
}
