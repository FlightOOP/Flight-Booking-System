#include <iostream>
#include <string>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;
#ifndef L1_ADMIN_H
#define L1_ADMIN_H
#include "User.h"

class Admin: public User { //inherits from User
    public:
    Admin(string us) {
        user_name=us;
    }
    void login() override {
        string usrnm;
        cout<<"Enter your username: ";
        cin>>usrnm;
        
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

#endif //L1_ADMIN_H
