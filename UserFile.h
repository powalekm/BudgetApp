#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>

#include "User.h"
#include "File.h"

using namespace std;

class UserFile :public File {

public:
    UserFile(string fileWithUsers) : File(fileWithUsers){};
    vector <User> loadUsersFromFile();

    void addUserToFile(User user);
    void changePassword(User user);

};
#endif
