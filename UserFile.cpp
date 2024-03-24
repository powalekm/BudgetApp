#include "UserFile.h"

vector <User> UserFile::loadUsersFromFile() {
    User user;
    vector <User> users;

    CMarkup xml;
    if(xml.Load(getFileName())) {
        xml.FindElem("root");
        xml.IntoElem();
        xml.FindElem("user");

        do {
            xml.IntoElem();
            xml.FindElem("userID");
            user.setUserID(atoi(xml.GetData().c_str()));
            xml.FindElem("login");
            user.setLogin(xml.GetData());
            xml.FindElem("password");
            user.setPassword(xml.GetData());
            xml.FindElem("firstName");
            user.setFirstName(xml.GetData());
            xml.FindElem("LastName");
            user.setLastName(xml.GetData());
            users.push_back(user);
            xml.OutOfElem();
        } while(xml.FindElem("user"));
    }
    return users;
}

void UserFile::addUserToFile(User user) {
    CMarkup xml;
    xml.Load(getFileName());

    if(xml.FindElem("root")) {
        xml.IntoElem();
    }else {
        xml.AddElem("root");
        xml.IntoElem();
    }
        xml.AddElem("user");
        xml.IntoElem();
        xml.AddElem("userID", user.getUserID());
        xml.AddElem("login", user.getLogin());
        xml.AddElem("password", user.getPassword());
        xml.AddElem("firstName", user.getFirstName());
        xml.AddElem("LastName", user.getLastName());
        //xml.OutOfElem();
        //xml.OutOfElem();
        xml.Save(getFileName());
    }

