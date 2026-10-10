#include"User.h"

vector<User> users;

User::User(string n, Vehicle *v){
    name = n;
    vehicle = v;
};

string User::getName(){
    return name;
}

Vehicle* User::getVehicle(){
    return vehicle;
}

void User::display(){
    cout << endl;
    cout << "User Name: " << name << endl;
    cout << "Vehicle Number: " << vehicle->getVehicleNo() << endl;
    cout << "Vehicle Type: " << vehicle->getVehicleType() << endl;
}

void registerUser(){
    string name;
    string number;
    int choice;

    cout << "\nEnter user's name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter user's vehicle number: ";
    getline(cin, number);
    cout<< "\nVehicle Type\n";
    cout << "1. Car\n2. Bike\n";
    cout << "Enter the choice: ";
    cin >> choice;

    Vehicle *v;
    if(choice==1){
        v = new car(number);
    }else{
        v = new bike(number);
    }

    User u(name, v);
    users.push_back(u);

    cout << "\nUser registered successfully\n";
}

void displayUser(){
    if(users.size()==0){
        cout << "\nNo user registered\n";
        return;
    }
    cout << "\nRegistered Users: \n";
    for(int i=0; i<users.size(); i++){
        users[i].display();
    }
}