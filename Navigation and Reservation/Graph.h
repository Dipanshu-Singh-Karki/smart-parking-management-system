#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
#include<string>
using namespace std;

const int MAX_NODES = 20;
const int MAX_RESERVSTIONS = 20;
const int INF = 999999;

struct Edge{
    int destination;
    int distance;
};

struct GraphNode{
    string name;
    Edge edges[10];
    int edgeCount;
};


struct Reservation{
    string vehicleNumber;
    int slotNumber;
    bool active;
    bool paymentDone;
};

extern GraphNode graph[MAX_NODES];
extern Reservation reservations[MAX_RESERVSTIONS];
extern int reservationCount;
extern int totalNodes;

void initializeGraph();

void addEdge(int source, int destination, int distance);

void displayParkingMap();

void shortestPath(int destination);

bool reserveSlot(string vehicleNumber, int slotNumber);

bool cancelReservation(string vehicleNumber);

int getReservedSlot(string vehicleNumber);

bool isSlotReserved(int slotNumber);

bool hasReservation(string vehicleNumber);

void displayReservations();

void navigateToSlot(int slotNumber);


#endif