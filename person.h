#include<iostream>
#ifndef person_h
#define person_h
using namespace std; 

class Person{
    protected: 
        string Name;
        int ID; 
        int Age;

    public: 
        Person(){} //class default constructor 
        void setName(string name); //setter for the Name variable
        string getName(); //getter for the Name variable 
        void setID(int id); //setter for the ID variable 
        int getID(); //getter for the ID variable 
        void setAge(int age); //setter for the age variable 
        int getAge(); //getter for the age variable 
        void print(); //prints all the Person object's information 
};

#endif
