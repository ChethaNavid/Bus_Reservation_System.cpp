#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <unistd.h>
#include "../header/BusReservationSystem.h"

using namespace std;

void BusReservationSystem::loadingBar() {
    for (int i = 0; i <= 100; i += 5) {
        system("cls"); 

        cout << "\n\n\n\n\t\t\t\t";
        cout << i << "% Loading...\n\n\t\t";
        cout << "";

        for (int j = 0; j < i; j += 2) {
            cout << " ";
        }
        usleep(100000);
        if (i == 90 || i == 50 || i == 96 || i == 83) {
            usleep(100000);
        }
    }
}

void BusReservationSystem::intro()  
{
    cout << "\n\n\n";
    usleep(100000);
    cout << "\t\t *           * ****  *     ***  ***   *     * ****" << endl;
    usleep(100000);
    cout << "\t\t  *         *  *     *    *    *   *  * * * * *"<< endl;
    usleep(100000);
    cout << "\t\t   *   *   *   ****  *    *    *   *  *  *  * ****" << endl;
    usleep(100000);
    cout << "\t\t    * * * *    *     *    *    *   *  *     * *" << endl;
    usleep(100000);
    cout << "\t\t     *   *     ****  ****  ***  ***   *     * ****" << endl;
    usleep(100000);
    cout<<endl;
    cout<<"\t\t====================================================\n"<<endl;
    usleep(500000);
    cout<<"\t\t\t   THIS IS BUS RESERVATION SYSTEM \n"<<endl;
    usleep(500000);
    cout<<"\t\t===================================================="<<endl;
    usleep(500000);
    cout << "\n\n";
    cout<<"\t\t Press Enter to continue...";
    cin.ignore();
    
}

void BusReservationSystem::bannerMenu() {
    cout << "\n\t\t\t========== WELCOME TO BUS RESERVATION SYSTEM ==========\n\n";
    cout << "\t\t1). Show All Buses\n";
    cout << "\t\t2). Book Tickets\n";
    cout << "\t\t3). Cancel Booking\n";
    cout << "\t\t4). Show Bus Status\n";
    cout << "\t\t0). Exit\n";
    cout << "\n\t\t===================================================================\n\n";
}

void BusReservationSystem::displayBusList() {
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

void BusReservationSystem::resetSeats() {
    fill(begin(num1), end(num1), 0); // Reset num1 array
    fill(begin(name), end(name), "[ ]"); // Reset name array
    fill(begin(phone), end(phone), 0);
}

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

void BusReservationSystem::readNameNum(int busNum, int& availableSeats) {

    resetSeats(); // Reset seat before reading new data
    
    string filename = "bus" + to_string(busNum) + ".txt";
    ifstream file(filename);
    if (!file.is_open()) return;
    file >> availableSeats;
    file.ignore(); // Ignore the newline character after availableSeats
    
    int number, phoneNum;
    string passengerName;
     while (file >> number) {
        file.ignore(); // Ignore space between number and name
        file >> phoneNum;
        file.ignore();
        getline(file, passengerName);
        num1[number - 1] = number;
        name[number - 1] = passengerName;
        phone[number - 1] = phoneNum;
    }
    file.close();
}

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
                name[i] = "[ ]";
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
