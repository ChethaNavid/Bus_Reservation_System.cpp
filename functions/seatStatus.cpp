#include "BusReservationSystem.h"
#include <iostream>
#include <iomanip>

using namespace std;

void BusReservationSystem::seat(int busNum, int& availableSeats) {

    system("cls");
    cout << "\n\t\t\t========== BUS RESERVATION SYSTEM ==========\n\n\n";
    cout << "\t\tYour bus number is " << busNum << " -----> " << bus[busNum - 1] << "\n\n";
    if(busNum == 1){
        cout << "\t\tDestination: Phnom Penh -----> Siem Reap\n\n";
        cout << "\t\tDeparture time: 6:00AM\n\n";
    } else if(busNum == 2){
        cout << "\t\tDestination: Phnom Penh -----> Battambong\n\n";
        cout << "\t\tDeparture time: 6:30AM\n\n";
    } else if(busNum == 3){
        cout << "\t\tDestination: Phnom Penh -----> Preh Sihanoukville\n\n";
        cout << "\t\tDeparture time: 7:00AM\n\n";
    } else if(busNum == 4){
        cout << "\t\tDestination: Phnom Penh -----> Kep\n\n";
        cout << "\t\tDeparture time: 7:15AM\n\n";
    } else if(busNum == 5){
        cout << "\t\tDestination: Phnom Penh -----> Kompong Chnang\n\n";
        cout << "\t\tDeparture time: 7:30AM\n\n";
    }
    for (int i = 0; i < 16; i += 2) {
        cout << "\t\t" << setw(2) << right << i + 1 << ". ";
        if (num1[i] != 0) {
            cout << setw(20) << left << name[i];
        } else {
            cout << setw(20) << left << "[ ]";
        }
        cout << "\t\t" << setw(2) << right << i + 2 << ". ";
        if (num1[i + 1] != 0) {
            cout << setw(20) << left << name[i + 1];
        } else {
            cout << setw(20) << left << "[ ]";
        }
        cout << "\n";
    }
}

void BusReservationSystem::status() {
    system("cls");
    cout << "\n\t\t\t========== BUS RESERVATION SYSTEM ==========\n\n\n";
    displayBusList();
    cout << "\t\tEnter your bus choice: ";
    cin >> busNum;
    cin.ignore();
    if (busNum < 1 || busNum > 5) {
        cout << "\n\t\tInvalid choice, please try again\n";
        return;
    }
    system("cls");
    int availableSeats = 16;
    resetSeats();  // Reset seat data before displaying status
    readNameNum(busNum, availableSeats); // Read booked seats
    system("cls");
    seat(busNum, availableSeats);
    if (availableSeats == 16) {
        cout << "\n\t\tAll seats are available on bus number " << busNum << "\n\n"; // Display available seats
    } else {
        cout << "\n\t\tThere are " << availableSeats << " available seat(s) on bus number " << busNum << "\n\n"; // Display available seats and occupied seats
        for (int i = 0; i < 16; i++) {
            if (num1[i] != 0) {
                cout << "\t\tSeat number " << num1[i] << " is occupied by " << name[num1[i] - 1] << "\n\n"; // Display occupied seats
            }
        }
    }
}

void BusReservationSystem::resetSeats() {
    fill(begin(num1), end(num1), 0); // Reset num1 array
    fill(begin(name), end(name), "[ ]"); // Reset name array
    fill(begin(phone), end(phone), 0);
}