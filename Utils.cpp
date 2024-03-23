#include "Utils.h"

char Utils::getCharacter() {
    cin.sync();
    string input = "";
    char character  = {0};
    while (true) {
        getline(cin, input);
        if (input.length() == 1) {
            character = input[0];
            break;
        }
        cout << "It is not a single character." << endl;
    }
    return character;
}
