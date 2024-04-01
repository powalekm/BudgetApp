#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>

#include "UserFile.h"
#include "User.h"
#include "Utils.h"
#include "Menus.h"

using namespace std;

class UserManager {
        int loggedUserID;
        vector <User> users;
        UserFile userFile;

        int getNewUserID();
        User setNewUserData();
        bool ifLoginExists(string newLogin);
public:

    UserManager(string fileWithUsers) : userFile(fileWithUsers){
    loggedUserID = 0;
    users = userFile.loadUsersFromFile();
    };

    int getLoggedUserID();
    bool isUserLoggedIn();
    void registerUser();
    void loginUser();
    void logout();
    void listAllUsers();
    void changePassword();
};
#endif
