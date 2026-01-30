#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n = "", int a = 0);
    virtual void displayDetails() = 0;   
                      
};

#endif
