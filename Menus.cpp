#include "Menus.h"

void Menus::showTitle(string title) {
    system("cls");
    cout << "-------" << title << "-------" << endl;
}

void Menus::showHomeMenu() {
    cout << "-----------------------" << endl;
    cout << "1. Login" << endl;
    cout << "2. Registration" << endl;
    cout << "9. Quit" << endl;
    cout << "-----------------------" << endl;
    cout << "Your choice: ";
}

void Menus::showMainMenu() {
    cout << "-----------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Balance for current month" << endl;
    cout << "4. Balance for previous month" << endl;
    cout << "5. Balance for selected period" << endl;
    cout << "6. Change password" << endl;
    cout << "8. Logout" << endl;
    cout << "9. Quit" << endl;
    cout << "-----------------------" << endl;
    cout << "Your choice: ";
}

void Menus::showNewOperationMenu() {
    cout << "-----------------------" << endl;
    cout << "1. Input the operation for today's date" << endl;
    cout << "2. Enter a different date" << endl;
    cout << "-----------------------" << endl;
    cout << "Your choice: ";
