#include "BudgetMainApp.h"

bool BudgetMainApp::isUserLoggedIn(){
    return userManager.isUserLoggedIn();
}

void BudgetMainApp::loginUser(){
    userManager.loginUser();
    if (userManager.isUserLoggedIn()) {
        budgetManager = new BudgetManager(FILE_WITH_INCOMES, FILE_WITH_EXPENSES, userManager.getLoggedUserID());
    }
}

void BudgetMainApp::logout(){
    userManager.logout();
    delete budgetManager;
    budgetManager = NULL;
}

void BudgetMainApp::registerUser(){
    userManager.registerUser();
}

void BudgetMainApp::listAllUsers(){
    userManager.listAllUsers();
}

void BudgetMainApp::changePassword(){
    if (userManager.isUserLoggedIn()) {
        userManager.changePassword();
    }
}

void BudgetMainApp::addIncome(){
    if (userManager.isUserLoggedIn()) {
        budgetManager->addIncome();
    }
}

void BudgetMainApp::addExpense(){
    if (userManager.isUserLoggedIn()) {
        budgetManager->addExpense();
    }
}

void BudgetMainApp::showCurrentMonthBalance(){
    if (userManager.isUserLoggedIn()) {
        budgetManager->showCurrentMonthBalance();
    }
}


