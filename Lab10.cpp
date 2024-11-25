/****************************************************
* Автор: Алексеев Д.К.                              *
* Дата: 19.11.2024                                  *
* Название: Календарь года                          *
****************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getFirstDayOfYear(int year) {
    int day = (year + year / 4 - year / 100 + year / 400) % 7; 
    return day;
}

void printCalendar(int year) {
    vector<string> months = {
        "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь",
        "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"
    };
    vector<int> daysInMonth = {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };

    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }

    int dayOfWeek = getFirstDayOfYear(year);
    cout << "Календарь на " << year << " год:\n\n";

    for (int i = 0; i < 12; i++) {
        cout << "  " << months[i] << "\n";
        cout << "  Пн  Вт  Ср  Чт  Пт  Сб  Вс\n";

        for (int j = 0; j < dayOfWeek; j++) {
            cout << "    ";
        }

        for (int day = 1; day <= daysInMonth[i]; day++) {
            cout << (day < 10 ? "   " : "  ") << day;

            if (++dayOfWeek == 7) {
                dayOfWeek = 0;
                cout << "\n";
            }
        }
        cout << "\n\n";
    }
}

int main() {
    int year;
    cout << "Введите год: ";
    cin >> year;

    printCalendar(year);

    return 0;
}
