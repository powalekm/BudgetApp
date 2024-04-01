#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include "Operation.h"
#include "OperationFile.h"
#include "Utils.h"
#include "DateMethods.h"
#include "Menus.h"
#include "Type.h"

using namespace std;

class BudgetManager {
    OperationFile incomesFile;
    OperationFile expensesFile;
    DateMethods dateMethods;

    vector <Operation> incomes;
    vector <Operation> expenses;

    const int LOGGED_USER_ID;
    Operation setNewOperation(const Type &type);
    void showBalace(int startDate, int endDate);
    double calculateBalance();
public:
    BudgetManager(string incomeFileName, string expenseFileName, int loggedUserId)
    : incomesFile(incomeFileName), expensesFile(expenseFileName), LOGGED_USER_ID(loggedUserId){
    incomes = incomesFile.loadOperationsFromFile(LOGGED_USER_ID);
    expenses = expensesFile.loadOperationsFromFile(LOGGED_USER_ID);
    };

    void addIncome();
    void addExpense();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showCustomPeriodBalance();
};
#endif
