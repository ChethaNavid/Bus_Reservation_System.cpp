#include "BusReservationSystem.h"
#include <iostream>
#include <fstream>

using namespace std;

void BusReservationSystem::cancelBooking() {
    int seat_no, phone_num, i;
    bool seatFound = false;
    char confirm;
    system("cls");
    displayBusList();
    cout << "\n\t\tEnter the bus number ----> ";
    cin >> busNum;
    cin.ignore();
    if (busNum < 1 || busNum > 5) {
        cout << "\t\tInvalid choice, please try again\n";
        return;
    }
    int availableSeats = 16;
    
    resetSeats(); // Reset seat data before cancelling
    readNameNum(busNum, availableSeats);
    system("cls");
    seat(busNum, availableSeats);
    if(availableSeats == 16) {
        cout << "\n\t\tNo booking seat found on the bus.\n";
        return;
    }
    cout << "\n\n\t\t\t========== Canceling Tickets ==========\n\n";
    cout << "\n\t\tEnter your seat number to cancel ---> ";
    cin >> seat_no;
    cin.ignore();
    if (seat_no < 1 || seat_no > 16) {
        cout << "\n\t\tInvalid seat number. Please choose a different seat.\n";
        return;
    }
    cout << "\n\t\tEnter your phone number ---> ";
    cin >> phone_num;
    cin.ignore();
    cout << "\n\t\tDo you want to cancel this seat? [Y/n]: ";
    cin >> confirm;
    cin.ignore();
    if(confirm != 'Y' && confirm != 'y'){
        cout << "\n\t\tCancellation canceled" << endl;
        return;
    }

    for (i = 0; i < 16; i++) {
        if (num1[i] == seat_no) {
            if(phone[i] == phone_num) {
                seatFound = true;
                num1[i] = 0;
                name[i] = "Empty";
                phone[i] = 0;
                availableSeats++;
                break;
            } else {
                cout << "\n\t\tIncorrect phone number. Please try again\n";
                return;
            }
        } 
    }

    if (seatFound) {
        string filename = "bus" + to_string(busNum) + ".txt";
        ofstream fileOut(filename);
        if (fileOut.is_open()) {
            fileOut << availableSeats << endl;
            for (int i = 0; i < 16; ++i) {
                if (num1[i] != 0) {
                    fileOut << num1[i] << " " << phone[i] << " " << name[i] << endl;
                }
            }
            fileOut.close();
        }
        cout << "\n\t\tSeat canceled successfully\n\n";

        if(busNum == 1){
            cout << "======================================================================================================\n";
            cout << "\t\t\t\tYour 60000 riel has been Returned\n";
            cout << "======================================================================================================\n";
        } else if(busNum == 2){
            cout << "======================================================================================================\n";
            cout << "\t\t\t\tYour 50000 riel has been Returned\n";
            cout << "======================================================================================================\n";
        } else if(busNum == 3){
            cout << "======================================================================================================\n";
            cout << "\t\t\t\tYour 40000 riel has been Returned\n";
            cout << "======================================================================================================\n";
        } else if(busNum == 4){
            cout << "======================================================================================================\n";
            cout << "\t\t\t\tYour 35000 riel has been Returned\n";
            cout << "======================================================================================================\n";
        } else{
            cout << "======================================================================================================\n";
            cout << "\t\t\t\tYour 30000 riel has been Returned\n";
            cout << "======================================================================================================\n";
        }
    } else {
        cout << "\n\t\tThe seat hasn't been booked or is already empty. Please try again\n";
    }
}