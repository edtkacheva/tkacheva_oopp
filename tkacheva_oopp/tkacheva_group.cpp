#include <iostream>
#include <string>
#include <locale>
#include <windows.h>
#include <fstream>
#include <vector>

#include "header.h"
#include "boost.h"
#include "tkacheva_student.h"
#include "tkacheva_group.h"

using namespace std;
BOOST_CLASS_EXPORT(tkacheva_headman)

using boost::archive::archive_flags;

void tkacheva_group::add_student()
{
    shared_ptr<tkacheva_student> s = make_shared<tkacheva_student>();
    s->tkacheva_student::create(cin);
    students.push_back(s);
}

void tkacheva_group::add_headman()
{
    shared_ptr<tkacheva_headman> headman = make_shared<tkacheva_headman>();
    headman->tkacheva_headman::create(cin);
    students.push_back(headman);
}

void tkacheva_group::view_students()
{
    if (students.empty())
    {
        cout << "Данных о студентах нет." << endl;
    }
    else
    {
        for (auto& s : students) {
            s->show(cout);
        }
    }
}

void tkacheva_group::delete_students()
{
    students.clear();
}

void tkacheva_group::save_data()
{
    if (students.empty())
    {
        cout << "Данных о студентах нет." << endl;
        return;
    }
    string filename;
    cout << "Введите название файла: ";
    cin.ignore();
    getline(cin, filename);
    ofstream fout;
    fout.open((filename), ios::trunc);
    if (fout.is_open())
    {
        boost::archive::text_oarchive write(fout, archive_flags::no_header);
        write << students;
        cout << "Данные были записаны в файл." << endl;
    }
    else
    {
        cout << "Неверное имя файла." << endl;
    }
    fout.close();
}

void tkacheva_group::load_data()
{
    int count = 0;
    ifstream fin;
    string filename;
    cout << "Введите название файла: ";
    cin.ignore();
    getline(cin, filename);
    fin.open((filename), ios::in);
    if (!fin.is_open())
    {
        cout << "Неверное название файла." << endl;
    }
    else
    {
        delete_students();
        if (!fin) {
            cout << "Невозможно считать данные из файла." << endl;
            fin.close();
            return;
        }
        else {
            boost::archive::text_iarchive load(fin, archive_flags::no_header);
            load >> students;
            view_students();
        }
        fin.close();
    }
}