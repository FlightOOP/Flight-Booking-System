#include <iostream>
using namespace std;

class User{

};
class Guest : public User{ //inherits from User
  
};

class Admin: public User { //inherits from User
};

class Gates{
    //gates exist no matter what
};
class Booking{
    
};
class Flight{
    Gates* gate; //
    Booking bookings;
    //one flight has array of bookings
};


