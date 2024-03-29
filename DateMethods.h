#ifndef DATEMETHODS_H
#define DATEMETHODS_H

#include <iostream>
#include <string>
#include <time.h>
#include <ctype.h>

using namespace std;

class DateMethods {

public:
    int getDate();
    int getTodayDate();
    bool isYearLeap(int year);
    bool isDateInputCorrect(string date);
    int daysInMonth(int year, int month, int day);
};
#endif
