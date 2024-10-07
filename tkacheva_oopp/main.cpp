#include <iostream>
#include <vector>
#include <windows.h>

#include "tkacheva_student.h"
#include "header.h"
#include "tkacheva_group.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    tkacheva_group students_group;
    while (true)
    {
        printmenu();
        int choice;
        cout << "Выберите действие: ";
        getcorrectnumber(choice);
        switch (choice)
        {
        case 1:
            students_group.add_student();
            break;
        case 2:
            students_group.add_headman();
            break;
        case 3:
            students_group.view_students();
            break;
        case 4:
            students_group.delete_students();
            cout << "Данные о студентах были удалены." << endl;
            break;
        case 5:
            students_group.save_data();
            break;
        case 6:
            students_group.load_data();
            break;
        case 0:
            return 0;
            break;
        default:
            cout << "Некорректный ввод! Повторите попытку." << endl;
            break;
        }
    }
}