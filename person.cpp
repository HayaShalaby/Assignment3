#include<iostream> 
#include "person.h"
using namespace std;

Person::Person(string name, int id, int age){
    Name = name;
    ID = id;
    Age = age;
}

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

