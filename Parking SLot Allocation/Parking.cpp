#include"Parking.h"

ParkingSLot slots[10];

WaititngQueue queue;

Node *head = NULL;

void initializeParking(){

    for(int i=0; i<10; i++){
        slots[i].slotNumber = i+1;
        slots[i].occupied = false;
        slots[i].vehicleNumber = "";
    }

    initializeQueue();
}

void initializeQueue(){
    queue.front = 0;
    queue.rear = -1;
}

void displaySlots(){
    cout << "\nParking Slots: \n";
    for(int i=0; i<10; i++){
        cout << "Slot " << slots[i].slotNumber << ": ";
        if(slots[i].occupied){
            cout<<"Occupied (" << slots[i].vehicleNumber << ")";
        }else{
            cout << "Available";
        }
        cout << endl;
    }
}

void enqueue(string vehicle){
    if(queue.rear==99){
        cout << "\nWaititng Queue Full\n";
        return;
    }
    queue.rear++;
    queue.waititng[queue.rear] = vehicle;
    cout << "\nVehicle added to Waiting Queue\n";
}

void dequeue(){
    if(queue.front>queue.rear){
        cout << "\nQueue is Empty\n";
        return;
    }
    if(queue.front==queue.rear){
        cout << "\nVehicle moved: " << queue.waititng[queue.front] << endl;
        queue.front = 0;
        queue.rear = -1;
    }
    cout << "\nVehicle moved: " << queue.waititng[queue.front] << endl;
    queue.front++;
}

void displayQueue(){
    if(queue.front>queue.rear){
        cout << "\nWaiting Queue is Empty\n";
        return;
    }
    cout << "\nWaiting Queue: \n";
    for(int i = queue.front; i<=queue.rear; i++){
        cout << queue.waititng[i] <<endl;
    }
}

void addHistory(string vehicle, int slot, string action){
    Node *temp = new Node;
    temp->vehicleNumber = vehicle;
    temp->slotNumber = slot;
    temp->action = action;
    temp->next = head;
    head = temp;
}

void displayHistory(){
    Node *temp = head;
    if(temp==nullptr){
        cout << "\nNo History\n";
        return;
    }
    cout << "\nParking History: \n";
    while(temp!=nullptr){
        cout << temp->vehicleNumber << " - " << temp->action << " - Slot " << temp->slotNumber << endl;
        temp = temp->next;
    }
}

void parkVehicle(){
    string vehicle;
    cout << "\nEnter the vehicle Number: ";
    cin >> vehicle;
    for(int i=0;i<10; i++){
        if(!slots[i].occupied){
            slots[i].vehicleNumber = vehicle;
            slots[i].occupied = true;
            cout << "\nVehicle parked at Slot " << slots[i].slotNumber << endl;
            addHistory(vehicle, slots[i].slotNumber, "Parked");
            return;
        }
    }
    cout << "\nParking FULL\n";
    enqueue(vehicle);
    return;
}

void removeVehicle(){
    string vehicle;
    cout << "\nEnter the vehicle number: ";
    cin >> vehicle;
    for(int i=0; i<10; i++){
        if(vehicle==slots[i].vehicleNumber){
            slots[i].occupied = false;
            slots[i].vehicleNumber = "";
            addHistory(vehicle,slots[i].slotNumber, "Removed");
            cout << "\nVehicle Removed\n";
            
            if(queue.front<=queue.rear){
                string nextVehicle = queue.waititng[queue.front];
                queue.front++;
                slots[i].occupied = true;
                slots[i].vehicleNumber = nextVehicle;
                cout << "Next Vehicle " << nextVehicle << " parked at " << slots[i].slotNumber;
                cout << endl;
                addHistory(nextVehicle,slots[i].slotNumber, "Parked");
            }
            return;
        }
    }
    cout << "\nVehicle NOT Found\n";
}