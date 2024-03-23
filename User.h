#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User {
    int userID;
    string firstName;
    string lastName;
    string login;
    string password;

public:
    void setUserID(int newUserID);
    void setFirstName(string newFirstName);
    void setLastName(string newLastName);
    void setLogin(string newLogin);
    void setPassword(string newPassword);

    int getUserID();
    string getFirstName();
    string getLastName();
    string getLogin();
    string getPassword();
};

#endif
