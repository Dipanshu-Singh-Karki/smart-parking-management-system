#include "Payment.h"

Payment payments[100];
int paymentCount = 0;

void displayCurrentPayments(){
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
    cout << endl;
}

void addPayment(string vehicleNumber, string vehicleType, int hours, int amount){
    payments[paymentCount].vehicleNumber = vehicleNumber;
    payments[paymentCount].vehicleType = vehicleType;
    payments[paymentCount].hours = hours;
    payments[paymentCount].amount = amount;
    ofstream file("paymentHistory.txt");
    if(!file){
        cout << "\nError in opening 'parkingHistory.txt'\n";
        return;
    }
    file << payments[paymentCount].vehicleNumber << ","
         << payments[paymentCount].vehicleType << ","
         << payments[paymentCount].hours << ","
         << payments[paymentCount].amount << endl;
    file.close();
    paymentCount++;
}

void displayPremanentPaymentHistory(){
    ifstream file("parkingHistory.txt");
    if(!file){
        cout << "\nError in opepning 'parkingHistory.txt'\n";
        return;
    }

    cout << "\nPermanent payment History: \n";
    string vehicle;
    string type;
    string hours;
    string amount;
    while(getline(file, vehicle, ',') &&
          getline(file, type, ',') &&
          getline(file, hours, ',') &&
          getline(file, amount)){
            cout << "Vehicle Number: " << vehicle << endl;
            cout << "Vehicle type : " << type << endl;
            cout << "Hours: " << hours << endl;
            cout << "Amount: Rs." << amount << endl;
            cout << endl;
          }
    file.close();
}
