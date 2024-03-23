#include "File.h"

string File::getFileName() {
    return FILE_NAME;
}

void File::checkRootNode(){
//function that should use NODE in XML files TO BE IMPLEMENTED
}

bool File::isFileEmpty(fstream &textFile) {
    textFile.seekg(0, ios::end);
    if (textFile.tellg() == 0)
        return true;
    else
        return false;
}

