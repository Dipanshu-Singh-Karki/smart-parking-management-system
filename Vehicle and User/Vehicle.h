#ifndef VEHICLE_H
#define VEHICLE_H

#include<iostream>
#include<string>
using namespace std;

class Vehicle{
    protected:
        string vehicleNo;
        string vehicleType;
    
    public:
        Vehicle(string number, string type){
            vehicleNo = number;
            vehicleType = type;
        }

        string getVehicleNo(){
            return vehicleNo;
        }

        string getVehicleType(){
            return vehicleType;
        }

        virtual void display(){
            cout << "Vehicle Number: " << getVehicleNo() << endl;
            cout << "Vehicle Type: " << getVehicleType() << endl;
        }

        virtual ~Vehicle(){
        }
};

class car: public Vehicle{
    public:
        car(string number):Vehicle(number, "Car"){}
};

class bike: public Vehicle{
    public:
        bike(string number):Vehicle(number, "Bike"){}
};

#endif