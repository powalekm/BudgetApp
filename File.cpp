#include "File.h"

string File::getFileName() {
    return FILE_NAME;
}

bool File::isFileEmpty() {
    CMarkup XML;
    return XML.Load(getFileName());
}

