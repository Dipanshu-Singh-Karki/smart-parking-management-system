#include<iostream>
#include"Vehicle and User/User.h"
#include"Parking SLot Allocation/Parking.h"
#include"Navigation and Reservation/Graph.h"
#include"Payment and Report/Payment.h"
using namespace std;

int main(){
    initializeParking();
    initializeGraph();
    cout << graph[0].name << endl;
cout << graph[1].name << endl;
cout << graph[2].name << endl;
cout << graph[11].name << endl;
    int choice;
    do{
        cout << "1. Register User\n";
        cout << "2. Display Users\n";
        cout << "3. Display Parking Slots\n";
        cout << "4. Park Vehicle\n";
        cout << "5. Remove Vehicle\n";
        cout << "6. Display Waiting Queue\n";
        cout << "7. Display Parking History\n";
        cout << "8. Display Parking Map\n";
        cout << "9. Make Reservation\n";
        cout << "10. Display Reservations\n";
        cout << "11. Display Payments\n";
        cout << "12. Generate Daily Report\n";
        cout << "13. Exit\n";
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
                displayParkingMap();
                break;
            case 9:
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
            case 10:
                displayReservations();
                break;
            case 11:
                displayPayments();
                break;
            case 12:
                generateReport();
                break;
            case 13:
                cout << "\nThank You.\n";
                return 0;
            default:
                cout << "\nInvalid Choice.\n";
        }
    }while(1);
    return 0;
}