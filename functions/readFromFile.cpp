#include <iostream>
#include <fstream>
#include "BusReservationSystem.h"

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