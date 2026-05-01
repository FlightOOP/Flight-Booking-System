#include <iostream>
using namespace std;

class User{
    public:
    string user_name;
    User(){}
    protected:
    string password;
    public: //BOTH ADMIN AND GUEST USE THIS
    void login(string usrnm){
        if (usrnm==user_name){
            string tempp;
            cout<<"Enter password: "<<endl;
            cin>>tempp;
            if (tempp==password){
                cout<<"Login succesful! Welcome "<<user_name;
            }
            else {cout<<"Incorrect password. ";}
        }
            
    }
};
class Guest : public User{ //inherits from User
    public:
    Guest(string us, const string psswd) {
        user_name=us;
        password=psswd;
    }
    
};

class Admin: public User { //inherits from User
    public:
    Admin(string us, const string psswd) {
        user_name=us;
        password=psswd;
    }
};

class Booking{
protected:
    string destinationFrom, destinationTo, date, time, gateNo, seatClass, flight;
    int seatNo;
public:
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

class Flight{
    string departure;
    string arrival;
    int flight_num;
    string destination;

public:
    Flight(){}
    Flight(string dep, string arr, int flnum, string des ){
        departure = dep;
        arrival = arr;
        flight_num = flnum;
        destination = des;
    }
    void delay(){
        cout << "Flight " << flight_num << " Has been delayed " << endl;
    }
    void display_flight(){
        cout << "Flight number " << flight_num << endl;
         cout << "Departure time  " << departure << endl;        
         cout << "Arrival time  " << arrival << endl;        
         cout << "Destination  " << destination << endl;        

        
    }
    //one flight has array of bookings
};

int main(){
    Guest  u1("Name","abc123");
    u1.login("Name");
}
