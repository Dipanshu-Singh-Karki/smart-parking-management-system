#include"Graph.h"

Graph parkingMap;
Reservation reservations[20];
int reservationCount = 0;

void initializeQueue(Queue *q){
    q->front = 0;
    q->rear = -1;
}

void enqueue(Queue *q, int val){
    if(q->rear==19){
        cout << "Queue is Full\n";
        return;
    }
    (q->rear)++;
    q->data[q->rear] = val;
}

int dequeue(Queue *q){
    if(q->front>q->rear){
        return -1;
    }
    if(q->front==q->rear){
        int val = q->data[q->front];
        q->front = 0;
        q->rear = -1;
        return val;
    }
    int val = q->data[q->front];
    (q->front)++;
    return val;
}

bool isEmpty(Queue *q){
    if(q->front>q->rear){
        return true;
    }
    return false;
}

void initializeGraph(){
    parkingMap.vertices = 6;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            parkingMap.adj[i][j] = 0;
        }
    }
    addEdge(0,1);
    addEdge(0,3);
    addEdge(1,2);
    addEdge(1,3);
    addEdge(3,4);
    addEdge(4,5);
}

void addEdge(int u, int v){
    parkingMap.adj[u][v] = 1;
    parkingMap.adj[v][u] = 1;
}

void displayMap(){
    cout << "\nParking Map: \n";
    cout << endl;
    cout << "         ENTRY\n";
    cout << "        /     \\\n";
    cout << "       A-------C\n";
    cout << "      /         \\\n";
    cout << "     B           D\n";
    cout << "                  \\\n";
    cout << "                  Exit\n";
}

void BFS(int start){
    bool visited[10];
    for(int i=0; i<10; i++){
        visited[i]= false;
    }
    Queue q;
    initializeQueue(&q);
    visited[start] = true;
    enqueue(&q, start);
    cout << "\nReachable Parking Areas:\n";
    while(!isEmpty(&q)){
        int current = dequeue(&q);
        switch(current){
            case 0:
                cout << "\nEntry"<< endl;
                break;
            case 1:
                cout << "Parking A"<< endl;
                break;
            case 2:
                cout << "Parking B"<< endl;
                break;
            case 3:
                cout << "Parking C"<< endl;
                break;
            case 4:
                cout << "Parking D"<< endl;
                break;
            case 5:
                cout << "Exit"<< endl;
                break;
            
        }
        for(int i=0; i<parkingMap.vertices; i++){
            if(parkingMap.adj[current][i]==1&&visited[i]==false){
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
}

void makeReservation(){
    if(reservationCount==20){
        cout << "\nReservation count FULL\n";
        return;
    }

    Reservation r;
    cin.ignore();

    cout << "Enter user name: ";
    getline(cin, r.userName);

    cout << "Enter vehicle number: ";
    getline(cin, r.vehicle);

    cout << "Enter slot number: ";
    cin >> r.slotNumber;

    reservations[reservationCount++] = r;
    cout << "\nReservation successful\n";
}

void displayReservation(){
    if(reservationCount==0){
        cout << "\nNo reservation available\n";
        return;
    }
    for(int i=0; i<reservationCount; i++){
        cout << "\nReservation "<<i+1<<endl;
        cout << "User Name: " << reservations[i].userName << endl;
        cout << "Vehicle no.: " << reservations[i].vehicle << endl;
        cout << "Slot no.: " << reservations[i].slotNumber << endl;
        cout << endl;
    }
}