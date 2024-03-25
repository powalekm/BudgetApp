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

string Utils::getLine() {
    string input = "";
    cin.sync();
    while( input == "") {
        getline(cin, input);
        if(input == "") {
            cout << "The input can't be empty, try again: ";
        }
    }
    return input;
}

bool Utils::stringComparision(string firstString, string secondString) {
    if(firstString.length() == secondString.length()) {
        transform(firstString.begin(), firstString.end(), firstString.begin(), ::tolower);
        transform(secondString.begin(), secondString.end(), secondString.begin(), ::tolower);
        if (firstString == secondString) {
            return true;
        }
    }
    return false;
}
