#include <iostream>
#include "BusReservationSystem.h"

using namespace std;

void BusReservationSystem::bookTickets() {
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
    int availableSeats = 16;
    resetSeats();  // Reset seat data before booking
    readNameNum(busNum, availableSeats);
    system("cls");
    seat(busNum, availableSeats);

    string fileName = "bus" + to_string(busNum) + ".txt";
    int booking = 0;
    
    if (availableSeats <= 0) {
        cout << "\n\t\tThere are no available seats on the bus\n\n";
        return;
    } else {
        cout << "\n\t\tAvailable seats -----> " << availableSeats << "\n\n";
        cout << "\t\tEnter number of tickets to book -----> ";
        cin >> booking;
        cin.ignore(); // Ensures the buffer is clear before the next input operation
    }
    if (booking > availableSeats) {
        cout << "\n\t\tNot enough available seats. Please try again.\n\n";
        return;
    } else {
        nameNum(busNum, booking, availableSeats);
        cout << "\n\nThank You For Using Our Service\n\n";
    }
}

