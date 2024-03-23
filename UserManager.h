#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>

#include "UserFile.h"
#include "User.h"

using namespace std;

class UserManager {
        vector <User> users;
        UserFile userFile;
public:

    UserManager(string fileWithUsers) : userFile(fileWithUsers){};

};
#endif
