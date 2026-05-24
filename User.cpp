#include <iostream>
#include <string>
#include<vector>
#include "User.h"
using namespace std;

void User::setPhone_no(){
        long long int phno;
        cin>>phno;
        while (true) {
            if (to_string(phno).length()==8){
            phone_no=phno;
            break;
            }
            else {cout<<"Phone number must be 8 digits long"<<endl;}
        }
    }
