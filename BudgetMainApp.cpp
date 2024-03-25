#include "BudgetMainApp.h"

bool BudgetMainApp::isUserLoggedIn(){
    return userManager.isUserLoggedIn();
}

void BudgetMainApp::loginUser(){
    userManager.loginUser();
}

void BudgetMainApp::logout(){
    userManager.logout();
}

void BudgetMainApp::registerUser(){
    userManager.registerUser();
}

void BudgetMainApp::listAllUsers(){
    userManager.listAllUsers();
}

void BudgetMainApp::changePassword(){
    userManager.changePassword();
}
