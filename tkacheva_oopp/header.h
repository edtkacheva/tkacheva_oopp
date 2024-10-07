#pragma once
#include <iostream>

using namespace std;

template <typename T>
void getcorrectnumber(T& x) {
    cin >> x;
    while (cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Ошибка ввода! Повторите попытку." << endl;
        cin >> x;
    }
}

static void printmenu() {
    cout << "1. Добавить студента." << endl
        << "2. Добавить старосту." << endl
        << "3. Вывести всех студентов." << endl
        << "4. Удалить всех студентов." << endl
        << "5. Загрузить данные в файл." << endl
        << "6. Скачать данные из файла." << endl
        << "0. Выход." << endl
        << "----------------------------" << endl;
}