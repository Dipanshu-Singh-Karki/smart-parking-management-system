#include<iostream>
#include"Vehicle and User\User.h"
#include"Parking SLot Allocation\Parking.h"
#include"Navigation and Reservation\Graph.h"
#include"Payment and Report\Payment.h"
using namespace std;

int main(){
    initializeParking();
    initializeGraph();
    int choice;
    do{
        cout << "\nSMART PARKING MANAGEMENT SYSTEM\n";
        cout << "1. Register user\n";
        cout << "2. Display users\n";
        cout << "3. Display parking slots\n";
        cout << "4. Park vehicle\n";
        cout << "5. Remove vehicle\n";
        cout << "6. Display waiting queue\n";
        cout << "7. Display parking history\n";
        cout << "8. Display parking map\n";
        cout << "9. BFS route\n";
        cout << "10. Make reservation\n";
        cout << "11. Display reservation\n";
        cout << "12. Calculate Payment\n";
        cout << "13. Display Payments\n";
        cout << "14. Generate Daily Report\n";
        cout << "15. Exit\n";
        cout << "\nEnter the choice: ";
        cin>> choice;

        switch(choice){
            case 1:
                registerUser();
                break;
            case 2:
                displayUser();
                break;
            case 3:
                displaySlots();
                break;
            case 4:
                parkVehicle();
                break;
            case 5:
                removeVehicle();
                break;
            case 6:
                displayQueue();
                break;
            case 7:
                displayHistory();
                break;
            case 8:
                displayMap();
                break;
            case 9:
                BFS(0);
                break;
            case 10:
                makeReservation();
                break;
            case 11:
                displayReservation();
                break;
            case 12:
                calculatePayment();
                break;
            case 13:
                displayPayments();
                break;
            case 14:
                generateReport();
                break;
            case 15:
                cout <<"\nTHANK YOU\n";
                return 0;
            default:
                cout << "Invalid Choice\n";
                break;
        }
    }while(1);
    return 0;
}