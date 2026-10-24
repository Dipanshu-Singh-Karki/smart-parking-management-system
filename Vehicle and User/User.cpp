#include"User.h"

vector<User> users;

User::User(){
    name = "";
    vehicle = NULL;
}

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

void saveUserToFile(User user){
    ofstream file("user.txt", ios::app);
    if(!file){
        cout << "Error opening 'user.txt'\n";
        return;
    }

    file << user.getName() << ","
         << user.getVehicle()->getVehicleNo() << ","
         << user.getVehicle()->getVehicleType() << endl;

    file.close();
}

void User::display(){
    cout << endl;
    cout << "User Name: " << name << endl;
    cout << "Vehicle Number: " << vehicle->getVehicleNo() << endl;
    cout << "Vehicle Type: " << vehicle->getVehicleType() << endl;
    cout << endl;
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
    saveUserToFile(u);

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


void loadUsersFromFile(){
    ifstream file("user.txt");

    if(!file){
        return;
    }

    string line;
    string name;
    string vehicleNo;
    string vehicleType;

    while(getline(file, line)){
        if(line == "")
        {
            continue;
        }
        stringstream ss(line);
        getline(ss, name, ',');
        getline(ss, vehicleNo, ',');
        getline(ss, vehicleType);

        Vehicle *vehicle = NULL;
        if(vehicleType=="Car"){
            vehicle = new car(vehicleNo);
        }else if(vehicleType=="Bike"){
            vehicle = new bike(vehicleNo);
        }

        if(vehicle!=NULL){
            users.push_back(User(name, vehicle));
        }
    }
    file.close();
}

bool findUserByVehicleNumber(string vehicleNumber, User &user){
    for(int i = 0; i<users.size(); i++){
        if(users[i].getVehicle()->getVehicleNo()==vehicleNumber){
            user = users[i];
            return true;
        }
    }
    return false;
}

void initializeUsers(){
    users.clear();
    loadUsersFromFile();
}