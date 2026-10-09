#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
#include<string>
using namespace std;

struct Reservation{
    string userName;
    string vehicle;
    int slotNumber;
};

struct Queue{
    int data[20];
    int front;
    int rear;
};

struct Graph{
    int vertices;
    int adj[10][10];
};

extern Graph parkingMap;
extern Reservation reservations[20];
extern int reservationCount;

void initializeQueue(Queue *q);
void enqueue(Queue *q, int val);
int dequeue(Queue *q);
bool isEmpty(Queue *q);

void initializeGraph();
void addEdge(int u, int v);
void displayMap();
void BFS(int start);

void makeReservation();
void displayReservation();

#endif