#include <iostream>
#include <vector>
#include <unistd.h>
#include "BusReservationSystem.h"

using namespace std;

void BusReservationSystem::displayBusList() {
    vector<string> bus{"Vireak Buntham Express", "e-Booking Express", "Larryta Express", "Angkor Express", "Phnom Penh Sorya Bus"};

    system("cls");
    cout << "\n\t\t\t========== BUS RESERVATION SYSTEM ==========\n\n\n";
    cout << "\t\t1) => " << bus[0] << "\n";
    cout << "\t\tPhnom Penh ---> Siem Reap\n";
    cout << "\t\tDeparture time: 6:00AM\n";
    cout << "\t\tPrice: 60000 riel\n\n";
    cout << "\t\t2) => " << bus[1] << "\n";
    cout << "\t\tPhnom Penh ---> Battambong\n";
    cout << "\t\tDeparture time: 6:30AM\n";
    cout << "\t\tPrice: 50000 riel\n\n";
    cout << "\t\t3) => " << bus[2] << "\n";
    cout << "\t\tPhnom Penh ---> Preh Sihanoukville\n";
    cout << "\t\tDeparture time: 7:00AM\n";
    cout << "\t\tPrice: 40000 riel\n\n";
    cout << "\t\t4) => " << bus[3] << "\n";
    cout << "\t\tPhnom Penh ---> Kep\n";
    cout << "\t\tDeparture time: 7:15AM\n";
    cout << "\t\tPrice: 35000 riel\n\n";
    cout << "\t\t5) => " << bus[4] << "\n";
    cout << "\t\tPhnom Penh ---> Kompong Chnang\n";
    cout << "\t\tDeparture time: 7:30AM\n";
    cout << "\t\tPrice: 30000 riel\n";
    cout << "\n\t\t===================================================================\n\n";
}