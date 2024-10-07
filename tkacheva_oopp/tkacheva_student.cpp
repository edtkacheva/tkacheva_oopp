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
    cout << "������� ��� ��������: ";
    in >> ws;
    getline(in, name);
    cout << "������� ������� ��������: ";
    in >> ws;
    getline(in, last_name);
    cout << "������� ������� ��������: ";
    getcorrectnumber(age);
    while (age <= 0) {
        cout << "������������ ����! ��������� �������." << endl;
        getcorrectnumber(age);
    }
}

void tkacheva_student::show(ostream& out)
{
    out << "�������:" << endl;
    out << "��� ��������: " << name << endl
        << "������� ��������: " << last_name << endl
        << "������� ��������: " << age << endl;
}