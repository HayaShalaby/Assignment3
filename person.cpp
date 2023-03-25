
#include "person.h"

void Person::setName(string name){
    Name = name;
}

string Person::getName(){
    return Name;
}

void Person::setID(int id){
    ID =id;
}

int Person::getID(){
    return ID;
}

void Person::setAge(int age){
    Age = age;
}

int Person::getAge(){
    return Age;
}

void Person::print(){
    cout << "Name: " << Name <<endl;
    cout << "ID: " << ID <<endl;
    cout << "Age: " << Age <<endl;
}

