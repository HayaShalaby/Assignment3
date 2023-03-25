#include<iostream>
#include "person.h"
#include "appointment.h"
#ifndef mechanic_h
#define mechanic_h
using namespace std;

class Mechanic: public Person{
    int Counter; //number of appointments tha mechanic has 
    Appointment *Bookings = new Appointment [Counter]; //array containing the appointments the mechanic has

    public:
        Mechanic(string name="", int id=0, int age=0, int counter=0): Person(name, id, age){} //default class constructor 
        bool isAvailable(int hrs, int min); //checks if mechanic is available at the time given by the parameters 
        void setCounter(int counter); //setter for Counter variable 
        int getCounter(); //getter for Counter variable 
        void setBooking(Appointment booking); //setter which sets the given element in the Bookings array 
        Appointment getBookings(); //getter which returns the pointer to the Bookings array 

};

#endif
