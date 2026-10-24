#include"Parking.h"
#include"../Vehicle and User/User.h"
#include"../Payment and Report/Payment.h"
#include"../Navigation and Reservation/Graph.h"

ParkingSlot slots[12];

WaitingQueue queue;

Node *head = NULL;

void initializeParking(){

    for(int i=0; i<12; i++){
        slots[i].slotNumber = i+1;
        slots[i].occupied = false;
        slots[i].vehicleNumber = "";
        slots[i].vehicleType = "";
        slots[i].hours = 0;
        slots[i].minutes = 0;
    }

    initializeQueue();
}

void initializeQueue(){
    queue.front = 0;
    queue.rear = -1;
}

void displaySlots(){
    cout << "\nParking Slots: \n";
    for(int i=0; i<12; i++){
        cout << "Slot P" << slots[i].slotNumber << ": ";
        if(slots[i].occupied){
            cout<<"Occupied (" << slots[i].vehicleNumber <<", "<< slots[i].vehicleType<< ")";
        }else{
            cout << "Available";
        }
        cout << endl;
    }
    cout << endl;
}

void enqueue(string vehicle, int type){
    if(queue.rear==99){
        cout << "\nWaititng Queue Full\n";
        return;
    }
    queue.rear++;
    queue.waiting[queue.rear] = vehicle;
    queue.waitingType[queue.rear] = type;
    cout << "\nVehicle added to Waiting Queue\n";
}

void dequeue(){
    if(queue.front>queue.rear){
        cout << "\nQueue is Empty\n";
        return;
    }
    if(queue.front==queue.rear){
        cout << "\nVehicle moved: " << queue.waiting[queue.front] << endl;
        queue.front = 0;
        queue.rear = -1;
        return;
    }
    cout << "\nVehicle moved: " << queue.waiting[queue.front] << endl;
    queue.front++;
}

string getFrontVehicle(){
    return queue.waiting[queue.front];
}

int getFrontType(){
    return queue.waitingType[queue.front];
}

void displayQueue(){
    if(queue.front>queue.rear){
        cout << "\nWaiting Queue is Empty\n";
        return;
    }
    cout << "\nWaiting Queue: \n";
    for(int i = queue.front; i<=queue.rear; i++){
        cout << queue.waiting[i] << ": ";
        if(queue.waitingType[i]==1){
            cout << "Car" << endl;
        }else{
            cout << "Bike" << endl;
        }
    }
}

void addHistory(string vehicle, int slot, string action,int hrs, int mins){
    Node *temp = new Node;
    temp->vehicleNumber = vehicle;
    temp->slotNumber = slot;
    temp->action = action;
    temp->hours = hrs;
    temp->minutes = mins;
    temp->next = head;
    head = temp;
}

void displayCurrentParkingHistory(){
    Node *temp = head;
    if(temp==nullptr){
        cout << "\nNo History\n";
        return;
    }
    cout << "\nParking History: \n";
    while(temp!=nullptr){
        cout << "Vehicle Number: "<< temp->vehicleNumber << endl;
        cout << "Slot Number: P"<< temp->slotNumber << endl;
        cout << "Action: "<< temp->action << endl;
        cout << "Time: "<< temp->hours << ":";
        if(temp->minutes<10){
            cout << "0";
        }
        cout << temp->minutes << endl;
        cout << endl;

        temp = temp->next;
    }
}

void displayPermanentHistory(){
    ifstream file("parkingHistory.txt");

    if(!file){
        cout << "\nNo parking history found\n";
        return;
    }
    string vehicleNo;
    string slotNo;
    string action;
    string hrs;
    string mins;

    cout << "\nPermanant parkinh history:\n";

    while(getline(file, vehicleNo, ',') &&
          getline(file, slotNo, ',') &&
          getline(file, action, ',') &&
          getline(file, hrs, ',') &&
          getline(file, mins)){
            cout << "Vehicle Number: " << vehicleNo << endl;
            cout << "slot Number: " << slotNo << endl;
            cout << "Action: " << action << endl;
            cout << "Time: "<< hrs << ":";
            if(mins.length()==1){
                cout << "0";
            }
            cout << mins << endl;
            cout << endl;
        }
        file.close();

}

Vehicle* searchVehicle(string number){
    for(int i=0; i<users.size(); i++){
        if(users[i].getVehicle()->getVehicleNo()==number){
            return users[i].getVehicle();
        }
    }
    return nullptr;
}

void parkVehicle(){
    string vehicle;
    cout << "\nEnter the vehicle Number: ";
    cin >> vehicle;
    Vehicle *v = searchVehicle(vehicle);
    if(v==nullptr){
        cout << "\nVehicle not registered\n";
        return;
    }
    string type = v->getVehicleType();
    cout << "Enter the entry time \n";
    int hrs, mins;
    cout << "Entry hour: ";
    cin >> hrs;
    cout << "Entry minute: ";
    cin >> mins;

    if(hasReservation(vehicle)){
        int reservedSlot = getReservedSlot(vehicle);
        int index = reservedSlot-1;
        if(slots[index].occupied){
            cout << "\nReserved slot already occupied\n";
            return;
        }
        slots[index].occupied = true;
        slots[index].vehicleNumber = vehicle;
        slots[index].vehicleType = type;
        slots[index].hours = hrs;
        slots[index].minutes = mins;

        cout << "\nVehicle pparked at slot P" << reservedSlot << endl;
        addHistory(vehicle, reservedSlot, "Reserved Parking", hrs, mins);
        navigateToSlot(reservedSlot);
        return;
    }

    for(int i=0;i<12; i++){
        if(!slots[i].occupied && !isSlotReserved(i+1)){
            slots[i].vehicleNumber = vehicle;
            slots[i].occupied = true;
            slots[i].vehicleType = type;
            slots[i].hours = hrs; slots[i].minutes = mins;
            cout << "\nVehicle parked at Slot " << slots[i].slotNumber << endl;
            addHistory(vehicle, slots[i].slotNumber, "Parked",hrs, mins);
            ofstream file("parkingHistory.txt", ios::app);
            if(!file){
                cout <<"\nError in opening 'parkingHistory.txt'\n";
            }else{
                file << vehicle << ","
                     << "P" << slots[i].slotNumber << ","
                     << "Parked" << ","
                     << hrs << ","
                     << mins << endl;
                file.close();
            }
            navigateToSlot(slots[i].slotNumber);
            return;
        }
    }
    cout << "\nParking FULL\n";
    if(type=="Car"){
        enqueue(vehicle, 1);
    }else{
        enqueue(vehicle, 2);
    }
    
    return;
}

void removeVehicle(){
    string vehicle;
    int amount;
    cout << "\nEnter the vehicle number: ";
    cin >> vehicle;
    cout << "Enter the exit time \n";
    int hrs, mins;
    cout << "Exit hour: ";
    cin >> hrs;
    cout << "Exit minute: ";
    cin >> mins;
    for(int i=0; i<12; i++){
        if(vehicle==slots[i].vehicleNumber){
            int entry, exit, duration, totalHours;
            entry = slots[i].hours*60 + slots[i].minutes;
            exit = hrs*60 + mins;
            duration = exit-entry;
            if(duration<0){
                cout << "\nInvalid Exit time\n";
                return;
            }
            totalHours = duration/60;
            if(duration%60!=0){
                totalHours++;
            }
            if(slots[i].vehicleType=="Car"){
                amount = totalHours*40;
            }else{
                amount = totalHours*20;
            }
            addPayment(slots[i].vehicleNumber, slots[i].vehicleType, totalHours, amount);
            slots[i].occupied = false;
            slots[i].vehicleNumber = "";
            slots[i].vehicleType = "";
            slots[i].hours = 0;
            slots[i].minutes = 0;
            addHistory(vehicle,slots[i].slotNumber, "Removed", hrs, mins);
            ofstream file("parkingHistory.txt", ios::app);
            if(!file){
                cout <<"\nError in opening 'parkingHistory.txt'\n";
            }else{
                file << vehicle << ","
                     << "P" << slots[i].slotNumber << ","
                     << "Removed" << ","
                     << hrs << ","
                     << mins << endl;
                file.close();
            }
            cout << "\nVehicle Removed\n";
            
            
            if(queue.front<=queue.rear){
                string nextVehicle = getFrontVehicle();
                int nextVehicleType = getFrontType();
                dequeue();
                slots[i].occupied = true;
                slots[i].vehicleNumber = nextVehicle;
                if(nextVehicleType==1){
                    slots[i].vehicleType = "Car";
                }else{
                    slots[i].vehicleType = "Bike";
                }
                slots[i].hours = hrs;
                slots[i].minutes = mins;
                cout << "Next Vehicle " << nextVehicle << " parked at " << slots[i].slotNumber;
                cout << endl;
                addHistory(nextVehicle,slots[i].slotNumber, "Parked", hrs, mins);
            }
            return;
        }
    }
    cout << "\nVehicle NOT Found\n";
}