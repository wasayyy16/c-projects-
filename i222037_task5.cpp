#include <iostream>
#include <string>
using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(const Date &date) {
    if (date.year < 0) return false;
    if (date.month < 1 || date.month > 12) return false;
    if (date.day < 1 || date.day > 31) return false;

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (isLeapYear(date.year)) {
        daysInMonth[2] = 29;
    }

    return date.day <= daysInMonth[date.month];
}

string getDayOfWeek(const Date &date) {
    static string daysOfWeek[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    int d = date.day;
    int m = date.month;
    int y = date.year;

    if (m < 3) {
        m += 12;
        y--;
    }

    int K = y % 100;
    int J = y / 100;

    int dayOfWeek = (d + (13 * (m + 1)) / 5 + K + (K / 4) + (J / 4) + 5 * J) % 7;

    return daysOfWeek[dayOfWeek];
}

int compareDates(const Date &date1, const Date &date2) {
    if (date1.year < date2.year) return -1;
    if (date1.year > date2.year) return 1;
    if (date1.month < date2.month) return -1;
    if (date1.month > date2.month) return 1;
    if (date1.day < date2.day) return -1;
    if (date1.day > date2.day) return 1;
    return 0;
}

int main() {
    Date date1, date2;

    cout << "Enter date 1 (dd mm yyyy): ";
    cin >> date1.day >> date1.month >> date1.year;

    cout << "Enter date 2 (dd mm yyyy): ";
    cin >> date2.day >> date2.month >> date2.year;

    if (isValidDate(date1) && isValidDate(date2)) {
        cout << "Date 1 is a valid date." << endl;
        cout << "Date 2 is a valid date." << endl;

        int comparison = compareDates(date1, date2);
        if (comparison < 0) {
            cout << "Date 1 is earlier than Date 2." << endl;
        } else if (comparison > 0) {
            cout << "Date 1 is later than Date 2." << endl;
        } else {
            cout << "Date 1 is the same as Date 2." << endl;
        }

        cout << "Day of the week for Date 1 is: " << getDayOfWeek(date1) << endl;
        cout << "Day of the week for Date 2 is: " << getDayOfWeek(date2) << endl;
    } else {
        cout << "One or both of the entered dates are not valid." << endl;
    }

    return 0;
}

