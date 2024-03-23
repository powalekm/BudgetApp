#ifndef BUDGETMAINAPP_H
#define BUDGETMAINAPP_H

#include "UserManager.h"

#include <iostream>

using namespace std;

class BudgetMainApp {
    UserManager userManager;
    //BudgetManager *budgetManager;
    const string FILE_WITH_INCOMES;
    const string FILE_WITH_EXPENSES;

public:
    BudgetMainApp(string fileWithUsers, string fileWithIncomes, string fileWithExpenses)
        : userManager(fileWithUsers), FILE_WITH_INCOMES(fileWithIncomes), FILE_WITH_EXPENSES(fileWithExpenses) {
        //budgetManager = NULL;
    }
    /*~BudgetMainApp() {
        delete budgetManager;
        budgetManager = NULL;
    }*/

    bool isUserLoggedIn();
    void loginUser();
    void registerUser();
};
#endif
