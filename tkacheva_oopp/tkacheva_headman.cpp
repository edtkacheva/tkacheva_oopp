#include "tkacheva_headman.h"

void tkacheva_headman::show(ostream& out) {
    tkacheva_student::show(cout);
    out << "�������� ������: " << group_name << endl
        << "����� ��������: " << email << endl;
}

void tkacheva_headman::create(istream& in) {
    tkacheva_student::create(cin);
    cin.ignore();
    cout << "������� �������� ������: ";
    getline(in, group_name);
    cout << "������� ����� ��������: ";
    getline(in, email);
}