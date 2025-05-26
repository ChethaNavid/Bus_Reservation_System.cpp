#include <iostream>
#include <unistd.h>
#include "BusReservationSystem.h"
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