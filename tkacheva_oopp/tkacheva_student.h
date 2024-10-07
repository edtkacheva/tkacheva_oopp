#pragma once
#include <iostream>
#include "boost.h"

using namespace std;

class tkacheva_student
{
private:
    friend class boost::serialization::access;
protected:
    string name = "";
    string last_name = "";
    int age = 0;
public:
    virtual void create(istream& in);
    virtual void show(ostream& out);
    tkacheva_student() {}
    virtual ~tkacheva_student() {}
    template <class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& name;
        ar& last_name;
        ar& age;
    }
};