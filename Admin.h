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


#endif //L1_ADMIN_H
