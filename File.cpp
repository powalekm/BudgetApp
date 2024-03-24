#include "File.h"

string File::getFileName() {
    return FILE_NAME;
}

void File::checkRootNode(){
//function that should use NODE in XML files TO BE IMPLEMENTED
}

bool File::isFileEmpty() {
    CMarkup XML;
    return XML.Load(getFileName());
}

