#include <string>
#include<vector>
#include<cstdlib>
#include<ctime>
#include <stdexcept>
#include <iostream>
#include "User.h"
#include "Guest.h"
#include "Admin.h"
#include "Booking.h"
#include "Flight.h"
#include "Class_Admin.cpp"
#include "Class_User.cpp"
#include "Class_Guest.cpp"
#include "Class_Booking.cpp"
#include "Class_Flight.cpp"
using namespace std;



int getChoice(int choice)
{
    if (choice !=0 && choice != 1)
    {
        throw logic_error("Invalid input!");
    }
    return choice;
}

void Create_Admin(string username, string password,vector<Admin>& admins)
{
    Admin a(username);
    a.setPasswword(password);
    long int phone_number;
    cout<<"\nPHONE NUMBER: Enter 8 digit phone number: "; cin>>phone_number;
    a.setPhone_no(phone_number);
    admins.emplace_back(a);
}

void Create_Guest(string username, string password, vector<Guest>& guests)
{
    Guest g(username);
    g.setPasswword(password);
    long int phone_number;
    cout<<"\nPHONE NUMBER: Enter 8 digit phone number: "; cin>>phone_number;
    g.setPhone_no(phone_number);
    guests.emplace_back(g);
}



int main(){

    cout<<"-----------------FLIGHT BOOKING SYSTEM--------------------"<<endl;
     Flight f1("5:00am","10:00am", 67, "Muscat, Oman", "10/6/26", 1);
    Flight f2("6:30pm","10:00pm", 89,"London, United Kingdom","12/6/26", 2);
                                                                            //prebuilt flights for demonstration purposes

    Guest g1("Guest");                                                  //Prebuilt User-->Guest
    g1.setPasswword("pass123");

    Admin a1("Admin");                                                  //Prebuilt User-->Admin
    a1.setPasswword("pass123");

    vector<Flight> flights = {f1, f2};                                  //Vectors that stores objects for display
    vector<Guest> guests = {g1};
    vector<Admin> admins = {a1};

        int choice;

    do
    {
        cout<<"\n--------------------------WELCOME--------------------------"<<endl;
        //Does the user want to sign up or login?
        do{
            try
            {
                cout<<"Please enter 1 to sign-up and 0 to log-in: "<<endl;
                cin>>choice;
                getChoice(choice);

            }
            catch (const logic_error& e)
            {
                cout<<e.what()<<endl;
            }
        }while (choice != 0 && choice != 1);

        if (choice == 1)                    //USER CHOSE TO SIGN UP
        {
            cout<<"\n-----------------------SIGNING UP------------------------"<<endl;
            cout<<"ACCOUNT TYPE: "<<"Please Enter 1 for Admin or 0 for Guest: "<<endl;
            do
            {
                try
                {
                    cin>>choice;
                    getChoice(choice);
                }
                catch (const logic_error& e)
                {
                    cout<<e.what()<<endl;
                }
            }while (choice != 0 && choice != 1);

            if (choice == 1)                //USER CHOSE TO SIGN UP AS ADMIN
            {
                string username; string password;

                cout<<"USERNAME: "; cin>>username;
                cout<<"\nPASSWORD: "; cin>>password;
                Create_Admin(username, password, admins);
                cout<<"\nADMIN ACCOUNT CREATED SUCCESSFULLY";
            }
            if (choice == 0)                //USER CHOSE TO SIGN UP AS GUEST
            {
                string username; string password;
                cout<<"USERNAME: "; cin>>username;
                cout<<"\nPASSWORD: "; cin>>password;
                Create_Guest(username, password, guests);
                cout<<"\nGUEST ACCOUNT CREATED SUCCESSFULLY"<<endl;
            }
            choice=1;
        }
    }while (choice==1);

    cout<<"----------------------------LOG IN------------------------------"<<endl;     //USER LOGIN

    cout<<"Please enter 1 to login as an Admin or a 0 to login as a Guest: "<<endl;
    do
    {
        try
        {
            cin>>choice;
            getChoice(choice);
        }
        catch (const logic_error& e)
        {
            cout<<e.what()<<endl;
        }
    }while (choice != 0 && choice != 1);

    if (choice == 1)
    {
        cout<<"Please Select Admin Account: "<<endl;                    //LOGIN AS ADMIN
        for (int i = 0; i < admins.size(); i++) {
            cout << i<<". "<< admins[i].getUser_name() <<endl;
        }
        int choice; cin>>choice;
        admins[choice].login();
    }

    if (choice==0)
    {
        cout<<"Please Select Guest Account: "<<endl;                   //LOGIN AS GUEST
        for (int i = 0; i < guests.size(); i++)
        {
            cout << i<<". "<< guests[i].getUser_name() <<endl;
        }
        int choice; cin>>choice;
        guests[choice].login();
    }


    cout<<"\n-----------------------------------------------------------"<<endl;
    cout<<"Available Flights: "<<endl;
    for (Flight& f : flights) {
        cout<<"\n"<<"--------------------"<<endl;
        f.display_flight();
    }

   
   
return 0;
}
