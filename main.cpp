/////////////////////
// Matthew Barham
// 2022-04-05
///////////////////////////////////////////////////////////////////
// Clock Conversion
//
// Takes input of 24-hour time format and converts to 12-hour format.
//
// Handles edge cases of hour and minute out of range, but letters
// will break the program.
///////////////////////////////////////////////////////////////////


#include <iostream>
#include <limits>

std::pair<int, int> GetTime();

void ConvertTime(std::pair<int, int> &, char &);

void Output(std::pair<int, int> &, char &);

int main() {
    char am_pm{'a'};

    std::pair<int, int> time{GetTime()};
    ConvertTime(time, am_pm);
    Output(time, am_pm);

    return 0;
}

/**
 * Asks the user for a time in 24-hour format.
 * @return A pair of the hour and minute
 */
std::pair<int, int> GetTime() {
    bool valid_time{false};
    int hour;
    int minutes;
    while (!valid_time) {
        std::cout << "Please enter the time (e.g. 16:32): ";

        char c;
        std::cin >> hour >> c >> minutes;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (hour < 0 || hour > 24) {
            std::cout << "You entered an invalid hour." << std::endl;
            continue;
        }
        if (minutes < 0 || minutes > 59 || (minutes > 0 && hour == 24)) {
            std::cout << "You entered an invalid minutes." << std::endl;
            continue;
        }
        valid_time = true;
    }

    return std::make_pair(hour, minutes);
}

/**
 * Converts time from 24-hour format to 12-hour format.
 * @param InTime A pair consisting of hour and minutes
 * @param am_pm A char storing the AM or PM value
 */
void ConvertTime(std::pair<int, int> &InTime, char &am_pm) {
    int hour{InTime.first};
    if (hour >= 12) {
        am_pm = 'p';
        InTime.first -= 12;
    } else {
        am_pm = 'a';
    }
}

/**
 * Outputs the provided time.
 * @param InTime
 * @param am_pm
 */
void Output(std::pair<int, int> &InTime, char &am_pm) {
    std::cout << "Your converted time is " << InTime.first << ":" << InTime.second << am_pm
              << std::endl;
}
