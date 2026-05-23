#include <iostream>
#include <string>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;
#include "Flight.h"
#include "Booking.h"

//constructor 
Flight::Flight(string dep, string arr, int flnum, string des, string d, int gate ){
    departure = dep;
    arrival = arr;
    flight_num = flnum;
    destination = des;
    date = d;
    gate_number = gate;
    srand(time(0));
}

// default constructor

Flight::Flight(){ 
    srand(time(0);// initializes random once }

// operator == overloading   

bool Flight::operator==(const Flight& other){
    return this->flight_num == other.flight_num;  }

// static variable initialization

int Flight::countBooking = 0;

void Flight::display_flight(){
    cout << "Flight number " << flight_num << endl;
    cout << "Departure time  " << departure << endl;        
    cout << "Arrival time  " << arrival << endl;        
    cout << "Destination  " << destination << endl;    
    cout << "Date " << date << endl;
    cout << "Gate " << gate_number << endl;  }

// getters and setters (not necessary to use )

void Flight::setDeparture(string dep){ departure = dep; }
string Flight::getDeparture(){ return departure; }

void Flight::setArrival(string arr){ arrival = arr; }
string Flight::getArrival(){ return arrival; }

void Flight::setFlightNum(int num){ flight_num = num; }
int Flight::getFlightNum(){ return flight_num; }

void Flight::setDestination(string des){ destination = des; }
string Flight::getDestination(){ return destination; }


//after 20 bookings you wont be able to book ( flight is full )

bool Flight::isFull(){
    return booking.size() >= 20; // max seats }

//seat randomizer

int Flight::generateSeat(string seatClass){
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

void Flight::bookFlight(User* currentUser){                                  
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
    Booking b(currentUser, departure, destination, date, arrival,
              to_string(gate_number), seatClass,
              to_string(flight_num), seat); // add date and gate from booking class using composition

    booking.push_back(b);
    cout << "Seat assigned: " << seat << endl;
    cout << "Booking successful!\n";                   
        
    //to count num of bookings 
    
    countBooking++;
}

//showing how many bookings per flight

string Flight::showInfo(){
    string s = "Flight " + to_string(flight_num) + " to " +
               getDestination() + " has " +
               to_string(countBooking) + " bookings.";
    return s ;
}
