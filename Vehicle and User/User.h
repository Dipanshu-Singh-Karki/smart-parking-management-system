#ifndef USER_H
#define USER_H

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include"Vehicle.h"

using namespace std;

class User{
    private:
    string name;
    Vehicle *vehicle;

    public:
        User();
        User(string n, Vehicle *v);

        string getName();

        Vehicle* getVehicle();

        void display();
};

extern vector<User> users;

void registerUser();

void displayUser();

bool findUserByVehicleNumber(string vehicleNumber, User &user);

void saveUserToFile(User user);

void loadUsersFromFile();

void initializeUsers();

#endif