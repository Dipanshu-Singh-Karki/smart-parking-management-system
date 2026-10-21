#include "Graph.h"
#include "../Payment and Report/Payment.h"

GraphNode graph[MAX_NODES];

Reservation reservations[MAX_RESERVSTIONS];

int reservationCount = 0;

int totalNodes = 17;

void addEdge(int source, int destination, int distance){
    graph[source].edges[graph[source].edgeCount].destination = destination;
    graph[source].edges[graph[source].edgeCount].distance = distance;
    graph[source].edgeCount++;
    
    graph[destination].edges[graph[destination].edgeCount].destination = source;
    graph[destination].edges[graph[destination].edgeCount].distance = distance;
    graph[destination].edgeCount++;
}

void initializeGraph(){
    for(int i=0;i<MAX_NODES; i++){
        graph[i].edgeCount = 0;
    }
    graph[0].name = "ENTRY";
    graph[1].name = "J1";
    graph[2].name = "J2";
    graph[3].name = "J3";
    graph[4].name = "P1";
    graph[5].name = "P2";
    graph[6].name = "P3";
    graph[7].name = "P4";
    graph[8].name = "P5";
    graph[9].name = "P6";
    graph[10].name = "P7";
    graph[11].name = "P8";
    graph[12].name = "P9";
    graph[13].name = "P10";
    graph[14].name = "P11";
    graph[15].name = "P12";
    graph[16].name = "EXIT";

    addEdge(0,1,10);
    addEdge(1,2,10);
    addEdge(2,3,10);
    addEdge(3,16,10);
    
    addEdge(1,4,4);
    addEdge(1,5,5);
    addEdge(1,6,6);
    addEdge(1,7,7);

    addEdge(2,8,4);
    addEdge(2,9,5);
    addEdge(2,10,6);
    addEdge(2,11,7);

    addEdge(3,12,4);
    addEdge(3,13,5);
    addEdge(3,14,6);
    addEdge(3,15,7);

    addEdge(10,16,8);
    addEdge(11,16,7);
    addEdge(14,16,5);
    addEdge(15,16,4);
}

void displayParkingMap(){
    cout << "\n";
    cout << "PARKING MAP\n";

    cout << "                     ENTRY\n";
    cout << "                       |\n";
    cout << "                       |\n";
    cout << " ----------------------J1-----------------------\n";
    cout << " |      ---------------J1---------------       |\n";
    cout << " |      |              |               |       |\n";
    cout << " P2     P1             |               P3      P4\n";
    cout << "                       |\n";
    cout << "                       |\n";
    cout << " ----------------------J2-----------------------\n";
    cout << " |      ---------------J2---------------       |\n";
    cout << " |      |              |               |       |\n";
    cout << " P6     P5             |               P7      P8\n";
    cout << "                       |               |_______|____________\n";
    cout << "                       |                                    |\n";
    cout << " ----------------------J3----------------------             |\n";
    cout << " |      ---------------J3---------------       |            |\n";
    cout << " |      |              |               |       |            |\n";
    cout << " P10    P9             |               P11     P12          |\n";
    cout << "                       |               |_______|________    |\n";
    cout << "                       |                                |   |\n";
    cout << "                       |________________________________|___|\n";
    cout << "                      EXIT\n";

    cout << "\n";
}

int getNodeIndex(string nodeName){
    for(int i=0; i<totalNodes; i++){
        if(graph[i].name==nodeName){
            return i;
        }
    }
    return -1;
}

void shortestPath(int destination){
    int distance[MAX_NODES];
    int parent[MAX_NODES];
    bool visited[MAX_NODES];

    for(int i=0; i<totalNodes; i++){
        distance[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }
    distance[0] = 0;

    for(int step = 0; step<totalNodes-1; step++){
        int minimun = INF;
        int current = -1;
        for(int i=0; i<totalNodes; i++){
            if(!visited[i] && distance[i]<minimun){
                minimun = distance[i];
                current = i;
            }
        }
        if(current == -1){
            break;
        }
        visited[current] = true;

        for(int i=0; i<graph[current].edgeCount; i++){
            int next = graph[current].edges[i].destination;
            int weight = graph[current].edges[i].distance;

            if(!visited[next] && distance[current] != INF && distance[current] + weight < distance[next]){
                distance[next] = distance[current]+weight;
                parent[next] = current;
            }
        }
    }

    if(distance[destination]==INF){
        cout << "\nNo route found\n";
        return;
    }

    int path[MAX_NODES];
    int pathCount = 0;
    int current = destination;

    while(current!=-1){
        path[pathCount++] = current;
        current = parent[current];
    }

    cout << "\nShortest route:\n";

    for(int i = pathCount - 1; i >= 0; i--){
        cout << graph[path[i]].name;
        if(i != 0){
            cout << " --> ";
        }
    }
    cout << "\nTotal Distance: " << distance[destination] << " metres\n";
    cout << endl;
}

void navigateToSlot(int slotNumber){
    if(slotNumber<1||slotNumber>12){
        cout << "\nInvalid slot number\n";
        return;
    }

    int node = slotNumber + 3;
    shortestPath(node);
}


bool hasReservation(string vehicleNumber){
    for(int i=0; i<reservationCount; i++){
        if(reservations[i].vehicleNumber==vehicleNumber && reservations[i].active){
            return true;
        }
    }
    return false;
}

bool isSlotReserved(int slotNumber){
    for(int i=0; i<reservationCount; i++){
        if(reservations[i].slotNumber==slotNumber && reservations[i].active){
            return true;
        }
    }
    return false;
}

int getReservedSlot(string vehicleNumber){
    for(int i=0; i<reservationCount; i++){
        if(reservations[i].vehicleNumber==vehicleNumber && reservations[i].active){
            return reservations[i].slotNumber;
        }
    }
    return -1;
}

bool reserveSlot(string vehicleNumber, int slotNumber){
    if(hasReservation(vehicleNumber)){
        cout << "\nVehicle already has a reservation\n";
        return false;
    }
    if(isSlotReserved(slotNumber)){
        cout << "\nSlot already reserved\n";
        return false;
    }
    if(slotNumber<1||slotNumber>12){
        cout << "\nInvalid slot number\n";
        return false;
    }

    int advanceAmount = 50;
    cout << "Reservation Charge: Rs " << advanceAmount << endl;
    addPayment(vehicleNumber, "Reservation", 0, advanceAmount);
    reservations[reservationCount].vehicleNumber = vehicleNumber;
    reservations[reservationCount].slotNumber = slotNumber;
    reservations[reservationCount].active = true;
    reservations[reservationCount].paymentDone = true;
    reservationCount++;

    cout << "\nReservation Successful\n";
    cout << "Vehicle: "<< vehicleNumber << endl;
    cout << "Reserved Slot: P"<< slotNumber << endl;
    cout << "\nNavigation route: \n";
    navigateToSlot(slotNumber);

    return true;
}

bool cancelReservation(string vehicleNumber){
    for(int i=0; i<reservationCount; i++){
        if(reservations[i].vehicleNumber==vehicleNumber && reservations[i].active){
            reservations[i].active = false;
            cout << "\nReservation cancelled\n";
            cout << "Advance payment is non refundable\n";
            return true;
        }
    }
    cout << "\nReservation not found\n";
    return false;
}

void displayReservations(){
    if(reservationCount==0){
        cout << "\nNo reservations\n";
        return;
    }

    cout << "\nReserved Parking Slots\n";
    for(int i=0; i<reservationCount; i++){
        if(reservations[i].active){
            cout << "\nVehcile Number: "<< reservations[i].vehicleNumber << endl;
            cout << "Reserved slot: P"<< reservations[i].slotNumber << endl;
        }
        if(reservations[i].paymentDone){
            cout << "Advance payment: (Rs. 50)Paid\n";
        }else{
            cout << "Advance payment: Pending\n";
        }
    }
    cout << endl;
}