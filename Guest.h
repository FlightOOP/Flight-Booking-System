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
    void login() override;
};


#endif //L1_GUEST_H
