//
// Created by User on 26.05.2021.
//

#ifndef PRACTISE_PERSON_H
#define PRACTISE_PERSON_H
#include <iostream>
#include "vector"


class Person {
    int id;
    int age;
    std::string name;
    int weight;
    std::vector<Person*>list_of_persons;
public:
    Person();
    Person(int id, int age, const std::string &name, int weight);

    int getId() const;

    int getAge() const;

    const std::string &getName() const;

    int getWeight() const;


    int binarySearchWithId (int id);
    void sortPersonWithId();

    static bool comparingWithAge(Person *p1, Person *p2);


};


#endif //PRACTISE_PERSON_H
