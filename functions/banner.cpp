#include "BusReservationSystem.h"
#include <iostream>
using namespace std;

void BusReservationSystem::bannerMenu() {
    cout << "\n\t\t\t========== WELCOME TO BUS RESERVATION SYSTEM ==========\n\n";
    cout << "\t\t1). Show All Buses\n";
    cout << "\t\t2). Book Tickets\n";
    cout << "\t\t3). Cancel Booking\n";
    cout << "\t\t4). Show Bus Status\n";
    cout << "\t\t0). Exit\n";
    cout << "\n\t\t===================================================================\n\n";
}