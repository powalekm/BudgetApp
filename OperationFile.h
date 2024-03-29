#ifndef OPERATIONFILE_H
#define OPERATIONFILE_H

#include <iostream>
#include <vector>

#include "File.h"
#include "Operation.h"

using namespace std;

class OperationFile :public File {
    int lastOperationID;

public:
    OperationFile(string fileWithOperation) : File(fileWithOperation){
    lastOperationID = 0;
    };

    int getLastOperationID();
    vector <Operation> loadOperationsFromFile(const int loggedUserID);
    void addOperationToFile(Operation operation);

};
#endif
