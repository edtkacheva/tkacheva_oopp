#include "tkacheva_headman.h"

void tkacheva_headman::show(ostream& out) {
    tkacheva_student::show(cout);
    out << "Название группы: " << group_name << endl
        << "Почта старосты: " << email << endl;
}

void tkacheva_headman::create(istream& in) {
    tkacheva_student::create(cin);
    cin.ignore();
    cout << "Введите название группы: ";
    getline(in, group_name);
    cout << "Введите почту старосты: ";
    getline(in, email);
}