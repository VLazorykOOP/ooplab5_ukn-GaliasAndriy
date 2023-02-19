#include <iostream>

#include "Lab5Exmaple.h"
#include "Task1.h"
#include "Task2.h"
#include "Task3.h"

int main()
{
    cout << " Lab #5  !\n";

    char flag = '5';
    do {
        cout << "  Main menu for choosing a task." << endl;
        cout << "  1. Class Liquid and derived class Alcohol" << endl;
        cout << "  2. Classes Wheel, Bike and Car" << endl;
        cout << "  3. Classes Lecturer and People" << endl;
        cout << "  4. Quit" << endl;

        cout << "\n  Your choice: ";
        flag = cin.get();
        cin.get();

        switch (flag) {
        case '1': mainTask1(); break;
        case '2': mainTask2(); break;
        case '3': mainTask3(); break;
        case '4': return 0;
        }
        flag = cin.get();
    } while (flag != '5');
    return 0;
}



