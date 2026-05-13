#include <iostream>
#include <string>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;
#include "User.h"
#ifndef L1_GUEST_H
#define L1_GUEST_H


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


#endif //L1_GUEST_H
