#include <iostream>
using namespace std;

class User{
    public:
    string user_name;
    User(){}
    protected:
    string password;
    public: //BOTH ADMIN AND GYEST USE THIS
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
    
};

class Flight{
    Booking bookings;
    //one flight has array of bookings
};

int main(){
    Guest  u1("Name","abc123");
    u1.login("Name");
}
