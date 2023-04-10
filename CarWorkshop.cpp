
#include<fstream>
#include<cstdlib>
#include "person.h"
#include "customer.h"
#include "mechanic.h"
#include "queue.h"
#include "appointment.h"



int main(){
    int mechCount;
    cout << "Please enter number of mechanics:" <<endl;
    cin >> mechCount;

    ifstream file1("mechanics.txt"); //opening the mechanics file for read 
    Mechanic *mechanics = new Mechanic [mechCount]; //creating an array of type Mechanic 
    string str;
    int i=0, h, m;
    while(getline(file1, str)){ //reading mechanics' info from the file 
        mechanics[i].setName(str);
        cin >> str;
        mechanics[i].setID(stoi(str));
        cin >> str;
        mechanics[i].setAge(stoi(str));
        cin >> str;
        mechanics[i].setCounter(stoi(str));
        for(int j=0; j<stoi(str); j++){
            cin >> h;
            cin >> m;

            Appointment app;
            app.hours = h;
            app.mins = m;
            mechanics[i].setBooking(app);
        }
        i++;
    }
    file1.close();


    int custCount;
    cout << "Please enter number of customers:" <<endl;
    cin >> custCount;
    ifstream file2("customers.txt"); //opening customers file for read 
    Customer *customers = new Customer [custCount]; //creating an array of type Customer 
    string str2;
    int x=0, h2, m2;
    while(getline(file2, str2)){ //reading customers' info from the file 
        customers[x].setName(str2);
        cin >> h2;
        cin >> m2;

        Appointment custApp;
        custApp.hours = h2;
        custApp.mins = m2;
        customers[x].setAppointment(custApp);
        x++;
    }
    file2.close();

    bool flag = false;
    for(int i=0; i<x; i++){ //assigning a mechanic for each customer according to their appointment and the mechanic's availability 
        for(int j=0; j<mechCount; j++){
            if(mechanics[j].isAvailable(customers[i].getAppointment().hours, customers[i].getAppointment().mins)){
                flag = true;
                customers[i].setMechanicID(mechanics[j].getID());
            }
        }
        if(flag == false) //if no mechanic was found to be available at the time of this customer's appointment 
            customers[i].setMechanicID(-1);
    }


    Customer temp;
    for (int i = 0; i < x; i++) { //sorting the customers array in ascending order 
        for (int j = i + 1; j < x; j++) {
            if(customers[i].getAppointment().hours > customers[j].getAppointment().hours || (customers[i].getAppointment().hours == customers[j].getAppointment().hours && customers[i].getAppointment().mins > customers[j].getAppointment().mins  ) ) { //had to do this because the overloaded operator is not working
                temp = customers[i];
                customers[i] = customers[j];
                customers[j] = temp;
            }
        }
    }


    queue<Customer>q(0);
    for (int i = 0; i < x; i++){ //pushing the ordered customers array into queue 
        q.push(customers[i]);
    }

    for(int i=0; i<x; i++){ //outputting the customers' info and their assigned mechanics 
        customers[i] = q.pop();
        if(customers[i].getMechanicID() == -1)
            cout << "We could not find an available mechanic for " << customers[i].getName() <<endl;
        else{
            customers[i].print();
            cout << "should be assigned to mechanic " << customers[i].getMechanicID() << " at " << customers[i].getAppointment().hours << ":" << customers[i].getAppointment().mins <<endl;
        }
    }

    delete[] customers;
    delete[] mechanics;

    return 0;
}
