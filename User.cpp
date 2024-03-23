#include "User.h"

void User::setUserID(int newUserID) {
    if (newUserID >= 0) {
        userID = newUserID ;
    }
}

void User::setFirstName(string newFirstName) {
    firstName = newFirstName;
}

void User::setLastName(string newLastName) {
    lastName = newLastName;
}

void User::setLogin(string newLogin) {
    login = newLogin;
}

void User::setPassword(string newPassword) {
    password = newPassword;
}

int User::getUserID() {
    return userID;
}

string User::getFirstName() {
    return firstName;
}

string User::getLastName() {
    return lastName;
}
string User::getLogin() {
    return login;
}

string User::getPassword() {
    return password;
}

