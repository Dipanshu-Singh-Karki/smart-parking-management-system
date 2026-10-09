#ifndef PARKING_H
#define PARKING_H

#include<iostream>
#include<string.h>
using namespace std;

struct ParkingSLot{
    int slotNumber;
    bool occupied;
    string vehicleNumber;
};

struct WaititngQueue{
    string waititng[100];
    int front;
    int rear;
};

struct Node{
    string vehicleNumber;
    int slotNumber;
    string action;
    Node *next;
};

extern ParkingSLot slots[10];
extern WaititngQueue queue;
extern Node *head;

void initializeParking();
void displaySlots();
void parkVehicle();
void removeVehicle();
void initializeQueue();
void enqueue(string vehicle);
void dequeue();
void displayQueue();
void addHistory(string vehicle, int slot, string action);
void displayHistory();

#endif