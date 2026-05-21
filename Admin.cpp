#include <iostream>
#include <string>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;
#include "Admin.h"

//Admin member functions here
 void login() override;
    //ONLY ADMIN CAN CREATE FLIGHTS!!!!!!!!
     void createFlight(Flight &f, string departure_from, string arrival_dest, int flight_num, string destination );
