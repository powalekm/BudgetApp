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

double Utils::getDouble() {
    string input = "";
    string doubleOutput = "";
    bool isInputCorrect = true;
    int numberOfSeperators = 0;
    do {
        cin.sync();
        getline(cin, input);
        isInputCorrect = true;
        numberOfSeperators = 0;
        for(unsigned int i = 0; i < input.length(); i++) {
            if( i == 0 && !isdigit(input[i])) {
                cout << "The input is not a digit" << endl;
                isInputCorrect = false;
                break;
            } else if( isdigit(input[i]) ) {
                doubleOutput += input[i];
            } else if (input[i] == '.' || input[i] == ',') {
                doubleOutput += '.';
                numberOfSeperators++;
                if (numberOfSeperators > 1) {
                    cout << "The input is in wrong format" << endl;
                    isInputCorrect = false;
                    break;
                }
            } else {
                cout << "The input is in wrong format" << endl;
                isInputCorrect = false;
                break;
            }
        }
    } while (!isInputCorrect);
    return stof(doubleOutput);
}
