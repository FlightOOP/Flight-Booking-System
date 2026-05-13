#ifndef L1_USER_H
#define L1_USER_H
#include <iostream>
#include <string>
#include<vector>
using namespace std;

class User{
protected:
    string user_name;

private:
    string password;
    long int phone_no;
    string bank_no;

public:
    User(){}
    void setPasswword(string p){
        password=p;
    }
    string getPassword(){
        return password;
    }

    void setPhone_no(long int phno){
        if (to_string(phno).length()==8){
            phone_no=phno;
        }
        else {cout<<"Phone number must be 8 digits long"<<endl;}
    }
    long int getPhone_no(){
        return phone_no;
    }

    void setBank_no(string b){
        bank_no=b;
    }
    string getBank_no(){
        return bank_no;
    }
    void setUser_name(string us){
        user_name=us;
    }
    string getUser_name(){
        return user_name;
    }
    //BOTH ADMIN AND GUEST USE THIS
    virtual void login(string usrnm)=0;
};


#endif //L1_USER_H
