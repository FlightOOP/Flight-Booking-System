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
    //ONLY ADMIN CAN CREATE FLIGHTS!!!!!!!!
     void createFlight(Flight &f, string departure_from, string arrival_dest, int flight_num, string destination ){
        f.setDeparture(departure_from);
        f.setArrival(arrival_dest);
        f.setFlightNum(flight_num);
        f.setDestination(destination);
    }
};


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

class Flight  {
private:
    string departure;
    string arrival;
    int flight_num;
    string destination;
    string seatClass;
    vector<Booking> booking; //flight contains multiple bookings

public:
 // operator == overloading    
bool operator==(const Flight& other){
    return this->flight_num == other.flight_num;
}

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
    void bookFlight(User* currentUser){
    string seatClass;
    display_flight();
    cout << "Enter class (First / Business / Economy): " << endl;
    cin >> seatClass;
        
    //generate seat
    int seat = generateSeat(seatClass);
        
    //create booking (Taimaa)
    Booking b(currentUser, departure, destination, "12-06-2026", arrival, "A1", seatClass, to_string(flight_num)); // add date and gate from booking class using composition
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
    friend class Admin;    
    //one flight has array of bookings
};
int Flight :: countBooking;

int main(){

    cout<<"-----------------FLIGHT BOOKING SYSTEM--------------------"<<endl;
    Flight f1("5am", "10am", 67, "Muscat, Oman");   //Our Admin should be the one to create this,
                                                    //but we have a prebuilt flight for demonstration purposes

    Guest g1("Guest 1");                                                  //Prebuilt User-->Guest
    g1.setPasswword("pass123");

    Admin a1("Admin 1");                                                  //Prebuilt User-->Admin
    a1.setPasswword("pass123");

    cout<<"Please enter 1 for Admin, and 0 for Guest"<<endl;
    cout<<"----->";

    int specify;
    cin>>specify;                                                          //**Will add exception handling after we learn it**
    if (specify==1)
    {
        a1.login("Admin 1");
    }
    if (specify==0)
    {
        g1.login("Guest 1");
    }

    cout<<"\n-----------------------------------------------------------"<<endl;
    cout<<"Available Flights: "<<endl;
    f1.display_flight();                                                        //My prebuilt flight (Placeholder)
    //an array that displays our available flights

    cout<<"------------------------------------------------------------"<<endl;
    cout<<"\nPlease select your next action: (Enter the number of action desirable): "<<endl;
    cout<<"1.Book a flight \n2.Cancel my booking"                              //What my user can do if they are a guest
          " \n3.My Booking info  \n4.User Settings"<<endl;
    cout<<"\n-------------------------------------------------------------"<<endl;

    int choice;
    cin>>choice;

    switch (choice)
    {
        case 1: cout<<"Please enter the number of the flight you want to book"<<endl;
            int flight_number;
            cin>>flight_number;                                                 //Should sift through the array of flights
            f1.bookFlight(&g1);
            break;

        case 2: //Function to cancel by booking here
            break;

        case 3: //Function to display my booking info here
            break;

        case 4: //Function for user info manipulation here
            break;
        default: cout<<"Session expired";
            break;
    }
    //Move main to it's own file 
    return 0;
}
