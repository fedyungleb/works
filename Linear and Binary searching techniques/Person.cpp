//
// Created by User on 26.05.2021.
//
#include <algorithm>
#include "Person.h"

Person::Person(int id, int age, const std::string &name, int weight) : id(id), age(age), name(name), weight(weight) {}

int Person::getId() const {
    return id;
}

int Person::getAge() const {
    return age;
}

const std::string &Person::getName() const {
    return name;
}

int Person::getWeight() const {
    return weight;
}

int Person::binarySearchWithId(int id) {

    int l =0;
    int r = list_of_persons.size()-1;



    while (l <= r){
        int m = l + (r - 1) / 2;
        if (list_of_persons[m]->getId()==id){
            return m;
        }
        if (list_of_persons[m]->getId()<id){
            l=m+1;
        }else{
            r=m-1;
        }
        return -1;
    }




    return 0;
}

bool Person::comparingWithAge(Person *p1, Person *p2) {


    return p1->getId()<p2->getId();
}
Person::Person() {
    auto *Hlib = new Person(2034,17,"Hlib",58);
    auto *Pavlo = new Person(1456,25,"Pavlo",60);
    auto *Roman = new Person(9346,18,"Roman",75);
    auto *Egor = new Person(2900,54,"Egor",95);
    auto *Dmytro = new Person(4124,18,"Dmytro",68);
    list_of_persons.push_back(Hlib);
    list_of_persons.push_back(Pavlo);
    list_of_persons.push_back(Roman);
    list_of_persons.push_back(Egor);
    list_of_persons.push_back(Dmytro);
    sortPersonWithId();
}
void Person::sortPersonWithId() {
    sort(list_of_persons.begin(), list_of_persons.end(), comparingWithAge);
}