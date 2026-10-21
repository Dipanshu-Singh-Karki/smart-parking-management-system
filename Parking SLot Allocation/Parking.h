#ifndef PARKING_H
#define PARKING_H

#include<iostream>
#include<string.h>
using namespace std;

struct ParkingSlot{
    int slotNumber;
    bool occupied;
    string vehicleNumber;
    string vehicleType;
    int hours;
    int minutes;
};

struct WaitingQueue{
    string waiting[100];
    int waitingType[100];
    int front;
    int rear;
};

struct Node{
    string vehicleNumber;
    int slotNumber;
    string action;
    int hours;
    int minutes;
    Node *next;
};

extern ParkingSlot slots[12];
extern WaitingQueue queue;
extern Node *head;

void initializeParking();
void displaySlots();
void parkVehicle();
void removeVehicle();
void initializeQueue();
string getFrontVehicle();
int getFrontType();
void enqueue(string vehicle, int type);
void dequeue();
void displayQueue();
void addHistory(string vehicle, int slot, string action, int hrs, int mins);
void displayHistory();

#endif