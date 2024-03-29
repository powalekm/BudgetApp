#include "OperationFile.h"

vector <Operation> OperationFile::loadOperationsFromFile(const int LOGGED_USER_ID){
    Operation operation;
    vector <Operation> operations;
    CMarkup xml;

    if(xml.Load(getFileName())) {
        xml.FindElem("root");
        xml.IntoElem();
        xml.FindElem("income");
        do {
            xml.IntoElem();
            xml.FindElem("id");
            operation.setID(atoi(xml.GetData().c_str()));
            lastOperationID = operation.getID();
            xml.FindElem("userID");
            operation.setUserID(atoi(xml.GetData().c_str()));
            xml.FindElem("date");
            operation.setDate(stoi(xml.GetData()));
            xml.FindElem("item");
            operation.setItem(xml.GetData());
            xml.FindElem("amount");
            operation.setAmount(stoi(xml.GetData()));
            if( operation.getUserID() == LOGGED_USER_ID){
                operations.push_back(operation);
            }
            xml.OutOfElem();
        } while(xml.FindElem("income"));
    }
    return operations;
}

int OperationFile::getLastOperationID(){
    return lastOperationID;
}

void OperationFile::addOperationToFile(Operation operation){
    CMarkup xml;
    xml.Load(getFileName());

    if(xml.FindElem("root")) {
        xml.IntoElem();
    } else {
        xml.AddElem("root");
        xml.IntoElem();
    }
    xml.AddElem("income");
    xml.IntoElem();
    xml.AddElem("id", operation.getID());
    xml.AddElem("userID", operation.getUserID());
    xml.AddElem("date", operation.getDate());
    xml.AddElem("item", operation.getItem());
    xml.AddElem("amount", operation.getAmount());
    xml.Save(getFileName());
    lastOperationID++;
}
