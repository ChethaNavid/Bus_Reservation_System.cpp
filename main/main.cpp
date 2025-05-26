#include "../header/BusReservationSystem.h"
#include <iostream>

using namespace std;

int main() {
    int choice;
    BusReservationSystem bus;
    bus.loadingBar();
    bus.intro();
    do {
        system("cls");
        bus.bannerMenu();
        cout << "\t\tPlease enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 0:
                cout << "\n\t\tThe program is turned off\n\n";
                exit(0);
                break;
            case 1:
                bus.displayBusList();
                break;
            case 2:
                bus.bookTickets();
                break;
            case 3:
                bus.cancelBooking();
                break;
            case 4: 
                bus.status();
                break;
            default:
                cout << "\n\t\tInvalid Choice Selection\n";
                break;
        }
        cout << "\nPress Enter to continue...";
        cin.ignore();
    } while (choice != 0);
    return 0; 
}