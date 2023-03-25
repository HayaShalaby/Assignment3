#include<iostream>
#include "customer.h"
#include "appointment.h"
using namespace std;


Customer::Customer(string name, int id, int age, int mechid, int hr, int min): Person(name, id, age){
    mechanicID = mechid;
    appointment.hours = hr;
    appointment.mins = min;
}

void Customer::setMechanicID(int mechid){
    mechanicID = mechid;
}

int Customer::getMechanicID(){
    return mechanicID;
}

void Customer::setAppointment(Appointment app){
    appointment = app;
}

Appointment Customer::getAppointment(){
    return appointment;
}

bool Customer::operator== (const Appointment &app){
    if(app.hours == appointment.hours && app.mins == appointment.mins)
        return true;
    else 
        return false;
}

bool Customer::operator> (const Appointment &app){
    if(app.hours > appointment.hours)
        return true;
    else if(app.hours == appointment.hours){
        if(app.mins > appointment.mins)
            return true;
    }

    return false;
 }


bool Customer::operator< (const Appointment &app){
     if(app.hours < appointment.hours)
        return true;
    else if(app.hours == appointment.hours){
        if(app.mins < appointment.mins)
            return true;
    }

    return false;
 }
