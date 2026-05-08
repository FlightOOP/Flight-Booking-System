#include <iostream>
#include <string>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

class User{
    protected:
    string user_name;
    
    private:
    string password;
    long int phone_no;
    string bank_no;

    public: 
    User(){} 
    void setPasswword(string p){
        password=p;
    }
    string getPassword(){
        return password;
    }

    void setPhone_no(long int phno){
        if (to_string(phno).length()==8){
        phone_no=phno;
        }
        else {cout<<"Phone number must be 8 digits long"<<endl;}
    }
    long int getPhone_no(){
        return phone_no;
    }

    void setBank_no(string b){
        bank_no=b;
    }
    string getBank_no(){
        return bank_no;
    }
    void setUser_name(string us){
        user_name=us;
    }
    string getUser_name(){
        return user_name;
    }
    //BOTH ADMIN AND GUEST USE THIS
    virtual void login(string usrnm)=0;
};
class Guest : public User{ //inherits from User
    public:
    Guest(string us) {
        user_name=us;
    }
    void login(string usrnm) override {
        if (usrnm==user_name){
            string tempp;
            cout<<"Enter password Guest: "<<endl;
            cin>>tempp;
            string p=getPassword();
            if (tempp==p){ //user enetrs correct password
                cout<<"Login succesful! Welcome "<<user_name;
            }
            else {cout<<"Incorrect password. ";}
        }    
    }
};
class Admin: public User { //inherits from User
    public:
    Admin(string us) {
        user_name=us;
    }
    void login(string usrnm) override {
        if (usrnm==user_name){
            string tempp;
            cout<<"Enter password Admin: "<<endl;
            cin>>tempp;
            string p=getPassword();
            if (tempp==p){ //user enetrs correct password
                cout<<"Login succesful! Welcome "<<user_name;
            }
            else {cout<<"Incorrect password. ";}
        }    
    }
};


class Booking{
protected:
    string destinationFrom, destinationTo, date, time, gateNo, seatClass, flight;
    int seatNo;
public:
Booking(string destinationFrom, string destinationTo, string date, string time, string gateNo, string seatClass,
    string flight) : destinationFrom(destinationFrom), destinationTo(destinationTo), date(date),
    time(time), gateNo(gateNo), seatClass(seatClass), flight(flight){}
    //pssngrInfo is a friend of user (to get his info)
    void passengerInfo();
    void cancelBooking();
    void bookingInfo();
};
void Booking::passengerInfo(){
    cout << "Full Name: " << endl;
    cout << "Phone Number: " << endl;
}
void Booking::cancelBooking(){
    int n;
    cout << "Enter 1 to cancle your booking. \nEnter 0 to continue without canceling: ";
    cin >> n;
    if (n==1){cout << "Booking cancelled.\n";}
    else {cout << "Booking confirmed\n";}
}
void Booking::bookingInfo(){
    cout << "Your Booking has been Confirmed. Please Don't loose Your ticket.\n";
    cout << "Passenger Name: " << endl;
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

class Flight  {
private:
    string departure;
    string arrival;
    int flight_num;
    string destination;
    // add string seatclass
    vector<Booking> booking; //flight contains multiple bookings

public:
static int countBooking;
    Flight(){ 
        srand(time(0));// initializes random once
    }
    Flight(string dep, string arr, int flnum, string des ){
        departure = dep;
        arrival = arr;
        flight_num = flnum;
        destination = des;
        srand(time(0));
    }
    void delay(){
        cout << "Flight " << flight_num << " Has been delayed " << endl;    //Add randomizer here (not in booking?) 
    }
    void display_flight(){
        cout << "Flight number " << flight_num << endl;
        cout << "Departure time  " << departure << endl;        
        cout << "Arrival time  " << arrival << endl;        
        cout << "Destination  " << destination << endl;        
        
    }
    // getters and setters
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
    //create booking
    Booking b(departure, destination, "12-06-2026", arrival, "A1", seatClass, to_string(flight_num));
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

int main(){

    cout<<"-----------------FLIGHT BOOKING SYSTEM--------------------"<<endl;
    //Move main to it's own file 
}
