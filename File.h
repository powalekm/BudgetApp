#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>

#include "Markup.h"

using namespace std;

class File {
    const string FILE_NAME;
    int lastID;

public:
    File(string fileName) : FILE_NAME(fileName){}

    string getFileName();
    bool isFileEmpty();
};
#endif
