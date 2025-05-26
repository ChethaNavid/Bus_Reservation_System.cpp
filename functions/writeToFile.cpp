#include <iostream>
#include <fstream>
#include "BusReservationSystem.h"
using namespace std;

void BusReservationSystem::nameNum(int busNum, int booking, int& availableSeats) {
    string fileName = "bus" + to_string(busNum) + ".txt";

    for (int i = 0; i < booking; i++) {
        int number, phoneNum; 
        char confirm;
        while (true) {
            cout << "\n\n\t\t\t========== Enter the details for ticket no " << i + 1 << " ==========\n\n\n";
            cout << "\t\tEnter the seat number ---> ";
            cin >> number;
            cin.ignore();
            if (number < 1 || number > 16) {
                cout << "\n\t\tInvalid seat number. Please choose a different seat.\n";
                continue;
            }
            if (num1[number - 1] != 0) {
                cout << "\n\t\tThe seat number " << number << " is already booked. Please choose a different seat.\n";
            } else {
                break;
            }
        }
        cout << "\n\t\tEnter the name of person ---> ";
        getline(cin, name[number - 1]);
        cout << "\n\t\tEnter phone number ---> ";
        cin >> phoneNum;
        cin.ignore();
        phone[number - 1] = phoneNum;
        cout << "\n\t\tDo you want to book this seat? [Y/n]: ";
        cin >> confirm;
        cin.ignore();
        if(confirm == 'Y' || confirm == 'y'){
            cout << "\n\t\tSeat successfully reserved\n\n";
            num1[number - 1] = number; // Update seat number
            availableSeats--; // Decrease available seats
        } else{
            name[number - 1].clear(); // Reset the name if not confirmed
            phone[number - 1] = 0;
            i--; // Retry booking this seat
            continue;
        }
    }

    // Save booking details to file
    ofstream fileOut(fileName);
    if(fileOut.is_open()){
        fileOut << availableSeats << endl;
        for(int i = 0; i < 16; i++){
            if(num1[i] != 0){
                fileOut << num1[i] << " " << phone[i] << " " << name[i] << endl;
            }
        }
        fileOut.close();
    }

    // Display total booking amount
    if(busNum == 1){
        cout << "======================================================================================================\n";
        cout << "\t\t\t\tThe Total booking amount is " << 60000 * booking << " riel\n";
        cout << "======================================================================================================\n";
    } else if(busNum == 2){
        cout << "======================================================================================================\n";
        cout << "\t\t\t\tThe Total booking amount is " << 50000 * booking << " riel\n";
        cout << "======================================================================================================\n";
    } else if(busNum == 3){
        cout << "======================================================================================================\n";
        cout << "\t\t\t\tThe Total booking amount is " << 40000 * booking << " riel\n";
        cout << "======================================================================================================\n";
    } else if(busNum == 4){
        cout << "======================================================================================================\n";
        cout << "\t\t\t\tThe Total booking amount is " << 35000 * booking << " riel\n";
        cout << "======================================================================================================\n";
    } else{
        cout << "======================================================================================================\n";
        cout << "\t\t\t\tThe Total booking amount is " << 30000 * booking << " riel\n";
        cout << "======================================================================================================\n";
    }
}