#ifndef BUSRESERVATIONSYSTEM_H
#define BUSRESERVATIONSYSTEM_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BusReservationSystem  {
public:
    void loadingBar();
    void intro();
    void displayBusList(); 
    void bookTickets();
    void cancelBooking();
    void bannerMenu();
    void status();
private:
    void seat(int busNum, int& availableSeats);
    void nameNum(int busNum, int booking, int& availableSeats);
    void readNameNum(int busNum, int& availableSeats);
    void resetSeats();

    vector<string> bus{"Vireak Buntham Express", "e-Booking Express", "Larryta Express", "Angkor Express", "Phnom Penh Sorya Bus"};
    int busNum;
    string name[100];
    int num1[100] = {0}; // Initialize all elements to 0
    int phone[100] = {0};
};

#endif