#include <string>
#include<vector>
#include<cstdlib>
#include<ctime>
#include <iostream>
using namespace std;

int main(){

    cout<<"-----------------FLIGHT BOOKING SYSTEM--------------------"<<endl;
    Flight f1("5am", "10am", 67, "Muscat, Oman");   //Our Admin should be the one to create this,
                                                    //but we have a prebuilt flight for demonstration purposes

    Guest g1("Guest 1");                                                  //Prebuilt User-->Guest
    g1.setPasswword("pass123");

    Admin a1("Admin 1");                                                  //Prebuilt User-->Admin
    a1.setPasswword("pass123");

    cout<<"Please enter 1 for Admin, and 0 for Guest"<<endl;
    cout<<"----->";

    int specify;
    cin>>specify;                                                          //**Will add exception handling after we learn it**
    if (specify==1)
    {
        a1.login("Admin 1");
    }
    if (specify==0)
    {
        g1.login("Guest 1");
    }

    
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
        case 1: cout<<"Please enter the number of the flight you want to book"<<endl;
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
