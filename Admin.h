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
    void login() override;
    
    //ONLY ADMIN CAN CREATE FLIGHTS!!!!!!!!
     void createFlight(Flight &f, string departure_from, string arrival_dest, int flight_num, string destination ); 
};

#endif //L1_ADMIN_H
