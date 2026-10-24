#include<iostream>
#include"Vehicle and User/User.h"
#include"Parking SLot Allocation/Parking.h"
#include"Navigation and Reservation/Graph.h"
#include"Payment and Report/Payment.h"
using namespace std;

int main(){
    initializeParking();
    initializeGraph();
    initializeUsers();
    
    int choice;
    do{
        cout << "1. Register User\n";
        cout << "2. Display Users\n";
        cout << "3. Display Parking Slots\n";
        cout << "4. Park Vehicle\n";
        cout << "5. Remove Vehicle\n";
        cout << "6. Display Waiting Queue\n";
        cout << "7. Display Current Parking History\n";
        cout << "8. Display Permanent Parking History\n";
        cout << "9. Display Parking Map\n";
        cout << "10. Make Reservation\n";
        cout << "11. Display Reservations\n";
        cout << "12. Display Payments\n";
        cout << "13. Generate Daily Report\n";
        cout << "14. Exit\n";
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
                displayCurrentParkingHistory();
                break;
            case 8:
                displayPermanentHistory();
                break;
            case 9:
                displayParkingMap();
                break;
            case 10:
            {
                string vehicle;
                int slot;
                cout << "\nEnter Vehicle Number : ";
                cin >> vehicle;
                cout << "Enter Slot Number (1-12) : ";
                cin >> slot;
                reserveSlot(vehicle, slot);
                break;
            }
            case 11:
                displayReservations();
                break;
            case 12:
                displayPayments();
                break;
            case 13:
                generateReport();
                break;
            case 14:
                cout << "\nThank You.\n";
                return 0;
            default:
                cout << "\nInvalid Choice.\n";
        }
    }while(1);
    return 0;
}