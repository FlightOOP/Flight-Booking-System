#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <string>
#include "Admin.h"
#include "User.h"
#include "Guest.h"
#include "Booking.h"
#include "Flight.h"

using namespace std;


int getChoice(int choice)                                        //Function for handling exception (entering invalid choices)
{
    if (choice !=0 && choice != 1)
    {
        throw logic_error("Invalid input! Please choose valid action");
    }
    return choice;
}

int getAction(int action)                                        //Function for handling exception (Entering invalid actions)
{
    if (action!=0 && action !=1 && action !=2 && action !=3 && action !=4 && action !=5 && action !=6 && action !=7)
    {
        throw logic_error("Invalid input! Please choose valid action!");
    }
    return action;
}

void Create_Admin(string username, string password,vector<Admin>& admins)            //function that creates a new admin account
{
    Admin a(username);
    a.setPasswword(password);
    cout<<"\nPHONE NUMBER: Enter 8 digit phone number: ";
    a.setPhone_no();
    admins.emplace_back(a);
}

void Create_Guest(string username, string password, vector<Guest>& guests)        //Function that cretes a new guest account
{
    Guest g(username);
    g.setPasswword(password);
    cout<<"\nPHONE NUMBER: Enter 8 digit phone number: ";
    g.setPhone_no();
    guests.emplace_back(g);
}

void Create_Flight(vector<Flight>& flights )                                           //Function that creates a flight
{
    string departure, arrival, destination, date;
    int flight_num, gate_number;

    cout<<"\n Enter required information :";
    cout<<"\nDeparture: "; cin>>departure;
    cout<<"\nArrival: "; cin>>arrival;
    cout<<"\nFlight Number: "; cin>>flight_num;
    cin.ignore();
    cout<<"\nDestination: "; getline(cin, destination);
    cout<<"\nDate: "; cin>>date;
    cout<<"\nGate Number: "; cin>>gate_number; cout<<endl;

    Flight f(departure, arrival, flight_num, destination, date, gate_number);
    flights.emplace_back(f);
}


int main(){


    cout<<"-----------------FLIGHT BOOKING SYSTEM--------------------"<<endl;        //First thing the user sees
    Flight f1("5:00am","10:00am", 67, "Muscat, Oman", "10/6/26", 1);
    Flight f2("6:30pm","10:00pm", 89,"London, United Kingdom","12/6/26", 2);        //Prebuilt Flights for demonstration purposes 


    Guest g1("Guest");                                                              //Prebuilt User-->Guest
    g1.setPasswword("pass123");


    Admin a1("Admin");                                                              //Prebuilt User-->Admin
    a1.setPasswword("pass123");


    vector<Flight> flights = {f1, f2};                                              //Vectors that stores objects for display
    vector<Guest> guests = {g1};
    vector<Admin> admins = {a1};
    
    while (true)                                                                 //An endless loop that gives the effect of a website page
    {
        int choice;     //First it will be used to determine wherether the user signs-up or log-in then it will distinguish a guest from an admin
        do
        {
            cout<<"\n--------------------------WELCOME--------------------------"<<endl;
            //Does the user want to sign up or login?                                        //User is given the option to sign up or login
            do{
                try
                {
                    cout<<"Please enter 1 to sign-up and 0 to log-in: ";
                    cin>>choice;
                    getChoice(choice);                                               //Exception handling 

                }
                catch (const logic_error& e)
                {
                    cout<<e.what()<<endl;
                }
            }while (choice != 0 && choice != 1);

            if (choice == 1)                                                        //USER CHOSE TO SIGN UP
            {
                cout<<"\n-----------------------SIGNING UP------------------------"<<endl;
                cout<<"ACCOUNT TYPE: "<<"Please Enter 1 for Admin or 0 for Guest: ";
                do
                {
                    try
                    {
                        cin>>choice;                                                
                        getChoice(choice);                                            //exception handling
                    }
                    catch (const logic_error& e)
                    {
                        cout<<e.what()<<endl;
                    }
                }while (choice != 0 && choice != 1);

                if (choice == 1)                                                    //USER CHOSE TO SIGN UP AS ADMIN
                {
                    string username; string password;

                    cout<<"USERNAME: "; cin>>username;
                    cout<<"\nPASSWORD: "; cin>>password;
                    Create_Admin(username, password, admins);
                    cout<<"\nADMIN ACCOUNT CREATED SUCCESSFULLY";
                }
                if (choice == 0)                                                    //USER CHOSE TO SIGN UP AS GUEST
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

        cout<<"----------------------------LOG IN------------------------------"<<endl;     //USER CHOOSES TO LOGIN

        cout<<"\nPlease enter 1 to login as an Admin or a 0 to login as a Guest: ";
        do
        {
            try
            {
                cin>>choice;
                getChoice(choice);                                              //exception handling 
            }
            catch (const logic_error& e)
            {
                cout<<e.what()<<endl;
            }
        }while (choice != 0 && choice != 1);

        User* currentUser = nullptr;                                            //a pointer that points towards the account that will login
    
        int userr;                                                              //determines which user logs in 
        if (choice == 1)
        {
            cout<<"\nPlease Select Admin Account: "<<endl;                       //LOGIN AS ADMIN
            for (int i = 0; i < admins.size(); i++) {
                cout << i<<". "<< admins[i].getUser_name() <<endl;
            }
            cin>>userr;
            admins[userr].login();
            currentUser = &admins[userr];                                      //pointer points towards address of admin account 
        }

        if (choice==0)
        {
            cout<<"\nPlease Select Guest Account: "<<endl;                       //LOGIN AS GUEST
            for (int i = 0; i < guests.size(); i++)
            {
                cout << i<<". "<< guests[i].getUser_name() <<endl;
            }
            cin>>userr;
            guests[userr].login();
            currentUser = &guests[userr];                                        //pointer points towards address of guest account

        }


        while (true)
        {
            cout<<"\n-----------------------------------------------------------"<<endl;
            cout<<"Available Flights: "<<endl;

            for (int i = 0; i < flights.size(); i++)                                //Displaying all available flights for booking 
            {
                cout<<i<<". "<<endl;
                flights[i].display_flight();
                cout<<endl;
            }


            if (choice == 0)
            {
                cout<<"------------------------------------------------------------"<<endl;
                cout<<"\nPlease select your next action: (Enter the number of action desirable): "<<endl;
                cout<<"0.Logout \n1.Book a flight \n2.Cancel my booking"                                             //What my Guest can do
                      " \n3.My Booking info  \n4.User Settings"<<endl;
                cout<<"\n-------------------------------------------------------------"<<endl;
            }

            if (choice == 1)
            {
                cout<<"------------------------------------------------------------"<<endl;
                cout<<"\nPlease select your next action: (Enter the number of action desirable): "<<endl;
                cout<<"0.Logout \n5.Create a Flight \n6.Show Flight Info"                                              //What my Admin can do
                      "\n7.Cancel a Flight \n4.User Settings"<<endl;
                cout<<"\n-------------------------------------------------------------"<<endl;
            }

            int action;                                                       //used to determine what the guest/admin wants to do in our system
            int index = 0;
            do
            {
                try
                {
                    cin>>action;
                    getAction(action);                                        //exception handling
                }
                catch (const logic_error& e)
                {
                    cout<<e.what()<<endl;
                }
            }while (action !=0 && action !=1 && action !=2 && action !=3 && action !=4 && action !=5 && action !=6 && action !=7);


            int option;                                                    //will be used for choosing a booking in a flight in case 2
            switch (action)
            {
            case 0:  //LOGGIN OUT OF ACCOUNT (GUEST AND ADMIN)
                cout<<"\nSafe Travels! \n----------------------LOGGED OUT SUCCESSFULLY-------------------------";    //goes back to main page
                break;




            case 1:   //BOOKING A FLIGHT  (GUEST)
                if (choice ==1) {cout<<"\n Invalid input!"; break;}
                cout<<"\nPlease enter the choice of the flight you want to book: ";
                int flight_number;
                cin>>flight_number;

                flights[flight_number].bookFlight(currentUser);       

                break;




            case 2: //CANCELLING A BOOKING (GUEST)
                if (choice ==1) {cout<<"\n Invalid input!"; break;}

                for (Flight& f : flights) {
                    for (Booking& b : f.getBookings()) {          //Shows the guest his bookings           
                        cout<<index<<". ";
                        b.bookingInfo();
                    }
                    index++;
                }
                index = 0;

                cout<<"\nWhich Booking would you like to cancel: (-1 to cancel operation)"; cin>>option;
                if (option == -1)
                {
                    break;
                }
                for (Flight& f : flights) {
                    vector<Booking>& bookings = f.getBookings();   //loops throught each flight's bookings and finding which one the user wants 
                    for (int i = 0; i < bookings.size(); i++) {
                        if (index == option) {
                            bookings.erase(bookings.begin() + i);
                            cout<<"\nBOOKING CANCELLED";
                            break;
                        }
                        index++;
                    }
                }
                break;


            case 3: //DISPLAYING MY BOOKINGS AND THEIR INFO (GUEST )
                if (choice ==1) {cout<<"\n Invalid input!"; break;}
                cout << "\n Below are your bookings: " << endl;            
                for (Flight& f : flights) {
                    for (Booking& b : f.getBookings()) {           //loops through the flighs' bookings and displaying the ones belonging to the account 
                        b.bookingInfo();
                    }
                }
                break;





            case 4: //MANIPULATING USER INFORMATION (GUEST AND ADMIN)
                do
                {
                    cout<<"------------USER SETTINGS--------------"<<"\n0.Back \n 1.Username \n2.Password \n3.Phone Number";
                    cout<<"\n Please choose the number corresponding to the info you want to update: ";
                    while (true)
                    {
                        cin>>option;
                        if (option == 0 || option == 1 || option == 2 || option == 3){ break;}
                        cout<<"\n Invalid input. pick again: ";
                    }

                    if (option == 1)
                    {
                        string us;
                        cout<<"\nNew Username: "; cin>>us;            //calls setter for username

                        if (choice == 0)
                        {
                            guests[userr].setUser_name( us);
                        }
                        if (choice == 1)
                        {
                            admins[userr].setUser_name(us);
                        }
                    }

                    if (option == 2)                
                    {
                        string p;
                        cout<<"\nNew Password: "; cin>>p;            //calls setter for password

                        if (choice == 0)
                        {
                            guests[userr].setPasswword( p);
                        }
                        if (choice == 1)
                        {
                            admins[userr].setPasswword(p);
                        }
                    }
                    if (option == 3)
                    {
                        if (choice == 0)                            //calls function for setting phone number 
                        {
                            guests[userr].setPhone_no();
                        }
                        if (choice == 1)
                        {
                            admins[userr].setPhone_no();
                        }
                    }
                }while (option != 0);

                break;



            case 5: //CREATING A FLIGHT (ADMIN)
                if (choice ==0) {cout<<"\n Invalid input!"; break;}

                Create_Flight(flights);
                cout<<"\n FLIGHT CREATED SUCCESSFULLY"<<endl;        //calls the creating flight function
                break;




            case 6: //SHOWING FLIGHT CAPACITY (ADMIN)
                if (choice ==0) {cout<<"\n Invalid input!"; break;}       
                for (int i = 0; i < flights.size(); i++)
                {
                    cout << i<<". "<< flights[i].showInfo() <<endl;
                }
                break;




            case 7: // CANCELLING FLIGHTS (ADMIN)
                if (choice ==0) {cout<<"\n Invalid input!"; break;}    

                cout<<"\nChoose a Flight to cancel: ";
                cin>>flight_number;
                flights.erase(flights.begin() + flight_number);        //takes flight number and erases it from vector
                cout<<"\n FLIGHT CANCELLED SUCCESSFULLY"<<endl;
                break;



            default: cout<<"Session expired"; //EXITING THE SYSTEM
                abort();
            }
            if (action ==0){ break;}
        }
    }
}
