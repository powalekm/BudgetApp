#include "BudgetManager.h"

void BudgetManager::addIncome() {
    const Type &type = INCOME;
    Operation operation = setNewOperation(type);

    incomes.push_back(operation);
    incomesFile.addOperationToFile(operation);
    cout << endl << "New income has been created." << endl << endl;
    system("pause");
    system("cls");
}

void BudgetManager::addExpense() {
    const Type &type = EXPENSE;
    Operation operation = setNewOperation(type);

    expenses.push_back(operation);
    expensesFile.addOperationToFile(operation);
    cout << endl << "New income has been created." << endl << endl;
    system("pause");
    system("cls");
}

Operation BudgetManager::setNewOperation(const Type &type) {
    Operation operation;
    char choice;

    if (type == INCOME) {
        operation.setID(incomesFile.getLastOperationID() + 1);
    } else if (type == EXPENSE) {
        operation.setID(expensesFile.getLastOperationID() + 1);
    } else {
        cout << "There is no correct type for operation! " << type << endl;
        system("pause");
    }
    operation.setUserID(LOGGED_USER_ID);
    if (type == INCOME) {
        Menus::showTitle("New Income");
    } else if (type == EXPENSE) {
        Menus::showTitle("New Expense");
    } else {
        cout << "There is no correct type for operation! " << type << endl;
        system("pause");
    }
    Menus::showNewOperationMenu();
    choice = Utils::getCharacter();
    switch(choice) {
    case '1':
        operation.setDate(dateMethods.getTodayDate());
        cout << "Today date is: " << dateMethods.presentDateInFormat(operation.getDate()) << endl;
        break;
    case '2':
        cout << "Enter date in format YYYY-MM-DD: ";
        operation.setDate(dateMethods.getDate());
        break;
    default:
        cout << "\nCharacter not used. Please try again.\n" << endl;
        system("pause");
        break;
    }
    cout << "Enter item description: ";
    operation.setItem(Utils::getLine());
    cout << "Enter transaction amount: ";
    operation.setAmount(Utils::getDouble());
    return operation;
}

void BudgetManager::showBalace(int startDate, int endDate) {
    double incomesBalance = 0;
    double expensesBalance = 0;

    if(startDate < endDate) {

        system("cls");
        Menus::showTitle("BALANCE");
        cout << "FROM " << dateMethods.presentDateInFormat(startDate) << " TO " << dateMethods.presentDateInFormat(endDate) << endl;

        if (incomes.empty()) {
            cout << "There is no incomes." << endl;
        } else {
            cout << endl << "-------INCOMES---------";
            sort(begin(incomes), std::end(incomes), [](Operation& left, Operation& right) {
                return left.getDate() > right.getDate();
            });
            for(unsigned int i = 0; i < incomes.size(); i++) {
                if(incomes[i].getDate() >= startDate && incomes[i].getDate() <= endDate) {
                    cout << endl << "Income ID: " << incomes[i].getID() << " Date: " << dateMethods.presentDateInFormat(incomes[i].getDate())
                         << " Amount: " << incomes[i].getAmount() << " Item: " << incomes[i].getItem();
                    incomesBalance += incomes[i].getAmount();
                }
            }
            cout << endl << endl << "Balance: " << incomesBalance << endl;
            cout << "-----------------------" << endl;
        }
        if (expenses.empty()) {
            cout << "There is no expenses." << endl;
        } else {
            cout << endl << "-------EXPENSES--------";
            sort(begin(expenses), std::end(expenses), [](Operation& left, Operation& right) {
                return left.getDate() > right.getDate();
            });
            for(unsigned int i = 0; i < expenses.size(); i++) {
                if(expenses[i].getDate() >= startDate && expenses[i].getDate() <= endDate) {
                    cout << endl << "Income ID: " << expenses[i].getID() << " Date: " << dateMethods.presentDateInFormat(expenses[i].getDate())
                         << " Amount: " << expenses[i].getAmount() << " Item: " << expenses[i].getItem();
                    expensesBalance += expenses[i].getAmount();
                }
            }
            cout << endl << endl << "Balance: " << expensesBalance << endl;
            cout << "-----------------------" << endl;
        }
        cout << "Total balance: " << incomesBalance - expensesBalance << endl;
        cout << "-----------------------" << endl;
    } else {
        cout << "The dates are incorrect." << endl;
    }
    system("pause");
}

void BudgetManager::showCurrentMonthBalance() {
    showBalace(dateMethods.getCurrentMonthFirstDayDate(), dateMethods.getTodayDate());
}

void BudgetManager::showPreviousMonthBalance() {
    showBalace(dateMethods.getPreviuseMonthFirstDayDate(), dateMethods.getPreviuseMonthLastDayDate());
}

void BudgetManager::showCustomPeriodBalance() {
    int dateStart = 0;
    int dateEnd = 0;

    cout << "Enter start date in format YYYY-MM-DD: ";
    dateStart = (dateMethods.getDate());
    cout << "Enter end date in format YYYY-MM-DD: ";
    dateEnd = (dateMethods.getDate());

    showBalace(dateStart, dateEnd);
}
