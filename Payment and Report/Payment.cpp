#include "Payment.h"

Payment payments[100];
int paymentCount = 0;

void calculatePayment(){
    if(paymentCount==100){
        cout << "\nPayment list Full\n";
        return;
    }
    Payment p;
    cout << "Enter vehicle no.: ";
    cin >> p.vehicleNumber;

    cout << "Vehicle Type:\n";
    cout << "1. Car\n2.Bike\n";
    cout << "Enter the choice: ";
    int choice;
    cin >> choice;
    if(choice==1){
        p.vehicleType = "Car";
    }else{
        p.vehicleType = "Bike";
    }
    cout << "Enter parking hours: ";
    cin >> p.hours;

    if(p.vehicleType=="Car"){
        p.amount = p.hours * 40;
    }else{
        p.amount = p.hours *20;
    }

    payments[paymentCount++] = p;

    cout << "\nPayment generated successfully\n";
    cout << "Total amount = Rs. " << p.amount << endl;
}

void displayPayments(){
    if(paymentCount==0){
        cout << "\nNo payment record\n";
        return;
    }

    cout << "\nPayment Records: \n";
    
    for(int i=0; i<paymentCount; i++){
        cout << "\nRecord "<< i+1 << endl;
        cout << "Vehicle Number: " << payments[i].vehicleNumber << endl;
        cout << "Vehicle type: " << payments[i].vehicleType << endl;
        cout << "Hours: " << payments[i].hours <<endl;
        cout << "Amount: " << payments[i].amount << endl;
        cout << endl;
    }
}

void generateReport(){
    int totalCollection = 0, totalCars = 0, totalBikes = 0;
    
    for(int i=0; i<paymentCount; i++){
        totalCollection += payments[i].amount;
        if(payments[i].vehicleType=="Car"){
            totalCars++;
        }else{
            totalBikes++;
        }
    }
    cout << "\nDaily Report\n";
    cout << "\nTotal Vehicles: " << paymentCount << endl;
    cout << "Cars Parked: " << totalCars << endl;
    cout << "Bikes Parked: " << totalBikes << endl;
    cout << "Total Revenue: Rs." << totalCollection << endl;
}