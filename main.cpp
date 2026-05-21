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



int main(){

    cout<<"-----------------FLIGHT BOOKING SYSTEM--------------------"<<endl;
     Flight f1("5:00am","10:00am", 67, "Muscat, Oman", "10/6/26", 1);
    Flight f2("6:30pm","10:00pm", 89,"London, United Kingdom","12/6/26", 2);
                                                                            //prebuilt flights for demonstration purposes

    Guest g1("Guest");                                                  //Prebuilt User-->Guest
    g1.setPasswword("pass123");

    Admin a1("Admin");                                                  //Prebuilt User-->Admin
    a1.setPasswword("pass123");

        int choice;
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

    
    cout<<"\n-----------------------------------------------------------"<<endl;
    cout<<"Available Flights: "<<endl;
    f1.display_flight();                                                        //My prebuilt flight (Placeholder)
    //an array that displays our available flights

    cout<<"------------------------------------------------------------"<<endl;
    cout<<"\nPlease select your next action: (Enter the number of action desirable): "<<endl;
    cout<<"1.Book a flight \n2.Cancel my booking"                              //What my user can do if they are a guest
          " \n3.My Booking info  \n4.User Settings"<<endl;
    cout<<"\n-------------------------------------------------------------"<<endl;

    int choice;
    cin>>choice;

    switch (choice)
    {
        case 1: cout<<"Please enter the number of the flight you want to book"<<endl;    //add exception handling
            int flight_number;
            cin>>flight_number;                                                 //Should sift through the array of flights
            f1.bookFlight();
            break;

        case 2: //Function to cancel by booking here
            break;

        case 3: //Function to display my booking info here
            break;

        case 4: //Function for user info manipulation here
            break;
        default: cout<<"Session expired";
            break;
    }

return 0;
}
