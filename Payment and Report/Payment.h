#ifndef PAYMENT_H
#define PAYMENT_H

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct Payment{
    string vehicleNumber;
    string vehicleType;
    int hours;
    int amount;
};

extern Payment payments[100];
extern int paymentCount;

void displayCurrentPayments();
void generateReport();
void addPayment(string vehicleNumber, string vehicleType, int hours, int amount);
void displayPremanentPaymentHistory();

#endif