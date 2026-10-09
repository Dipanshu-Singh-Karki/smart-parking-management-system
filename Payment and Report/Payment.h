#ifndef PAYMENT_H
#define PAYMENT_H

#include<iostream>
#include<string>
using namespace std;

struct Payment{
    string vehicleNumber;
    string vehicleType;
    int hours;
    int amount;
};

extern Payment payments[100];
extern int paymentCount;

void calculatePayment();
void displayPayments();
void generateReport();

#endif