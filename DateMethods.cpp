#include "DateMethods.h"

bool DateMethods::isDateInputCorrect(string date) {
    if(date.length() == 10) {
        for(unsigned int i = 0; i < date.length(); i++) {
            if( !isdigit(date[i]) && i < 4 ) {
                return false;
            } else if( !isdigit(date[i]) && i > 4 && i < 7 ) {
                return false;
            } else if( !isdigit(date[i]) && i > 7 ) {
                return false;
            } else if( i == 4 || i == 7 ) {
                if (date[i] != '-') {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

int DateMethods::getDate() {
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);
    bool dateCorrect = false;
    string input, dateYear, dateMonth, dateDay = "";
    cin.sync();
    int year, month, day = 0;
    do {
        getline(cin, input);
        if( isDateInputCorrect(input) ) {
            dateYear = "";
            dateMonth = "";
            dateDay = "";
            for(unsigned int i = 0; i < input.length(); i++) {
                if( i < 4 ) {
                    dateYear += input[i];
                } else if(i > 4 && i < 7 ) {
                    dateMonth += input[i];
                } else if( i > 7 ) {
                    dateDay += input[i];
                }
            }
            year = stoi(dateYear);
            month = stoi(dateMonth);
            day = stoi(dateDay);

            if( year > 1900 && year <= (aTime->tm_year + 1900) ) {
                if( month > 0 && month <= 12 ) {
                    if( day > 0 && day <= daysInMonth(year, month) ) {
                        dateCorrect = true;
                    } else {
                        cout << "This day is not in calendar: " << day << endl;
                        system("pause");
                    }
                } else {
                    cout << "This is not correct month (1-12): " << month << endl;
                    system("pause");
                }
            } else {
                cout << "The year must be in period from 1900 to " << (aTime->tm_year + 1900) << endl;
                system("pause");
            }
        } else {
            cout << "The format is not correct. Please try again." << endl;
        }
    } while (!dateCorrect);
    return stoi( dateYear + dateMonth + dateDay );
}

int DateMethods::getTodayDate() {
    int todayDay, todayMonth, todayYear;
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);
    todayYear = aTime->tm_year + 1900;
    todayMonth = aTime->tm_mon + 1;
    todayDay = aTime->tm_mday;

    return (todayYear * 10000 + todayMonth * 100 + todayDay);
}

bool DateMethods::isYearLeap(int year) {
    if ( year % 400 == 0) {
        return true;
    } else if( year % 100 == 0) {
        return false;
    } else if (year % 4 == 0) {
        return true;
    }
    return false;
}

int DateMethods::daysInMonth(int year, int month) {
    int numberOfDaysInMonth = 0;

    if(month ==  1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        numberOfDaysInMonth = 31;
    } else if(month == 4 || month == 6 || month == 9|| month == 11) {
        numberOfDaysInMonth = 30;
    } else if(month == 2 ) {
        if (isYearLeap(year)) {
            numberOfDaysInMonth = 29;
        } else {
            numberOfDaysInMonth = 28;
        }
    }
    return numberOfDaysInMonth;
}

int DateMethods::getCurrentMonthFirstDayDate() {
    int day, month, year;
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);
    year = aTime->tm_year + 1900;
    month = aTime->tm_mon + 1;
    day = 1;
    return (year * 10000 + month * 100 + day);
}

int DateMethods::getPreviuseMonthFirstDayDate() {
    int day, month, year;
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);
    year = aTime->tm_year + 1900;
    month = aTime->tm_mon + 1;
    day = 1;
    if(month == 1) {
        year--;
        month = 12;
    } else {
        month--;
    }
    return (year * 10000 + month * 100 + day);
}

int DateMethods::getPreviuseMonthLastDayDate() {
    int month, year;
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);
    year = aTime->tm_year + 1900;
    month = aTime->tm_mon + 1;
    if(month == 1) {
        year--;
        month = 12;
    } else {
        month--;
    }
    return (year * 10000 + month * 100 + daysInMonth(year, month));
}

string DateMethods::presentDateInFormat(int number) {
    string date = to_string(number);
    string year = "";
    string month = "";
    string day = "";
    for(unsigned int i = 0; i < date.length(); i++) {
        if( i < 4 ) {
            year += date[i];
        } else if(i >= 4 && i < 6 ) {
            month += date[i];
        } else if( i >= 6 ) {
            day += date[i];
        }
    }
    return (year + '-' + month + '-' + day);
}
