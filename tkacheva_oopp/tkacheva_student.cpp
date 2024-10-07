#include "tkacheva_student.h"
#include "header.h"
#include "boost.h"

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

BOOST_CLASS_IMPLEMENTATION(tkacheva_student, boost::serialization::level_type::object_serializable)

void tkacheva_student::create(istream& in)
{
    cout << "Введите имя студента: ";
    in >> ws;
    getline(in, name);
    cout << "Введите фамилию студента: ";
    in >> ws;
    getline(in, last_name);
    cout << "Введите возраст студента: ";
    getcorrectnumber(age);
    while (age <= 0) {
        cout << "Некорректный ввод! Повторите попытку." << endl;
        getcorrectnumber(age);
    }
}

void tkacheva_student::show(ostream& out)
{
    out << "Студент:" << endl;
    out << "Имя студента: " << name << endl
        << "Фамилия студента: " << last_name << endl
        << "Возраст студента: " << age << endl;
}