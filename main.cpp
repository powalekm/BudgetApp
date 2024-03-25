#include <iostream>
#include "BudgetMainApp.h"
#include "Menus.h"
#include "Utils.h"
#include "UserManager.h"

using namespace std;

int main() {

    BudgetMainApp budgetMainApp("Users.xml", "Incomes.xml", "Expenses.xml");
    char choice;


    while(true) {
        if(!budgetMainApp.isUserLoggedIn()) {

            Menus::showTitle("HOME MENU");
            Menus::showHomeMenu();

            choice = Utils::getCharacter();

            switch(choice) {
            case '1':
                budgetMainApp.loginUser();
                break;
            case '2':
                budgetMainApp.registerUser();
                break;
            case '3':
                budgetMainApp.listAllUsers();
                break;
            case '9':
                cout << "\nSee you next time.\n";
                exit(0);
                break;
            default:
                cout << "\nCharacter not used. Please try again.\n" << endl;
                system("pause");
                break;
            }
        } else {
            Menus::showTitle("MAIN MENU");
            Menus::showMainMenu();

            choice = Utils::getCharacter();
            switch(choice) {
            case '6':
                budgetMainApp.changePassword();
                break;
            case '9':
                cout << "\nSee you next time.\n";
                budgetMainApp.logout();
                system("pause");
                break;
            default:
                cout << "\nCharacter not used. Please try again.\n" << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}
