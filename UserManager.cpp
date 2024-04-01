#include "UserManager.h"

bool UserManager::isUserLoggedIn() {
    if (loggedUserID > 0) {
        return true;
    } else {
        return false;
    }
}

void UserManager::registerUser() {
    User user = setNewUserData();

    users.push_back(user);
    userFile.addUserToFile(user);

    cout << endl << "New account has been created." << endl << endl;
    system("pause");
    system("cls");
}

int UserManager::getNewUserID() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserID() + 1;
}

bool UserManager::ifLoginExists(string newLogin) {
    for(unsigned int i = 0; i <users.size(); i++) {
        if(users[i].getLogin() == newLogin) {
            cout << endl << "This login is already taken." << endl;
            return true;
        }
    }
    return false;
}

User UserManager::setNewUserData() {
    User user;
    user.setUserID(getNewUserID());

    system("cls");
    cout << " >>> New User <<<" << endl << endl;
    cout << "First name: ";
    user.setFirstName(Utils::getLine());
    cout << "Last name: ";
    user.setLastName(Utils::getLine());
    do {
        cout << "Login: ";
        user.setLogin(Utils::getLine());
    } while (ifLoginExists(user.getLogin()) == true);
    cout << "Password: ";
    user.setPassword(Utils::getLine());

    return user;
}

void UserManager::listAllUsers() {
    if (users.empty()) {
        cout << "There is no user in the file." << endl;
    } else {
        for(unsigned int i = 0; i <users.size(); i++) {
            cout << "User ID:    " << users[i].getUserID() << endl;
            cout << "Login:      " <<  users[i].getLogin() << endl;
            cout << "Password:   " <<  users[i].getPassword() << endl;
            cout << "First Name: " <<  users[i].getFirstName() << endl;
            cout << "Last Name:  " <<  users[i].getLastName() << endl;
        }
    }
    system("pause");
}

void UserManager::loginUser() {
    User user;
    string login = "", pasword = "";
    bool loginVerification = false;

    cout << endl << "Login: ";
    user.setLogin(Utils::getLine());

    unsigned int i = 0;
    while (i < users.size()) {

        if (Utils::stringComparision(user.getLogin(), users[i].getLogin())) {
            loginVerification = true;
            for (int loginAttempts = 2; loginAttempts >= 0; loginAttempts--) {
                cout << "Password: ";
                user.setPassword(Utils::getLine());
                if (user.getPassword() == users[i].getPassword()) {
                    cout << "You are logged correctly." << endl;
                    system("pause");
                    loggedUserID = users[i].getUserID();
                    break;
                }
                cout << "The password is not correct, you have " << loginAttempts << " attempts left."  << endl;
                if ( loginAttempts == 0) {
                    cout << endl << "Login failed." << endl;
                    system("pause");
                }
            }
        }
        i++;
    }
    if (loginVerification == false) {
        cout << "The login is not in the system." << endl << endl;
        system("pause");
    }
}

void UserManager::logout() {
    loggedUserID = 0;
    cout << "You are correctly logged out." << endl;
}

void UserManager::changePassword() {
    string newPassword = "";
    Menus::showTitle("CHANGE PASSWORD");
    cout << "New password: ";
    newPassword = Utils::getLine();

    for (unsigned int i = 0; i < users.size(); i++) {
        if (loggedUserID == users[i].getUserID()) {
            users[i].setPassword(newPassword);
            userFile.changePassword(users[i]);
            cout << "The password has been changed." << endl << endl;
            system("pause");
        }
    }
}
int UserManager::getLoggedUserID() {
    return loggedUserID;
}
