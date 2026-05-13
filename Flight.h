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
    vector<Booking> booking; //flight contains multiple bookings

public:
static int countBooking;
    Flight(){
        srand(time(0));// initializes random once
    }
    //constructor
    Flight(string dep, string arr, int flnum, string des ){
        departure = dep;
        arrival = arr;
        flight_num = flnum;
        destination = des;
        srand(time(0));
    }

    void display_flight(){
        cout << "Flight number " << flight_num << endl;
        cout << "Departure time  " << departure << endl;
        cout << "Arrival time  " << arrival << endl;
        cout << "Destination  " << destination << endl;

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

    //check if taimaa should add it to her part
    void bookFlight(){
    string seatClass;
    display_flight();
    cout << "Enter class (First / Business / Economy): " << endl;
    cin >> seatClass;

    //generate seat
    int seat = generateSeat(seatClass);

    //create booking (Taimaa)
    Booking b(departure, destination, "12-06-2026", arrival, "A1", seatClass, to_string(flight_num)); // add date and gate from booking class using composition
    booking.push_back(b);
    cout << "Seat assigned: " << seat << endl;
    cout << "Booking successful!\n";

    //to count num of bookings
    countBooking++ ;
    }
    //showing how many bookings per flight
    string showInfo(){
        string s = "Flight " + to_string(flight_num) + " to " + getDestination() + " has " + to_string (countBooking) + " bookings.";

        return s ;
    }

    //one flight has array of bookings
};
int Flight :: countBooking;


#endif //L1_FLIGHT_H
