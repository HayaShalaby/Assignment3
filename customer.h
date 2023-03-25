#include<iostream>
#include "person.h"
#include "appointment.h"
#ifndef customer_h
#define customer_h
using namespace std; 

class Customer : public Person{
    int mechanicID;
    Appointment appointment;

    public:
        Customer(): Person(){} //class default constructor 
        void setMechanicID(int mechid); //setter for the mechanicID variable 
        int getMechanicID(); //getter for the mechanicID variable 
        void setAppointment(Appointment app); //setter for the appointment object 
        Appointment getAppointment(); //getter for the appointment object 

        bool operator== (const Appointment &app); //function that overrides the = operator to compare two objects of type Appointment 
        bool operator> (const Appointment &app); //function that overrides the > operator to compare two objects of type Appointment 
        bool operator< (const Appointment &app); //function that overrides the < operator to compare two objects of type Appointment 

};


#endif
