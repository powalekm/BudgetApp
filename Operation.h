#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>

using namespace std;

class Operation {
    int id;
    int userID;
    int date;
    string item;
    double amount;

public:
    void setID(int newID);
    void setUserID(int newUserID);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(double newAmount);

    int getID();
    int getUserID();
    int getDate();
    string getItem();
    double getAmount();
};
#endif
