#include <iostream>
#include <string>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;
#ifndef L1_BOOKING_H
#define L1_BOOKING_H


class Booking{
protected:
    User *user;//composition between user and booking
    string destinationFrom, destinationTo, date, time, gateNo, seatClass, flight;
    int seatNo;
    bool isCancelled;

public:
Booking(User* u , string destinationFrom, string destinationTo, string date, string time, string gateNo, string seatClass,
    string flight, int seatNo) : user(u), destinationFrom(destinationFrom), destinationTo(destinationTo), date(date),
    time(time), gateNo(gateNo), seatClass(seatClass), flight(flight), seatNo(seatNo), isCancelled(false){}
    //pssngrInfo is a friend of user (to get his info)
    void passengerInfo();
    void cancelBooking();
    void bookingInfo();
};


#endif //L1_BOOKING_H
