#include <iostream>
#include <string>
#include<vector>
#include<cstdlib>
#include<ctime>
#include "Flight.h"
#include "Booking.h"
#include "User.h"

//  Static variable definition 
int Flight::countBooking = 0;

//  Constructors
Flight::Flight() {
    srand(time(0));}

Flight::Flight(string dep, string arr, int flnum, string des, string d, int gate) {
    departure = dep;
    arrival = arr;
    flight_num = flnum;
    destination = des;
    date = d;
    gate_number = gate;
    srand(time(0));
}

//  Operator Overload 
bool Flight::operator==(const Flight& other) {
    return this->flight_num == other.flight_num;
}

//  Display 
void Flight::display_flight() {
    cout << "Flight number " << flight_num << endl;
    cout << "Departure time  " << departure << endl;
    cout << "Arrival time  " << arrival << endl;
    cout << "Destination  " << destination << endl;
    cout << "Date " << date << endl;
    cout << "Gate " << gate_number << endl;
}

//  Getters & Setters 
void Flight::setDeparture(string dep) { departure = dep; }
string Flight::getDeparture() { return departure; }

void Flight::setArrival(string arr) { arrival = arr; }
string Flight::getArrival() { return arrival; }

void Flight::setFlightNum(int num) { flight_num = num; }
int Flight::getFlightNum() { return flight_num; }

void Flight::setDestination(string des) { destination = des; }
string Flight::getDestination() { return destination; }

// Checking if there are any available bookings left
bool Flight::isFull() {
    return booking.size() >= 20;
}

int Flight::generateSeat(string seatClass) {
    if (seatClass == "First") {
        return rand() % 20 + 1;
    }
    else if (seatClass == "Business") {
        return rand() % 40 + 21;
    }
    else {
        return rand() % 90 + 61;
    }
}

void Flight::bookFlight(User* currentUser) {

    if (isFull()) {
        cout << "This flight is fully booked!\n";
        return;
    }

    string seatClassInput;
    display_flight();

    cout << "Enter class (First / Business / Economy): " << endl;
    cin >> seatClassInput;

    int seat = generateSeat(seatClassInput);

    Booking b(currentUser, departure, destination, date, arrival,
              to_string(gate_number), seatClassInput,
              to_string(flight_num), seat);

    booking.push_back(b);

    cout << "Seat assigned: " << seat << endl;
    cout << "Booking successful!\n";

    countBooking++;
}

// return booking information that is stored in bookFlight() function
vector<Booking>& Flight::getBookings() {   
    return booking;
}

// flight Info 
string Flight::showInfo() {
    return "Flight " + to_string(flight_num) + " to " + destination +
           " has " + to_string(countBooking) + " bookings.";
}
