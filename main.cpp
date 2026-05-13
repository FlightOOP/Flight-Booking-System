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

return 0;
}
