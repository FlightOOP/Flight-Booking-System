#include <iostream>
#include <string>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;
#include "Booking.h"

void Booking::passengerInfo(){
    cout << "Full Name: " << user->getUser_name() << endl;
    cout << "Phone Number: " << user->getPhone_no() << endl;
}
void Booking::cancelBooking(){
    isCancelled = true;
    cout << "Booking cancelled.\n";
}
void Booking::bookingInfo(){
    cout << "\n----- Booking Info -----\n";

    if (isCancelled){
        cout << "Status: Cancelled\n";
    } else {
        cout << "Status: Confirmed\n";
        cout << "Passenger Name: " << user->getUser_name() << endl;
        cout << "Date: " << date << endl;
        cout << "Flight: " << flight << endl;
        cout << endl;
        cout << "Boarding Time: " << time << endl;
        cout << endl;
        cout << "Destination from " << destinationFrom << " to " << destinationTo << endl;
        cout << "class: " << seatClass << endl;
        cout << "Seat Number: " << seatNo << endl;
        cout << "Gate Number: " << gateNo << endl;
    }
}
Booking::~Booking(){};
