#include <iostream>
#include <string>
#include<vector>
#include<cstdlib>
#include<ctime>
#include "Guest.h"
#include "User.h"
using namespace std;

void Guest::login()  {
        string usrnm;
        cout<<"Enter your username: ";
        cin>>usrnm;
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
Guest::~Guest(){};
