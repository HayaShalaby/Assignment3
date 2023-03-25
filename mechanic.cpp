#include<iostream> 
#include "person.h"
#include "mechanic.h"
using namespace std;

Mechanic::Mechanic(string name, int id, int age, int counter): Person(name, id, age){
     Counter = counter;
}

bool Mechanic::isAvailable(int hrs, int min){
    for(int i=0; i<Counter; i++){
        if(Bookings[i].hours == hrs && Bookings[i].mins == min)
            return false;
    }

    return true;
}

void Mechanic::setCounter(int counter){
    Counter = counter;
}

int Mechanic::getCounter(){
    return Counter;
}

void Mechanic::setBooking(Appointment booking){
    Bookings[Counter] = booking;
}

Appointment Mechanic::getBookings(){
    return *Bookings;
}