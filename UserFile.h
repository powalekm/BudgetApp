#ifndef USERFILE_H
#define USERFILE_H

#include "File.h"
#include <iostream>

using namespace std;

class UserFile :public File {

public:
    UserFile(string fileWithUsers) : File(fileWithUsers){};

};
#endif
