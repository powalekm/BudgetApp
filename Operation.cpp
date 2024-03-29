#include "Operation.h"

void Operation::setID(int newID) {
    if (newID > 0) {
        id = newID;
    }
}

void Operation::setUserID(int newUserID) {
    if (newUserID > 0) {
        userID = newUserID;
    }
}

void Operation::setDate(int newDate) {
    date = newDate;
}

void Operation::setItem(string newItem) {
    item = newItem;
}

void Operation::setAmount(double newAmount) {
    amount = newAmount;
}

int Operation::getID() {
    return id;
}

int Operation::getUserID() {
    return userID;
}
int Operation::getDate() {
    return date;
}

string Operation::getItem() {
    return item;
}
double Operation::getAmount() {
    return amount;
}
