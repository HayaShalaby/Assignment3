
#include "customer.h"
#include "appointment.h"




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
