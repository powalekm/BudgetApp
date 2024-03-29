#include "BudgetManager.h"

void BudgetManager::addIncome(){

    Operation operation = setNewOperation();

    incomes.push_back(operation);
    incomesFile.addOperationToFile(operation);
    cout << endl << "New income has been created." << endl << endl;
    system("pause");
    system("cls");
}

void BudgetManager::addExpense(){
}

Operation BudgetManager::setNewOperation() {
    Operation operation;

    operation.setID(incomesFile.getLastOperationID() + 1);
    operation.setUserID(LOGGED_USER_ID);

    Menus::showTitle("New Expense");
    Menus::showNewOperationMenu();

    choice = Utils::getCharacter();
    switch(choice){
        case '1':
            operation.setDate(dateMethods.getTodayDate());
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
    cout << "Enter date in format YYYY-MM-DD: ";
    operation.setDate(dateMethods.getDate());
    cout << "Enter item description: ";
    operation.setItem(Utils::getLine());
    cout << "Enter transaction amount: ";
    operation.setAmount(Utils::getDouble());
    return operation;
}

void BudgetManager::showCurrentMonthBalance(){
 if (incomes.empty()) {
        cout << "There is no incomes in the file." << endl;
    } else {
        Menus::showTitle("CURRENT MONTH BALANCE");
        cout << "-----------------------";
        for(unsigned int i = 0; i <incomes .size(); i++) {
            cout << endl << "Income ID:     " << incomes[i].getID() << endl;
            cout << "Income Date:   " << incomes[i].getDate() << endl;
            cout << "Income Item:   " << incomes[i].getItem() << endl;
            cout << "Income Amount: " << incomes[i].getAmount() << endl;
            cout << "-----------------------";
        }
    }
    system("pause");
}
