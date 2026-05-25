#include <iostream>
#include <string>
#include<vector>
#include<cstdlib>
#include<ctime>
#include "Booking.h"
#include "Admin.h"
using namespace std;
#ifndef L1_FLIGHT_H
#define L1_FLIGHT_H

class Booking;
class User;

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
    Flight(string dep, string arr, int flnum, string des, string d, int gate );

     // operator == overloading    
    bool operator==(const Flight& other);

    static int countBooking;

    Flight();

    void display_flight();

    // getters and setters (not necessary to use )
    void setDeparture(string dep);
    string getDeparture();

    void setArrival(string arr);
    string getArrival();

    void setFlightNum(int num);
    int getFlightNum();

    void setDestination(string des);
    string getDestination();

     //after 20 bookings you wont be able to book ( flight is full )
    bool isFull();

    //seat randomizer
    int generateSeat(string seatClass);

    // deciding the seat class
    void bookFlight(User* currentUser);

    //showing how many bookings per flight
    string showInfo();

    vector<Booking>& getBookings();

    friend class Admin;    
    ~Flight();
};

#endif //L1_FLIGHT_H

