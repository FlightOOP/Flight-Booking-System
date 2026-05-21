#include <iostream>
#include <string>
#include<vector>
#include<cstdlib>
#include<ctime>
# include "Booking.h"
using namespace std;
#ifndef L1_FLIGHT_H
#define L1_FLIGHT_H

class Flight  {

private:
    string departure;
    string arrival;
    int flight_num;
    string destination;
    string seatClass;
    string date;
    int gate_number; 
    vector<Booking> booking; //flight contains multiple bookings

public:
     //constructor 
    Flight(string dep, string arr, int flnum, string des, string d, int gate ){
        departure = dep;
        arrival = arr;
        flight_num = flnum;
        destination = des;
        date = d;
        gate_number = gate;
        srand(time(0));
    }
     // operator == overloading    
    bool operator==(const Flight& other){
    return this->flight_num == other.flight_num;   }

    static int countBooking;

    Flight(){ 
        srand(time(0));// initializes random once
    }
   
    void display_flight(){
        cout << "Flight number " << flight_num << endl;
        cout << "Departure time  " << departure << endl;        
        cout << "Arrival time  " << arrival << endl;        
        cout << "Destination  " << destination << endl;    
        cout << "Date " << date << endl;
        cout << "Gate " << gate_number << endl;
    }

    // getters and setters (not necessary to use )
    void setDeparture(string dep){ departure = dep; }
    string getDeparture(){ return departure; }

    void setArrival(string arr){ arrival = arr; }
    string getArrival(){ return arrival; }

    void setFlightNum(int num){ flight_num = num; }
    int getFlightNum(){ return flight_num; }

    void setDestination(string des){ destination = des; }
    string getDestination(){ return destination; }

     //after 20 bookings you wont be able to book ( flight is full )
    bool isFull(){
        return booking.size() >= 20; // max seats
    }

    //seat randomizer
    int generateSeat(string seatClass){
    if(seatClass == "First"){
        return rand() % 20 + 1;
        }
    else if(seatClass == "Business"){
        return rand() % 40 + 21;
        }
    else{
        return rand() % 90 + 61;
        }
    }
    // deciding the seat class
    void bookFlight(User* currentUser){                                  
    // checking if there are available flights to be booked    
    if (isFull()) {
        cout << "This flight is fully booked!\n";
        return; // stop the function
    }
    string seatClass;
    display_flight();
    cout << "Enter class (First / Business / Economy): " << endl;       
    cin >> seatClass;
        
    //generate seat
    int seat = generateSeat(seatClass);
        
    //create booking 
    Booking b(currentUser, departure, destination, date, arrival, to_string( gate_number), seatClass, to_string(flight_num),seat); // add date and gate from booking class using composition
    booking.push_back(b);   
    cout << "Seat assigned: " << seat << endl;
    cout << "Booking successful!\n";                   
        
    //to count num of bookings 
    countBooking++ ; }

    //showing how many bookings per flight
    string showInfo(){
        string s = "Flight " + to_string(flight_num) + " to " + getDestination() + " has " + to_string (countBooking) + " bookings.";
        return s ;
    }
    
    friend class Admin;    
};
int Flight :: countBooking;

#endif //L1_FLIGHT_H
